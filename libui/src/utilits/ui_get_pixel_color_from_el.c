/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_get_pixel_color_from_el.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:19:29 by edraugr-          #+#    #+#             */
/*   Updated: 2019/06/27 19:57:30 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

Uint32	ui_get_pixel_color_from_el(SDL_Renderer *renderer,
		t_ui_el *el, t_vec2 coord)
{
	Uint32		res;
	SDL_Surface	*surf;
	Uint8		*p;

	surf = SDL_CreateRGBSurfaceWithFormat(0, 1, 1, 24, SDL_PIXELFORMAT_RGBA8888);
	res = 0;
	SDL_RenderReadPixels(renderer, &((t_rect){coord.x + el->rect.x, coord.y + el->rect.y, 1, 1}), 0, surf->pixels, surf->pitch);
	p = (Uint8 *)surf->pixels;
	//printf("r: %d, g: %d, b: %d\n", p[2], p[1], p[0]);
	res = (p[2] << 16 & 0xFF0000) + (p[1] << 8 & 0xFF00) + (p[0] & 0xFF);
	SDL_FreeSurface(surf);
	SDL_SetRenderTarget(renderer, NULL);
	return (res);
}
