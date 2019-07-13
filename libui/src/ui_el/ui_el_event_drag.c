/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_drag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:15:41 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/13 09:30:24 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_el_event_drag(t_ui_main *m, void *a)
{
	t_ui_el		*el;
	int			x;
	int			y;

	el = (t_ui_el *)a;
	x = m->ptr_pos.x - el->ptr_rel_pos.x;
	y = m->ptr_pos.y - el->ptr_rel_pos.y;
	if (x < el->parent->rect.x || y < el->parent->rect.y ||
		x + el->rect.w > el->parent->rect.x + el->parent->rect.w ||
		y + el->rect.h > el->parent->rect.y + el->parent->rect.h)
		return (1);
	ui_el_set_new_pos(el, 0, PIXEL, (t_fvec2){x, y});
	return (1);
}

int	ui_el_event_hor_slider_drag(t_ui_main *m, void *a)
{
	t_ui_el		*el;
	int			x;
	int			y;

	el = (t_ui_el *)a;
	printf("1: (%d, %d)\n", el->rect.x, el->rect.y);
	x = m->ptr_pos.x - el->ptr_rel_pos.x;
	y = el->rect.y;
	if (x < el->parent->rect.x ||
		x + el->rect.w > el->parent->rect.x + el->parent->rect.w)
		return (1);
	ui_el_set_new_pos(el, 0, ABS | PIXEL, (t_fvec2){x, y});
	return (1);
}
