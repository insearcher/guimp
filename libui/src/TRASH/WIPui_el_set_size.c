/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:21:20 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/28 14:51:47 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_set_rel_size(t_ui_el *el, float x, float y)
{
	t_ui_el	*p;

	if (!el || !*el || !(p = el->parent))
		return ;
	if (fabs(x > 1.0))
		x > 0.0 ? x = 1.0 : x = -1.0;
	if (fabs(y > 1.0))
		x > 0.0 ? x = 1.0 : x = -1.0;
	el->size->rel->x = x;
	el->size->rel->y = y;
	el->size->abs->x = p->size->abs->x * x;
	el->size->abs->y = p->size->abs->y * y;
}

void	ui_el_set_abs_size(t_ui_el *el, float x, float y)
{
	t_ui_el	*p;

	if (!el || !*el || !(p = el->parent))
		return ;
	if (x > p->size->abs->x || x < 0)
		x > 0 ? x = p->size->abs->x : x = 0;
	if (y > p->size->abs->y || y < 0)
		y > 0 ? y = p->size->abs->y : y = 0;
	el->size->abs->x = x;
	el->size->abs->y = y;
	el->size->rel->x = (float)((float)p->size->abs->x / (float)x);
	el->size->rel->y = (float)((float)p->size->abs->y / (float)y);
}
