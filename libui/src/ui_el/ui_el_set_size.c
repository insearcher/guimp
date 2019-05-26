/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:12:38 by sbecker           #+#    #+#             */
/*   Updated: 2019/05/26 09:03:01 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_set_size(t_ui_el *el, t_ui_el *canvas, int type, t_fvec2 v)
{
	if ((type & SIZE_PIXEL))
	{
		el->rect.w = roundf(v.x);
		el->rect.h = roundf(v.y);
	}
	else if ((type & SIZE_ABS))
	{
		el->rect.w = roundf((float)canvas->rect.w * v.x);
		el->rect.h = roundf((float)canvas->rect.h * v.y);
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
