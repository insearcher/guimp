/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_set_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 22:53:44 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/30 21:26:13 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_set_pixel(t_env *e, const int x, const int y, const Uint32 c)
{
	int		bpp;
	Uint8	*p;

	if (x < 0 || x >= e->w || y < 0 || y >= e->h)
		return ;
	bpp = e->sur->format->BytesPerPixel;
	p = (Uint8 *)e->sur->pixels + y * e->sur->pitch + x * bpp;
	(bpp == 1) ? *p = c : 0;
	(bpp == 2) ? *(Uint16 *)p = c : 0;
	(bpp == 4) ? *(Uint32 *)p = c : 0;
	if (bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
		{
			p[0] = (c >> 16) & 0xFF;
			p[1] = (c >> 8) & 0xFF;
			p[2] = c & 0xFF;
		}
		else
		{
			p[0] = c & 0xFF;
			p[1] = (c >> 8) & 0xFF;
			p[2] = (c >> 16) & 0xFF;
		}
	}
}
