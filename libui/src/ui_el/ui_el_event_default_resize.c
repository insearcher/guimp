/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_event_default_resize.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:03:56 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 09:17:11 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_el_event_default_resize(t_ui_main *m, void *a)
{
	t_ui_el *el;

	el = (t_ui_el *)a;
	(void)m;
	el->rect.x = roundf(el->parent->rect.x + (float)el->parent->rect.w * el->relative_rect.x);
	el->rect.y = roundf(el->parent->rect.y + (float)el->parent->rect.h * el->relative_rect.y);
	el->rect.w = roundf((float)el->parent->rect.w * el->relative_rect.w);
	el->rect.h = roundf((float)el->parent->rect.h * el->relative_rect.h);
	el->cut_rect = el->rect;
	return (1);
}
