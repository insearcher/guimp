/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_abs_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:33:27 by edraugr-          #+#    #+#             */
/*   Updated: 2019/04/12 20:43:52 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_set_abs_size(t_ui_el *el, int w, int h)
{
	t_ui_el	*p;

	if (!el || !(p = el->parent) || w == 0 || h == 0)
		return ;
	// if (x > p->rect.x || x < 0)
	// 	x > 0 ? x = p->p->rect.x : x = 0;
	// if (y > p->p->rect.y || y < 0)
	// 	y > 0 ? y = p->p->rect.y : y = 0;
	el->rect.w = w;
	el->rect.h = h;
	el->frect.w = (float)((float)w / (float)p->rect.w);
	el->frect.h = (float)((float)h / (float)p->rect.h);
}
