/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:12:38 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/24 21:23:51 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_set_size(t_ui_el *el, int type, t_fvec2 v)
{
	t_ui_el	*p;

	p = el;
	while (p->parent)
		p = p->parent;
	if ((type & PIXEL))
	{
		el->rect.w = roundf(v.x);
		el->rect.h = roundf(v.y);
	}
	else if ((type & ABS))
	{
		el->rect.w = roundf((float)p->rect.w * v.x);
		el->rect.h = roundf((float)p->rect.h * v.y);
	}
	else
	{
		el->rect.w = roundf((float)el->parent->rect.w * v.x);
		el->rect.h = roundf((float)el->parent->rect.h * v.y);
	}
	el->relative_rect.w = (float)el->rect.w / (float)el->parent->rect.w;
	el->relative_rect.h = (float)el->rect.h / (float)el->parent->rect.h;
	el->cut_rect.w = el->rect.w;
	el->cut_rect.h = el->rect.h;
}
