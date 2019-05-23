/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_drag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:15:41 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/23 05:39:19 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void 	ui_el_drag(void *a1, void *a2)
{
	t_ui_main	*m;
	t_ui_el		*el;
	int			x;
	int			y;

	m = (t_ui_main *)a1;
	el = (t_ui_el *)a2;
	x = m->ptr_pos.x - el->ptr_rel_pos.x;
	y = m->ptr_pos.y - el->ptr_rel_pos.y;
	if (x < el->parent->rect.x || y < el->parent->rect.y ||
		x + el->rect.w > el->parent->rect.x + el->parent->rect.w ||
		y + el->rect.h > el->parent->rect.y + el->parent->rect.h)
		return ;
	ui_el_change_pos(el, x, y);
}
