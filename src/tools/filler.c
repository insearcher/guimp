/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:29:55 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/13 07:16:56 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

static Uint32	getpixel(SDL_Surface *surface, int x, int y)
{
	int bpp = surface->format->BytesPerPixel;
	/* Here p is the address to the pixel we want to retrieve */
	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

	switch(bpp) {
		case 1:
			return *p;

		case 2:
			return *(Uint16 *)p;

		case 3:
			if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
				return p[0] << 16 | p[1] << 8 | p[2];
			else
				return p[0] | p[1] << 8 | p[2] << 16;

		case 4:
			return *(Uint32 *)p;

		default:
			return 0;       /* shouldn't happen, but avoids warnings */
	}
//	int bpp;
//	Uint8 *p;

	/*
	* Get destination format
	//*/
	//bpp = surface->format->BytesPerPixel;
	//p = (Uint8 *) surface->pixels + y * surface->pitch + x * bpp;
	//return
	//		*(Uint32 *) p;
}

static void	putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
	int bpp;
	Uint8 *p;

	/*
	* Get destination format
	*/
	bpp = surface->format->BytesPerPixel;
	p = (Uint8 *) surface->pixels + y * surface->pitch + x * bpp;
	switch (bpp) {
		case 1:
			*p = pixel;
			break;
		case 2:
			*(Uint16 *) p = pixel;
			break;
		case 3:
			if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
				p[0] = (pixel >> 16) & 0xff;
				p[1] = (pixel >> 8) & 0xff;
				p[2] = pixel & 0xff;
			} else {
				p[0] = pixel & 0xff;
				p[1] = (pixel >> 8) & 0xff;
				p[2] = (pixel >> 16) & 0xff;
			}
			break;
		case 4:
			*(Uint32 *) p = pixel;
			break;
	}				/* switch */
}

void	tool_filler(t_ui_win *w, t_texture *texture, t_cvec2 color, t_vec2 coord)
{
	char 	*field;
	int f = 0;
	int l = 0;
	int *queue;
	int x, y;

	x = w->size.x * w->size.y;
	field = (char *)malloc(x);
	for (int i = 0; i < x; i++)
		field[i] = 0;
	queue = (int *)malloc(x * sizeof(int));
	SDL_SetRenderDrawColor(w->sdl_renderer, 255, 255, 255, 0);
	SDL_RenderClear(w->sdl_renderer);
	SDL_Texture *t = SDL_CreateTexture(w->sdl_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, w->size.x, w->size.y);
	SDL_SetRenderTarget(w->sdl_renderer, t);
	SDL_RenderCopy(w->sdl_renderer, texture, NULL, NULL);
	SDL_Surface *s = SDL_CreateRGBSurface(0, w->size.x, w->size.y, 32, 0, 0, 0, 1);
	SDL_RenderReadPixels(w->sdl_renderer, NULL, s->format->format, s->pixels, s->pitch);
	for (int i = 0; i < x; i++)
		queue[i] = 0;
	queue[l++] = coord.x * 10000 + coord.y;
	while (f < l)
	{
		x = queue[f] / 10000;
		y = queue[f++] % 10000;
		if (field[y * w->size.x + x] <= '2' && getpixel(s, x, y) == color.color2)
		{
			putpixel(s, x, y, color.color1);
			field[y * w->size.x + x] = '2';
		}
		if (x + 1 < w->size.x && !field[y * w->size.x + x + 1] && getpixel(s, x + 1, y) == color.color2)
		{
			queue[l++] = (x + 1) * 10000 + y;
			field[y * w->size.x + x + 1] = '1';
		}
		if (x - 1 >= 0 && !field[y * w->size.x + x - 1] && getpixel(s, x - 1, y) == color.color2)
		{
			queue[l++] = (x - 1) * 10000 + y;
			field[y * w->size.x + x - 1] = '1';
		}
		if (y - 1 >= 0 && !field[(y - 1) * w->size.x + x] && getpixel(s, x, y - 1) == color.color2)
		{
			queue[l++] = x * 10000 + y - 1;
			field[(y - 1) * w->size.x + x] = '1';
		}
		if (y + 1 < w->size.y && !field[(y + 1) * w->size.x + x] && getpixel(s, x, y + 1) == color.color2)
		{
			queue[l++] = x * 10000 + y + 1;
			field[(y + 1) * w->size.x + x] = '1';
		}
	}
	SDL_Texture *tmp = SDL_CreateTextureFromSurface(w->sdl_renderer, s);
	SDL_SetRenderTarget(w->sdl_renderer, texture);
	SDL_RenderCopy(w->sdl_renderer, tmp, NULL, NULL);
	SDL_SetRenderTarget(w->sdl_renderer, NULL);
	free(field);
	free(queue);
	SDL_DestroyTexture(tmp);
	SDL_DestroyTexture(t);
	SDL_FreeSurface(s);
}

void choose_fill(t_ui_main *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(main->data);
	(void)el_v;
	g->draw_tool.tool = GM_TOOL_FILL;
}
