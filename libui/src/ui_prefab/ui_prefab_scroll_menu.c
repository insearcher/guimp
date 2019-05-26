/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_prefab_scroll_menu.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:21:24 by sbecker           #+#    #+#             */
/*   Updated: 2019/05/26 16:27:04 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_prefab_scroll_menu(t_ui_main *m, t_ui_el *canvas, t_ui_el *scroll_menu, t_scroll_m_pref *scroll_data)
{
	t_list	*list;
	t_ui_el	*cur_el;

	list = scroll_menu->children;
	while (list)
	{
		cur_el = (t_ui_el *)list->content;
		ui_el_set_pos(cur_el, canvas, scroll_data->type_pos, scroll_data->begin_pos);
		ui_el_set_size(cur_el, canvas, scroll_data->type_size, scroll_data->size);
		cur_el->params = scroll_data->params;
		cur_el->id = scroll_data->begin_id;
		cur_el->sdl_renderer = scroll_data->sdl_renderer;
		ui_el_add_texture_from_main_by_id(m, cur_el, scroll_data->texture, "default");
		++scroll_data->begin_id;
		scroll_data->begin_pos.y += scroll_data->size.y + scroll_data->indent;
		list = list->next;
		printf("P elID: %d, pos: (%d, %d)\n", cur_el->id, cur_el->rect.x, cur_el->rect.y);
		printf("P elID: %d, size: (%d, %d)\n", cur_el->id, cur_el->rect.w, cur_el->rect.h);
	}
//	free(scroll_data->texture);
}
