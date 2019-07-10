/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_create_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:54:15 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/10 02:34:52 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

/*
** OBSOLETE
*/

SDL_Texture	*ui_el_create_empty_texture(t_ui_el *el)
{
	SDL_Texture	*tmp_texture;

	if ((tmp_texture = SDL_CreateTexture(el->sdl_renderer, SDL_PIXELFORMAT_RGBA8888,
					SDL_TEXTUREACCESS_TARGET, el->rect.w, el->rect.h)) == NULL)
		return (NULL);
	SDL_SetRenderTarget(el->sdl_renderer, tmp_texture);
	SDL_SetRenderDrawBlendMode(el->sdl_renderer, SDL_BLENDMODE_NONE);
	SDL_SetRenderDrawColor(el->sdl_renderer, 255, 255, 255, 0);
	SDL_SetTextureBlendMode(tmp_texture, SDL_BLENDMODE_BLEND);
	SDL_RenderFillRect(el->sdl_renderer, NULL);
	SDL_SetRenderDrawBlendMode(el->sdl_renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderTarget(el->sdl_renderer, NULL);
	SDL_SetRenderDrawColor(el->sdl_renderer, 0, 0, 0, 255);
	return (tmp_texture);
}

SDL_Texture	*ui_el_create_texture(t_ui_el *el)
{
	SDL_Texture	*tmp;
	SDL_Rect	rect;

	if (!el->sdl_surface || !el->sdl_renderer)
		ui_sdl_deinit(EXIT_FAILURE);
	SDL_GetClipRect(el->sdl_surface, &rect);
	if (rect.w > 16384 || rect.h > 4000)
		return (ui_el_create_empty_texture(el));
	if (!(tmp = SDL_CreateTextureFromSurface(el->sdl_renderer, el->sdl_surface)))
		ui_sdl_deinit(EXIT_FAILURE);
	return (tmp);
}
