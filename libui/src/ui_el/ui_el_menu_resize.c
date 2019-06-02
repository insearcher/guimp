/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_resize_menu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 14:45:05 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/02 15:29:20 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

typedef struct	s_resize_data
{
	t_fvec2	elem_pos;
	t_fvec2	elem_size;
	t_fvec2	indent;
}				t_resize_data;

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
	child = (t_ui_el *)el->children->next->content;
	new_pos2.x = el->rect.x + (float)el->rect.w * child->relative_rect.x;
	new_pos2.y = el->rect.y + (float)el->rect.h * child->relative_rect.y;
	data->indent.x = roundf(new_pos2.x - new_pos1.x - new_size.x);
	data->indent.y = roundf(new_pos2.y - new_pos1.y - new_size.y);
	data->elem_pos = ft_fvec2_round(new_pos1);
	data->elem_size = ft_fvec2_round(new_size);
	data->elem_pos.x = data->elem_pos.x - (float)el->rect.x;
	data->elem_pos.y = data->elem_pos.y - (float)el->rect.y;
}

void	ui_el_menu_resize(void *a1, void *a2)
{
	t_resize_data	data;
	t_list			*list;
	t_ui_el			*el;
	t_ui_el			*cur_el;

	ui_el_default_resize(a1, a2);
	el = (t_ui_el *)a1;
	get_new_pos_size_indent(el, &data);
	list = el->children;
	while (list)
	{
		cur_el = (t_ui_el *)list->content;
		ui_el_change_pos_for_resize(cur_el, 0, POS_PIXEL, data.elem_pos);
		ui_el_change_size_for_resize(cur_el, 0, SIZE_PIXEL, data.elem_size);
		data.elem_pos.y += data.elem_size.y + data.indent.y;
		list = list->next;
	}
}
