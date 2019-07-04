/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 04:01:11 by edraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 21:59:05 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

static t_vec2	lerp(t_vec2 p1, t_vec2 p2, float k)
{
	t_vec2	res;

	res.x = p1.x + roundf((float)(p2.x - p1.x) * k);
	res.y = p1.y + roundf((float)(p2.y - p1.y) * k);
	return (res);
}

static t_vec2	calc_el_dot(t_vec2 *d, float k)
{
	t_vec2	res;

	res = lerp(
			lerp(
				lerp(d[0], d[1], k),
				lerp(d[1], d[2], k),
				k
			),
			lerp(
				lerp(d[1], d[2], k),
				lerp(d[2], d[3], k),
				k
			),
			k
		);
	return (res);
}

void	draw_elipse(t_guimp *g, t_vec2 s, t_vec2 e)
{
	t_vec2	d[6];
	float	k;
	float	step;

	if (s.y > e.y)
	{
		d[0] = s;
		s = e;
		e = d[0];
	}
	d[0] = (t_vec2){s.x, s.y + (e.y - s.y) / 2};
	d[1] = s;
	d[2] = (t_vec2){e.x, s.y};
	d[3] = (t_vec2){e.x, d[0].y};
	if (s.x == e.x || s.y == e.y)
		return ;
	step = 1.0 / (float)((float)(e.y - s.y) / 2.0);
	k = 0;
	d[4] = calc_el_dot(d, k);
	while(k <= 1)
	{
		d[5] = calc_el_dot(d, k + step);
		if (d[4].y == d[5].y)
		{
			SDL_RenderDrawLine(g->main_win->sdl_renderer, d[4].x, d[4].y, s.x + e.x - d[4].x, d[4].y);
			SDL_RenderDrawLine(g->main_win->sdl_renderer, d[4].x, s.y + e.y - d[4].y, s.x + e.x - d[4].x, s.y + e.y - d[4].y);
		}
		else
			while (d[4].y != d[5].y)
			{
				SDL_RenderDrawLine(g->main_win->sdl_renderer, d[4].x, d[4].y, s.x + e.x - d[4].x, d[4].y);
				SDL_RenderDrawLine(g->main_win->sdl_renderer, d[4].x, s.y + e.y - d[4].y, s.x + e.x - d[4].x, s.y + e.y - d[4].y);
				d[4].y = d[4].y > d[5].y ? d[4].y - 1 : d[4].y + 1;
			}
		k += step;
		d[4] = d[5];
	}
}

void	draw_empty_elipse(t_guimp *g, t_vec2 s, t_vec2 e)
{
	t_vec2	d;

	if (s.y > e.y)
	{
		d = s;
		s = e;
		e = d;
	}
	// if (s.x > e.x)
	// {
	// 	d.x = s.x;
	// 	s.x = e.x;
	// 	e.x = s.x;
	// }
	draw_elipse(g, s, e);
	if (g->draw_tool.brush_size >= abs(e.x - s.x) / 2 || g->draw_tool.brush_size >= abs(e.y - s.y) / 2)
		return ;
	s = (t_vec2){s.x + g->draw_tool.brush_size, s.y + g->draw_tool.brush_size};
	e = (t_vec2){e.x - g->draw_tool.brush_size, e.y - g->draw_tool.brush_size};
	SDL_SetRenderDrawColor(g->main_win->sdl_renderer, 0, 0, 0, 0);
	SDL_SetRenderDrawBlendMode(g->main_win->sdl_renderer, SDL_BLENDMODE_NONE);
	draw_elipse(g, s, e);
}
