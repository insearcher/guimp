/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:12:38 by sbecker           #+#    #+#             */
/*   Updated: 2019/05/24 16:29:02 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_set_size(t_ui_el *el, t_ui_el *canvas, int type, t_fvec2 v)
{
	if ((type & SIZE_PIXEL))
	{
		el->rect.w = (int)v.x;
		el->rect.h = (int)v.y;
	}
	else if ((type & SIZE_ABS))
	{
		el->rect.w = canvas->rect.w * v.x;
		el->rect.h = canvas->rect.h * v.y;
	}
	else
	{
		el->rect.w = el->parent->rect.w * v.x;
		el->rect.h = el->parent->rect.h * v.y;
	}
	el->relative_rect.w = el->rect.w / (float)el->parent->rect.w;
	el->relative_rect.h = el->rect.h / (float)el->parent->rect.h;
	el->cut_rect.w = el->rect.w;
	el->cut_rect.h = el->rect.h;
}
