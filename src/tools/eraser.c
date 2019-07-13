/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eraser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:36:26 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/13 10:12:40 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

int	choose_eraser(t_ui_main *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(main->data);
	(void)el_v;
	g->draw_tool.tool = GM_TOOL_ERASER;
	return (1);
}

void	tool_eraser(t_ui_el *el, t_guimp *g, int x, int y)
{
	SDL_BlendMode	bm;
	int				s;

//	ui_draw_circle(el->sdl_renderer, (t_rect){x, y, 0, 200}, SDL_BLENDMODE_NONE, (SDL_Color){255,255,0,255});
	s = g->draw_tool.brush_size;
	SDL_SetRenderTarget(el->sdl_renderer, (SDL_Texture *)(g->layers.current_layer->sdl_textures->content));
	SDL_GetRenderDrawBlendMode(el->sdl_renderer, &bm);
	SDL_SetRenderDrawBlendMode(el->sdl_renderer, SDL_BLENDMODE_NONE);
	SDL_SetRenderDrawColor(el->sdl_renderer, 255, 255, 255, 0);
	SDL_RenderFillRect(el->sdl_renderer, &(t_rect){x - s, y - s, 2 * s, 2 * s});
	SDL_SetRenderTarget(el->sdl_renderer, NULL);
	SDL_SetRenderDrawBlendMode(el->sdl_renderer, bm);
}

