/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fat_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 19:33:23 by edraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 19:25:51 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

static t_fvec2	get_normal(int x1, int y1, int x2, int y2)
{
	t_fvec2	res;
	float	lenth;
	int		tmp;

	if (y2 == y1)
	{
		res.x = 0;
		res.y = 1;
		return (res);
	}
	if (x2 == x1)
	{
		res.x = 1;
		res.y = 0;
		return (res);
	}
	res.x = 1.0;
	res.y = (float)(x2 - x1) / (float)(y2 - y1);
	lenth = sqrt(res.y * res.y + 1);
	res.x /= lenth;
	res.y /= lenth;
	if (x2 > x1)
		res.x *= -1;
	if (x2 < x1)
		res.y *= -1;
	return (res);
}

void			draw_fat_line(t_guimp *g, t_vec2 start, t_vec2 end)
{
	t_fvec2	norm;
	int		i;
	t_vec2	p1;
	t_vec2	p2;

	i = -g->draw_tool.brush_size / 2 - 1;
	norm = get_normal(start.x, start.y, end.x, end.y);
	while (++i < g->draw_tool.brush_size / 2)
	{
		p1.x = start.x + i * norm.x;
		p1.y = start.y + i * norm.y;
		p2.x = end.x + i * norm.x;
		p2.y = end.y + i * norm.y;
		SDL_RenderDrawLine(g->main_win->sdl_renderer, p1.x, p1.y, p2.x, p2.y);
		SDL_RenderDrawLine(g->main_win->sdl_renderer, p1.x, p1.y + 1, p2.x, p2.y + 1);
		SDL_RenderDrawLine(g->main_win->sdl_renderer, p1.x + 1, p1.y, p2.x + 1, p2.y);
		SDL_RenderDrawLine(g->main_win->sdl_renderer, p1.x, p1.y - 1, p2.x, p2.y - 1);
		SDL_RenderDrawLine(g->main_win->sdl_renderer, p1.x - 1, p1.y, p2.x - 1, p2.y);
	}
}
