/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:49:03 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/13 07:20:54 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	choose_pipette(t_ui_main *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(main->data);
	(void)el_v;
	g->draw_tool.tool = GM_TOOL_PIPETTE;
}

void	tool_pipette(t_guimp *g, t_ui_el *el)
{
	int color = ui_util_get_pixel_color_from_el(el->sdl_renderer, el, (t_vec2){el->ptr_rel_pos.x, el->ptr_rel_pos.y});
	g->draw_tool.r = (color & 0xFF0000) >> 16;
	g->draw_tool.g = (color & 0x00FF00) >> 8;
	g->draw_tool.b = color & 0x0000FF;
	el = ui_win_find_el_by_id(g->tool_win, GM_TOOL_ID_SL_HEAD_RED);
	ui_el_set_new_pos(el, 0, PIXEL, (t_fvec2){-el->rect.w / 2 + g->draw_tool.r / 255.0f * el->parent->rect.w, 0});
	el = ui_win_find_el_by_id(g->tool_win, GM_TOOL_ID_SL_HEAD_GR);
	ui_el_set_new_pos(el, 0, PIXEL, (t_fvec2){-el->rect.w / 2 + g->draw_tool.g / 255.0f * el->parent->rect.w, 0});
	el = ui_win_find_el_by_id(g->tool_win, GM_TOOL_ID_SL_HEAD_BL);
	ui_el_set_new_pos(el, 0, PIXEL, (t_fvec2){-el->rect.w / 2 + g->draw_tool.b / 255.0f * el->parent->rect.w, 0});
	update_color_rect(g, g->draw_tool.r, g->draw_tool.g, g->draw_tool.b);
}
