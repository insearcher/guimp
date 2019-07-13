/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_event_menu_resize.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:04:13 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 09:13:56 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void	ui_el_set_new_pos_for_resize(t_ui_el *el, t_fvec2 v)
{
	el->rect.x = roundf(v.x + (float)el->parent->rect.x);
	el->rect.y = roundf(v.y + (float)el->parent->rect.y);
	el->cut_rect.x = el->rect.x;
	el->cut_rect.y = el->rect.y;
}

static void	ui_el_set_new_size_for_resize(t_ui_el *el, t_fvec2 v)
{
	el->rect.w = roundf(v.x);
	el->rect.h = roundf(v.y);
	el->cut_rect.w = el->rect.w;
	el->cut_rect.h = el->rect.h;
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

int			ui_el_event_menu_resize(t_ui_main *m, void *a)
{
	t_resize_data	data;
	t_list			*list;
	t_ui_el			*el;
	t_ui_el			*cur_el;

	ui_el_event_default_resize(m, a);
	el = (t_ui_el *)a;
	if (el && el->children)
	{
		get_new_pos_size_indent(el, &data);
		list = el->children;
		while (list)
		{
			cur_el = (t_ui_el *)list->content;
			ui_el_set_new_pos_for_resize(cur_el, data.elem_pos);
			ui_el_set_new_size_for_resize(cur_el, data.elem_size);
			bfs_iter(cur_el->children, ui_el_set_new_pos_for_children, 0);
			bfs_iter(cur_el->children, ui_el_set_new_size_for_children, 0);
			data.elem_pos.y += data.elem_size.y + data.indent.y;
			list = list->next;
		}
	}
	return (1);
}
