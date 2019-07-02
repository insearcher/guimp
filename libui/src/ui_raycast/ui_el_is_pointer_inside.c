/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_is_pointer_inside.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 04:37:32 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/02 07:54:09 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_el_is_pointer_inside(void *a1, void *a2)
{
	t_ui_main	*m;
	t_ui_el		*el;
	Sint32		x;
	Sint32		y;

	m = (t_ui_main *)a1;
	el = (t_ui_el *)a2;
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
