/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:45:47 by sbecker           #+#    #+#             */
/*   Updated: 2019/05/26 09:14:11 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_set_pos(t_ui_el *el, t_ui_el *canvas, int type, t_fvec2 v)
{
	if ((type & POS_ABS) && (type & POS_PIXEL))
	{
		el->rect.x = roundf(v.x);
		el->rect.y = roundf(v.y);
	}
	else if ((type & POS_ABS))
	{
		el->rect.x = roundf((float)canvas->rect.w * v.x);
		el->rect.y = roundf((float)canvas->rect.h * v.y);
	}
	else if ((type & POS_PIXEL))
	{
		el->rect.x = roundf(v.x) + el->parent->rect.x;
		el->rect.y = roundf(v.y) + el->parent->rect.y;
	}
	else
	{
		el->rect.x = roundf((float)el->parent->rect.x + (float)el->parent->rect.w * v.x);
		el->rect.y = roundf((float)el->parent->rect.y + (float)el->parent->rect.h * v.y);
	}
	el->relative_rect.x = (float)(el->rect.x - el->parent->rect.x) / (float)el->parent->rect.w;
	el->relative_rect.y = (float)(el->rect.y - el->parent->rect.y) / (float)el->parent->rect.h;
	el->cut_rect.x = el->rect.x;
	el->cut_rect.y = el->rect.y;
}
