/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_save_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:09:46 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/09 19:22:46 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_save_texture(SDL_Renderer *r, SDL_Texture *t, const char *path, int type)
{
	SDL_Texture	*p;
	SDL_Surface	*s;

	p = SDL_GetRenderTarget(r);
	s = SDL_CreateRGBSurface(0, 1704, 800, 32, 0, 0, 0, 0);
	SDL_SetRenderTarget(r, t);
	SDL_RenderReadPixels(r, NULL, s->format->format, s->pixels, s->pitch);
	if (type == IMG_TYPE_PNG)
		IMG_SavePNG(s, path);
	else if (type == IMG_TYPE_JPG)
		IMG_SaveJPG(s, path, 100);
	SDL_SetRenderTarget(r, p);
}