/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:40:37 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/11 17:54:05 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

//void	start_zoom_in(void *m, void *win)
//{
//	int			pt;
//	t_guimp		*g;
//	t_ui_win	*w;
//
//	g = (t_guimp *)(((t_ui_main *)m)->data);
//	w = (t_ui_win *)win;
//	pt = g->draw_tool.tool;
//	g->draw_tool.tool = GM_TOOL_ZOOM;
//	start_draw_with_selected_tool(m, ui_win_find_el_by_id(w, GM_MAIN_ID_DRAW));
//	g->draw_tool.tool = pt;
//}
//
//void	start_zoom_out(void *m, void *win)
//{
//	int			pt;
//	t_guimp		*g;
//	t_ui_win	*w;
//
//	g = (t_guimp *)(((t_ui_main *)m)->data);
//	w = (t_ui_win *)win;
//	pt = g->draw_tool.tool;
//	g->draw_tool.tool = GM_TOOL_ZOOM;
//	start_alt_with_selected_tool(m, ui_win_find_el_by_id(w, GM_MAIN_ID_DRAW));
//	g->draw_tool.tool = pt;
//}

void	choose_zoom(void *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	(void)el_v;
	g->draw_tool.tool = GM_TOOL_ZOOM;
}

void	tool_zoom_in(t_guimp *g, int x, int y)
{
	g->draw_tool.zoom++;
	g->zoom_rect.w = GM_IMAGE_SIZE_X / g->draw_tool.zoom;
	g->zoom_rect.h = GM_IMAGE_SIZE_Y / g->draw_tool.zoom;
	x = x - g->zoom_rect.w / 2;
	y = y - g->zoom_rect.h / 2;
	x = (x + g->zoom_rect.w > GM_IMAGE_SIZE_X) ? GM_IMAGE_SIZE_X - g->zoom_rect.w : x;
	y = (y + g->zoom_rect.h > GM_IMAGE_SIZE_Y) ? GM_IMAGE_SIZE_Y - g->zoom_rect.h : y;
	g->zoom_rect.x = x < 0 ? 0 : x;
	g->zoom_rect.y = y < 0 ? 0 : y;
}

void	tool_zoom_out(t_guimp *g, int x, int y)
{
	g->draw_tool.zoom--;
	g->zoom_rect.w = GM_IMAGE_SIZE_X / g->draw_tool.zoom;
	g->zoom_rect.h = GM_IMAGE_SIZE_Y / g->draw_tool.zoom;
	x = x - g->zoom_rect.w / 2;
	y = y - g->zoom_rect.h / 2;
	x = (x + g->zoom_rect.w > GM_IMAGE_SIZE_X) ? GM_IMAGE_SIZE_X - g->zoom_rect.w : x;
	y = (y + g->zoom_rect.h > GM_IMAGE_SIZE_Y) ? GM_IMAGE_SIZE_Y - g->zoom_rect.h : y;
	g->zoom_rect.x = x < 0 || g->draw_tool.zoom == 1 ? 0 : x;
	g->zoom_rect.y = y < 0 || g->draw_tool.zoom == 1 ? 0 : y;
}
