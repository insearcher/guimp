/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_change_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 05:28:15 by sbecker           #+#    #+#             */
/*   Updated: 2019/05/26 09:15:56 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void	ui_el_change_pos_for_children(void *a1, void *a2)
{
	t_ui_el *el;
	t_vec2  *d;

	el = (t_ui_el *)a1;
	d = (t_vec2 *)a2;
	el->rect.x += d->x;
	el->rect.y += d->y;
	el->cut_rect.x = el->rect.x;
	el->cut_rect.y = el->rect.y;
}

void    ui_el_change_pos(t_ui_el *el, int x, int y)
{
	t_vec2  v;
	t_ui_el *p;
	t_vec2	change_relative;

	if (!el || !(p = el->parent))
		return ;
	v.x = x - el->rect.x;
	v.y = y - el->rect.y;
	change_relative.x = el->rect.x + v.x;
	change_relative.y = el->rect.y + v.y;
	el->relative_rect.x = (float)(change_relative.x - el->parent->rect.x) / (float)el->parent->rect.w;
	el->relative_rect.y = (float)(change_relative.y - el->parent->rect.y) / (float)el->parent->rect.h;
	bfs_iter_root(el, ui_el_change_pos_for_children, &v);
}
