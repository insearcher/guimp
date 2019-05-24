/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:45:47 by sbecker           #+#    #+#             */
/*   Updated: 2019/05/24 17:08:01 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_set_pos(t_ui_el *el, t_ui_el *canvas, int type, t_fvec2 v)
{
	printf ("%d\n", POS_ABS);
	printf ("%d\n", POS_PIXEL);
	printf ("%d\n", type);
	if ((type & POS_ABS) && (type & POS_PIXEL))
	{
		el->rect.x = (int)v.x;
		el->rect.y = (int)v.y;
		printf("elID: %d CHECK1\n", el->id);
	}
	else if ((type & POS_ABS))
	{
		el->rect.x = (int)(canvas->rect.w * v.x);
		el->rect.y = (int)(canvas->rect.h * v.y);
		printf("elID: %d CHECK2\n", el->id);
	}
	else if ((type & POS_PIXEL))
	{
		el->rect.x = (int)v.x + el->parent->rect.x;
		el->rect.y = (int)v.y + el->parent->rect.y;
		printf("elID: %d CHECK3\n", el->id);
	}
	else
	{
		el->rect.x = el->parent->rect.x + (int)(el->parent->rect.w * v.x);
		el->rect.y = el->parent->rect.y + (int)(el->parent->rect.h * v.y);
		printf("elID: %d CHECK4\n", el->id);
	}
	el->relative_rect.x = (float)el->rect.x / (float)el->parent->rect.w;
	el->relative_rect.y = (float)el->rect.y / (float)el->parent->rect.h;
	el->cut_rect.x = el->rect.x;
	el->cut_rect.y = el->rect.y;
}
