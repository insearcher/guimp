/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_is_pointer_inside.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 04:37:32 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/25 19:48:45 by sbednar          ###   ########.fr       */
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
	if (el->params & EL_IGNOR_RAYCAST)
		return (0);
	x = m->ptr_pos.x;
	y = m->ptr_pos.y;
	return ((el->rect.x <= x && el->rect.y <= y) &&
		(x <= (el->rect.x + el->rect.w) && y <= (el->rect.y + el->rect.h)));
}
