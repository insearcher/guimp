/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_tmp_layer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:09:45 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/12 18:09:09 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"


static void	process_tool_state_draw(t_guimp *g)
{
	SDL_SetRenderDrawColor(g->main_win->sdl_renderer, g->draw_tool.r, g->draw_tool.g, g->draw_tool.b, 255);
	if (g->draw_tool.tool == GM_TOOL_RECT)
		(g->draw_tool.tool_mode == GM_TOOL_MODE_FILL ?
		 draw_rect(g, (t_vec2){g->draw_tool.prew_point.x, g->draw_tool.prew_point.y}, (t_vec2){g->draw_tool.cur_point.x, g->draw_tool.cur_point.y}) :
		 draw_empty_rect(g, (t_vec2){g->draw_tool.prew_point.x, g->draw_tool.prew_point.y}, (t_vec2){g->draw_tool.cur_point.x, g->draw_tool.cur_point.y}));
	else if (g->draw_tool.tool == GM_TOOL_SQUARE)
		(g->draw_tool.tool_mode == GM_TOOL_MODE_FILL ?
		 draw_rect(g, (t_vec2){g->draw_tool.prew_point.x, g->draw_tool.prew_point.y}, (t_vec2){g->draw_tool.cur_point.x, g->draw_tool.prew_point.y + abs(g->draw_tool.prew_point.x - g->draw_tool.cur_point.x)}) :
		 draw_empty_rect(g, (t_vec2){g->draw_tool.prew_point.x, g->draw_tool.prew_point.y}, (t_vec2){g->draw_tool.cur_point.x, g->draw_tool.prew_point.y + abs(g->draw_tool.prew_point.x - g->draw_tool.cur_point.x)}));
	else if (g->draw_tool.tool == GM_TOOL_ELLIPSE)
		(g->draw_tool.tool_mode == GM_TOOL_MODE_FILL ?
		 draw_ellipse(g, (t_vec2){g->draw_tool.prew_point.x, g->draw_tool.prew_point.y}, (t_vec2){g->draw_tool.cur_point.x, g->draw_tool.cur_point.y}) :
		 draw_empty_ellipse(g, (t_vec2){g->draw_tool.prew_point.x, g->draw_tool.prew_point.y}, (t_vec2){g->draw_tool.cur_point.x, g->draw_tool.cur_point.y}));
	else if (g->draw_tool.tool == GM_TOOL_LINE)
		draw_line(g, (t_vec2){g->draw_tool.prew_point.x, g->draw_tool.prew_point.y},
					  (t_vec2){g->draw_tool.cur_point.x, g->draw_tool.cur_point.y});
	else if (g->draw_tool.tool == GM_TOOL_TEXT)
		draw_text(g, (t_vec2){g->draw_tool.prew_point.x, g->draw_tool.prew_point.y},
					  (t_vec2){g->draw_tool.cur_point.x, g->draw_tool.cur_point.y},
					  ui_win_find_el_by_id(g->tool_win, 120610));
}

static void	process_tool_state_end(t_guimp *g)
{
	SDL_SetRenderDrawColor(g->main_win->sdl_renderer, g->draw_tool.r, g->draw_tool.g, g->draw_tool.b, 255);
	if (g->draw_tool.tool == GM_TOOL_RECT)
		(g->draw_tool.tool_mode == GM_TOOL_MODE_FILL ?
		 draw_rect(g, (t_vec2){g->draw_tool.prew_point.x, g->draw_tool.prew_point.y}, (t_vec2){g->draw_tool.cur_point.x, g->draw_tool.cur_point.y}) :
		 draw_empty_rect(g, (t_vec2){g->draw_tool.prew_point.x, g->draw_tool.prew_point.y}, (t_vec2){g->draw_tool.cur_point.x, g->draw_tool.cur_point.y}));
	else if (g->draw_tool.tool == GM_TOOL_SQUARE)
		(g->draw_tool.tool_mode == GM_TOOL_MODE_FILL ?
		 draw_rect(g, (t_vec2){g->draw_tool.prew_point.x, g->draw_tool.prew_point.y}, (t_vec2){g->draw_tool.cur_point.x, g->draw_tool.prew_point.y + abs(g->draw_tool.prew_point.x - g->draw_tool.cur_point.x)}) :
		 draw_empty_rect(g, (t_vec2){g->draw_tool.prew_point.x, g->draw_tool.prew_point.y}, (t_vec2){g->draw_tool.cur_point.x, g->draw_tool.prew_point.y + abs(g->draw_tool.prew_point.x - g->draw_tool.cur_point.x)}));
	else if (g->draw_tool.tool == GM_TOOL_ELLIPSE)
		(g->draw_tool.tool_mode == GM_TOOL_MODE_FILL ?
		 draw_ellipse(g, (t_vec2){g->draw_tool.prew_point.x, g->draw_tool.prew_point.y}, (t_vec2){g->draw_tool.cur_point.x, g->draw_tool.cur_point.y}) :
		 draw_empty_ellipse(g, (t_vec2){g->draw_tool.prew_point.x, g->draw_tool.prew_point.y}, (t_vec2){g->draw_tool.cur_point.x, g->draw_tool.cur_point.y}));
	else if (g->draw_tool.tool == GM_TOOL_LINE)
		draw_line(g, (t_vec2){g->draw_tool.prew_point.x, g->draw_tool.prew_point.y},
					  (t_vec2){g->draw_tool.cur_point.x, g->draw_tool.cur_point.y});
	else if (g->draw_tool.tool == GM_TOOL_TEXT)
		draw_text(g, (t_vec2){g->draw_tool.prew_point.x, g->draw_tool.prew_point.y},
					  (t_vec2){g->draw_tool.cur_point.x, g->draw_tool.cur_point.y},
					  ui_win_find_el_by_id(g->tool_win, 120610));
	g->draw_tool.state = GM_TOOL_STATE_NONE;
	SDL_SetRenderTarget(g->main_win->sdl_renderer, (t_texture *)(g->layers.current_layer->sdl_textures->content));
	SDL_RenderCopy(g->main_win->sdl_renderer, g->layers.tmp_texture, NULL, NULL);
}

void	process_tmp_layer(t_guimp *g)
{
	SDL_SetRenderTarget(g->main_win->sdl_renderer, g->layers.tmp_texture);
	SDL_SetRenderDrawColor(g->main_win->sdl_renderer, 0, 0, 0, 0);
	SDL_RenderClear(g->main_win->sdl_renderer);
	if (g->draw_tool.state == GM_TOOL_STATE_DRAW)
		process_tool_state_draw(g);
	if (g->draw_tool.state == GM_TOOL_STATE_END)
		process_tool_state_end(g);
	SDL_SetRenderTarget(g->main_win->sdl_renderer, NULL);
}
