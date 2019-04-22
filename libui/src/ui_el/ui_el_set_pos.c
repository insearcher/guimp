/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 10:36:17 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/22 10:40:37 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void ui_el_set_pos_abs(t_ui_el *el, int x, int y)
{
	t_ui_el	*p;

	if (!el || !(p = el->parent))
		return ;
	el->frect.x = x;
	el->frect.y = y;
	el->rect.x = (int)((float)p->rect.w * x);
	el->rect.y = (int)((float)p->rect.h * y);
}

static void ui_el_set_pos_flex(t_ui_el *el, int x, int y)
{

}

static void ui_el_set_pos_rel(t_ui_el *el, int x, int y)
{

}

void	ui_el_set_pos(t_ui_el *el, int x, int y, int m)
{
	if (m == EL_POS_ABSOLUTE)
		ui_el_set_pos_abs(el, x, y);
	else if (m == EL_POS_FLEXIBLE)
		ui_el_set_pos_flex(el, x, y);
	else if (m == EL_POS_RELATIVE)
		ui_el_set_pos_rel(el, x, y);
}
