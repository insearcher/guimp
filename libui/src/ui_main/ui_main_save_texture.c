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

void	ui_main_save_texture(t_ui_win *win, SDL_Texture *t, const char *path, int type)
{
	SDL_Texture	*p;
	SDL_Surface	*s;

	p = SDL_GetRenderTarget(win->sdl_renderer);
	s = SDL_CreateRGBSurface(0, win->size.x, win->size.y, 32, 0, 0, 0, 0);
	SDL_SetRenderTarget(win->sdl_renderer, t);
	SDL_RenderReadPixels(win->sdl_renderer, NULL, s->format->format, s->pixels, s->pitch);
	if (type == IMG_TYPE_PNG)
		IMG_SavePNG(s, path);
	else if (type == IMG_TYPE_JPG)
		IMG_SaveJPG(s, path, 100);
	SDL_SetRenderTarget(win->sdl_renderer, p);
}