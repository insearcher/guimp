/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_abs_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:35:28 by edraugr-          #+#    #+#             */
/*   Updated: 2019/04/22 10:41:36 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_set_abs_pos(t_ui_el *el, int x, int y)
{
	t_ui_el	*p;

	if (!el || !(p = el->parent))
		return ;
	el->rect.x = x;
	el->rect.y = y;
	el->frect.x = (float)((float)x / (float)p->rect.w);
	el->frect.y = (float)((float)y / (float)p->rect.h);
}
