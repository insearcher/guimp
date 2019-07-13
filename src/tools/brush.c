/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:12:48 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/13 09:56:58 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

int	choose_brush(t_ui_main *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	(void)el_v;
	g->draw_tool.tool = GM_TOOL_BRUSH;
	return (1);
}

int	set_brush_texture_from_el(t_ui_main *main, void *el_v)
{
	t_guimp 	*g;
	t_ui_el 	*el;

	g = (t_guimp *) (((t_ui_main *) main)->data);
	el = (t_ui_el *) el_v;
	g->draw_tool.brush = (SDL_Texture *)el->data;
	return (1);
}

void	tool_brush(t_ui_el *el, t_guimp *g, int x, int y)
{
	SDL_SetRenderTarget(el->sdl_renderer, (SDL_Texture *)(g->layers.current_layer->sdl_textures->content));
	SDL_SetTextureColorMod(g->draw_tool.brush, g->draw_tool.r, g->draw_tool.g, g->draw_tool.b); //вместо ui_el_get_texture_by_id(el, "brush") нужно выбрать текстуру текущей кисти
	SDL_SetTextureAlphaMod(g->draw_tool.brush, g->draw_tool.a);
	SDL_RenderCopy(el->sdl_renderer, g->draw_tool.brush, NULL,
				   &((t_rect){x - g->draw_tool.brush_size / 2, y - g->draw_tool.brush_size / 2,
							g->draw_tool.brush_size, g->draw_tool.brush_size})); //вместо ui_el_get_texture_by_id(el, "brush") нужно выбрать текстуру текущей кисти
	SDL_SetRenderTarget(el->sdl_renderer, NULL);
}