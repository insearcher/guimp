/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 04:30:10 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/12 09:53:45 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int	ui_raycast_bfs_is_pointer_inside_el(t_ui_main *m, void *a)
{
	t_ui_el     *el;
	Sint32      x;
	Sint32      y;

	el = (t_ui_el *)a;
	x = m->ptr_pos.x;
	y = m->ptr_pos.y;
	if (el->params & EL_IS_DEPENDENT)
		if (!((el->parent->cut_rect.x <= x && el->parent->cut_rect.y <= y) &&
					(x <= (el->parent->cut_rect.x + el->parent->cut_rect.w)
					 && y <= (el->parent->cut_rect.y + el->parent->cut_rect.h))))
			return (0);
	return ((el->rect.x <= x && el->rect.y <= y) &&
			(x <= (el->rect.x + el->rect.w) && y <= (el->rect.y + el->rect.h)));
}

t_ui_el	*ui_raycast(t_ui_main *m, t_ui_win *w)
{
	t_ui_el		*res;

	if (w != NULL)
	{
		res = bfs_root(m, w->canvas, ui_raycast_bfs_is_pointer_inside_el);
		return (res);
	}
	return (NULL);
}
