/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_prefab_get_pixel_pos.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 23:45:08 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/06 01:25:11 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void    ui_prefab_get_pixel_pos(t_ui_el *p, t_ui_el *canvas, int type, t_fvec2 *v)
{
	if ((type & ABS) && (type & PIXEL))
	{
		v->x = roundf(v->x);
		v->y = roundf(v->y);
	}
	else if ((type & ABS))
	{
		v->x = roundf((float)canvas->rect.w * v->x);
		v->y = roundf((float)canvas->rect.h * v->y);
	}
	else if ((type & PIXEL))
	{
		v->x = roundf((float)p->rect.x + v->x);
		v->y = roundf((float)p->rect.y + v->y);
	}
	else
	{
		v->x = roundf((float)p->rect.x + (float)p->rect.w * v->x);
		v->y = roundf((float)p->rect.y + (float)p->rect.h * v->y);
	}
}
