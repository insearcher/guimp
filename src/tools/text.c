/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:49:44 by edraugr-          #+#    #+#             */
/*   Updated: 2019/07/13 13:59:09 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

int	choose_text(t_ui_main *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(main->data);
	(void)el_v;
	g->draw_tool.tool = GM_TOOL_TEXT;
	g->draw_tool.state = GM_TOOL_STATE_NONE;
	return (1);
}

void	draw_text(t_guimp *g, t_vec2 s, t_vec2 e, t_ui_el *el)
{
	t_texture	*t;

	t = SDL_CreateTextureFromSurface(g->main_win->sdl_renderer, el->sdl_surface);
	SDL_RenderCopy(g->main_win->sdl_renderer, t, NULL, &(t_rect){s.x, s.y, e.x - s.x, e.y - s.y});
	SDL_DestroyTexture(t);
}
