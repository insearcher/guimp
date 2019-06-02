/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_default_resize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 20:41:19 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/01 15:19:09 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_default_resize(void *a1, void *a2)
{
	t_ui_el *el;

	el = (t_ui_el *)a1;
	(void)a2;
	el->rect.x = roundf(el->parent->rect.x + (float)el->parent->rect.w * el->relative_rect.x);
	el->rect.y = roundf(el->parent->rect.y + (float)el->parent->rect.h * el->relative_rect.y);
	el->rect.w = roundf((float)el->parent->rect.w * el->relative_rect.w);
	el->rect.h = roundf((float)el->parent->rect.h * el->relative_rect.h);
	el->cut_rect = el->rect;
}
