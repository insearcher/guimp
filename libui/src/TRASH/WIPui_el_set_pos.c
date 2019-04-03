/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:48:34 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/29 20:48:24 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_set_rel_pos(t_ui_el *el, float x, float y)
{
	t_ui_el	*p;

	if (!el || !*el || !(p = el->parent))
		return ;
	if (fabs(x > 1.0))
		x > 0.0 ? x = 1.0 : x = -1.0;
	if (fabs(y > 1.0))
		x > 0.0 ? x = 1.0 : x = -1.0;
	el->pos->rel->x = x;
	el->pos->rel->y = y;
	el->pos->abs->x = p->size->abs->x * x;
	el->pos->abs->y = p->size->abs->y * y;
}

void	ui_el_set_abs_pos(t_ui_el *el, int x, int y)
{
	t_ui_el	*p;

	if (x > p->pos->abs->x || x < 0)
		x > 0 ? x = p->pos->abs->x : x = 0;
	if (y > p->pos->abs->y || y < 0)
		y > 0 ? y = p->pos->abs->y : y = 0;
	el->pos->abs->x = x;
	el->pos->abs->y = y;
	el->pos->rel->x = (float)((float)p->size->abs->x / (float)x);
	el->pos->rel->y = (float)((float)p->size->abs->y / (float)y);
}
