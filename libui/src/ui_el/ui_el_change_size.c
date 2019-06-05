/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_change_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 22:01:02 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/05 16:42:03 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void ui_el_change_size_in_tree(void *a1, void *a2)
{
	t_ui_el *el;
	t_vec2  *dist;

	el = (t_ui_el *)a1;
	dist = (t_vec2 *)a2;
	el->rect.w += dist->x;
	el->rect.h += dist->y;
	el->relative_rect.w = (float)el->rect.w / (float)el->parent->rect.w;
	el->relative_rect.h = (float)el->rect.h / (float)el->parent->rect.h;
	el->cut_rect.w = el->rect.w;
	el->cut_rect.h = el->rect.h;
}

void		ui_el_change_size(t_ui_el *el, t_ui_el *canvas, int type, t_fvec2 v)
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
	bfs_iter_root(el, ui_el_change_size_in_tree, &dist);
}
