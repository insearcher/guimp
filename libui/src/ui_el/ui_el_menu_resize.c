/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_resize_menu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 14:45:05 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/05 04:52:08 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void	ui_el_set_new_pos_for_resize(t_ui_el *el, t_fvec2 v)
{
	el->rect.x = roundf(v.x + (float)el->parent->rect.x);
	el->rect.y = roundf(v.y + (float)el->parent->rect.y);
	el->cut_rect.x = el->rect.x;
	el->cut_rect.y = el->rect.y;
	bfs_iter(el->children, ui_el_set_new_pos_for_children, 0);
}

static void	ui_el_set_new_size_for_resize(t_ui_el *el, t_fvec2 v)
{
	el->rect.w = roundf(v.x);
	el->rect.h = roundf(v.y);
	el->cut_rect.w = el->rect.w;
	el->cut_rect.h = el->rect.h;
	bfs_iter(el->children, ui_el_set_new_size_for_children, 0);
}

static void	get_new_pos_size_indent(t_ui_el *el, t_resize_data *data)
{
	t_fvec2	new_pos1;
	t_fvec2	new_pos2;
	t_fvec2	new_size;
	t_ui_el	*child;

	child = (t_ui_el *)el->children->content;
	new_size.x = (float)el->rect.w * child->relative_rect.w;
	new_size.y = (float)el->rect.h * child->relative_rect.h;
	new_pos1.x = (float)el->rect.x + (float)el->rect.w * child->relative_rect.x;
	new_pos1.y = (float)el->rect.y + (float)el->rect.h * child->relative_rect.y;
	if ((t_ui_el *)el->children->next)
	{
		child = (t_ui_el *)el->children->next->content;
		new_pos2.x = (float)el->rect.x + (float)el->rect.w * child->relative_rect.x;
		new_pos2.y = (float)el->rect.y + (float)el->rect.h * child->relative_rect.y;
		data->indent.x = roundf(new_pos2.x - new_pos1.x - new_size.x);
		data->indent.y = roundf(new_pos2.y - new_pos1.y - new_size.y);
	}
	data->elem_pos = ft_fvec2_round(new_pos1);
	data->elem_size = ft_fvec2_round(new_size);
	data->elem_pos.x = data->elem_pos.x - (float)el->rect.x;
	data->elem_pos.y = data->elem_pos.y - (float)el->rect.y;
}

void		ui_el_menu_resize(void *a1, void *a2)
{
	t_resize_data	data;
	t_list			*list;
	t_ui_el			*el;
	t_ui_el			*cur_el;

	ui_el_default_resize(a1, a2);
	el = (t_ui_el *)a1;
	if (el && el->children)
	{
		get_new_pos_size_indent(el, &data);
		list = el->children;
		while (list)
		{
			cur_el = (t_ui_el *)list->content;
			ui_el_set_new_pos_for_resize(cur_el, data.elem_pos);
			ui_el_set_new_size_for_resize(cur_el, data.elem_size);
			data.elem_pos.y += data.elem_size.y + data.indent.y;
			list = list->next;
		}
	}
}
