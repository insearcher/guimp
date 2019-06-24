/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:45:47 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/24 21:23:56 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_set_pos(t_ui_el *el, int type, t_fvec2 v)
{
	t_ui_el	*p;

	p = el;
	while (p->parent)
		p = p->parent;
	if ((type & ABS) && (type & PIXEL))
	{
		el->rect.x = roundf(v.x);
		el->rect.y = roundf(v.y);
	}
	else if ((type & ABS))
	{
		el->rect.x = roundf((float)p->rect.w * v.x);
		el->rect.y = roundf((float)p->rect.h * v.y);
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
}
