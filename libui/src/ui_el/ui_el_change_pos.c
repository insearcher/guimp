/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_change_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 05:28:15 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 02:36:13 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void	ui_el_change_pos_in_tree(void *a1, void *a2)
{
	t_ui_el	*el;
	t_vec2	*dist;

	el = (t_ui_el *)a1;
	dist = (t_vec2 *)a2;
	el->rect.x += dist->x;
	el->rect.y += dist->y;
	el->relative_rect.x = (float)(el->rect.x - el->parent->rect.x) / (float)el->parent->rect.w;
	el->relative_rect.y = (float)(el->rect.y - el->parent->rect.y) / (float)el->parent->rect.h;
	el->cut_rect.x = el->rect.x;
	el->cut_rect.y = el->rect.y;
}

void    ui_el_change_pos(t_ui_el *el, t_ui_el *canvas, int type, t_fvec2 v)
{
	t_vec2  dist;

	if (type & PIXEL)
	{
		dist.x = roundf(v.x);
		dist.y = roundf(v.y);
	}
	else if ((type & ABS))
	{
		dist.x = roundf((float)canvas->rect.w * v.x);
		dist.y = roundf((float)canvas->rect.h * v.y);
	}
	else
	{
		dist.x = roundf((float)el->parent->rect.w * v.x);
		dist.y = roundf((float)el->parent->rect.h * v.y);
	}
	bfs_iter_root(el, ui_el_change_pos_in_tree, &dist);
}
