/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_abs_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:35:28 by edraugr-          #+#    #+#             */
/*   Updated: 2019/05/23 02:05:09 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void	ui_el_set_abs_pos_for_children(void *a1, void *a2)
{
	t_ui_el	*el;
	t_vec2	*d;

	el = (t_ui_el *)a1;
	d = (t_vec2 *)a2;
	el->rect.x += d->x;
	el->rect.y += d->y;
	el->frect.x = (float)((float)el->rect.x / (float)el->parent->rect.w);
	el->frect.y = (float)((float)el->rect.y / (float)el->parent->rect.h);
}

void	ui_el_set_abs_pos(t_ui_el *el, int x, int y)
{
	t_vec2	v;
	t_ui_el	*p;

	if (!el || !(p = el->parent))
		return ;
	v.x = x - el->rect.x;
	v.y = y - el->rect.y;
	bfs_iter_root(el, ui_el_set_abs_pos_for_children, &v);
}
