/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:12:48 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/10 16:13:20 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	choose_brush(void *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	(void)el_v;
	g->draw_tool.tool = GM_TOOL_BRUSH;
}

void	tool_brush(t_ui_el *el, t_guimp *g, int x, int y)
{
	SDL_SetRenderTarget(el->sdl_renderer, (SDL_Texture *)(g->layers.current_layer->sdl_textures->content));
	SDL_SetTextureColorMod(ui_el_get_texture_by_id(el, "brush"), g->draw_tool.r, g->draw_tool.g, g->draw_tool.b); //вместо ui_el_get_texture_by_id(el, "brush") нужно выбрать текстуру текущей кисти
	SDL_SetTextureAlphaMod(ui_el_get_texture_by_id(el, "brush"), g->draw_tool.a);
	SDL_RenderCopy(el->sdl_renderer, ui_el_get_texture_by_id(el, "brush"), NULL,
				   &((t_rect){x - g->draw_tool.brush_size / 2, y - g->draw_tool.brush_size / 2,
							  g->draw_tool.brush_size, g->draw_tool.brush_size})); //вместо ui_el_get_texture_by_id(el, "brush") нужно выбрать текстуру текущей кисти
	SDL_SetRenderTarget(el->sdl_renderer, NULL);
}