/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_change_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 05:28:15 by sbecker           #+#    #+#             */
/*   Updated: 2019/05/23 05:35:17 by sbecker          ###   ########.fr       */
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
}

void    ui_el_change_pos(t_ui_el *el, int x, int y)
{
	t_vec2  v;
	t_ui_el *p;

	if (!el || !(p = el->parent))
		return ;
	v.x = x - el->rect.x;
	v.y = y - el->rect.y;
	bfs_iter_root(el, ui_el_change_pos_for_children, &v);
}
