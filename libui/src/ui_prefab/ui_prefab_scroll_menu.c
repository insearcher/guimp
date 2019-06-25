/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_prefab_scroll_menu.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:21:24 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/24 21:25:33 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_prefab_scroll_menu(t_ui_main *m, t_ui_el *canvas, t_ui_el *scroll_menu, t_scroll_m_pref *scroll_data)
{
	t_list	*list;
	t_ui_el	*cur_el;

	ui_prefab_get_pixel_pos(scroll_menu, canvas, scroll_data->type_pos, &scroll_data->begin_pos);
	ui_prefab_get_pixel_size(scroll_menu, canvas, scroll_data->type_size, &scroll_data->size);
	ui_prefab_get_pixel_size(scroll_menu, canvas, scroll_data->type_indent, &scroll_data->indent);
	list = scroll_menu->children;
	while (list)
	{
		cur_el = (t_ui_el *)list->content;
		ui_el_set_pos(cur_el, PIXEL | ABS, scroll_data->begin_pos);
		ui_el_set_size(cur_el, PIXEL, scroll_data->size);
		cur_el->params |= scroll_data->params;
		cur_el->id = scroll_data->begin_id;
		cur_el->sdl_renderer = scroll_data->sdl_renderer;
		ui_el_add_texture_from_main_by_id(m, cur_el, scroll_data->texture, "default");
		++scroll_data->begin_id;
		scroll_data->begin_pos.y += scroll_data->size.y + scroll_data->indent.y;
		list = list->next;
	}
}
