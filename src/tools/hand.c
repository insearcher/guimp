/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:45:54 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/10 15:45:54 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	choose_hand(void *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	(void)el_v;
	g->draw_tool.tool = GM_TOOL_HAND;
}

void	tool_hand(t_guimp *g)
{
	g->zoom_rect.x += (abs(g->draw_tool.prew_point.x - g->draw_tool.cur_point.x) >= GM_HAND_MIN_DIST ? g->draw_tool.prew_point.x - g->draw_tool.cur_point.x : 0) * GM_HAND_MOVE_SPEED;
	g->zoom_rect.y += (abs(g->draw_tool.prew_point.y - g->draw_tool.cur_point.y) >= GM_HAND_MIN_DIST ? g->draw_tool.prew_point.y - g->draw_tool.cur_point.y : 0) * GM_HAND_MOVE_SPEED;
	g->zoom_rect.x = g->zoom_rect.x < 0 ? 0 : g->zoom_rect.x;
	g->zoom_rect.x = g->zoom_rect.x + g->zoom_rect.w > GM_IMAGE_SIZE_X ? GM_IMAGE_SIZE_X - g->zoom_rect.w : g->zoom_rect.x;
	g->zoom_rect.y = g->zoom_rect.y < 0 ? 0 : g->zoom_rect.y;
	g->zoom_rect.y = g->zoom_rect.y + g->zoom_rect.h > GM_IMAGE_SIZE_Y ? GM_IMAGE_SIZE_Y - g->zoom_rect.h : g->zoom_rect.y;
}