/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_new_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 21:13:32 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 05:54:42 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_set_new_pos_for_children(void *a1, void *a2)
{
	t_ui_el *el;

	el = (t_ui_el *)a1;
	(void)a2;
	el->rect.x = roundf((float)el->parent->rect.x
			+ (float)el->parent->rect.w * el->relative_rect.x);
	el->rect.y = roundf((float)el->parent->rect.y
			+ (float)el->parent->rect.h * el->relative_rect.y);
	el->cut_rect.x = el->rect.x;
	el->cut_rect.y = el->rect.y;
}

void	ui_el_set_new_pos(t_ui_el *el, t_ui_el *canvas, int type, t_fvec2 v)
{
	if ((type & ABS) && (type & PIXEL))
	{
		el->rect.x = roundf(v.x);
		el->rect.y = roundf(v.y);
	}
	else if ((type & ABS))
	{
		el->rect.x = roundf((float)canvas->rect.w * v.x);
		el->rect.y = roundf((float)canvas->rect.h * v.y);
	}
	else if ((type & PIXEL))
	{
		el->rect.x = roundf((float)el->parent->rect.x + v.x);
		el->rect.y = roundf((float)el->parent->rect.y + v.y);
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
	bfs_iter(el->children, ui_el_set_new_pos_for_children, 0);
}
