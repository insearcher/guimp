/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_prefab_get_relative_pos.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 08:34:01 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/05 05:46:36 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_prefab_get_relative_pos(t_ui_el *p, t_ui_el *canvas, int type, t_fvec2 *pos)
{
	if (type == 0)
		return ;
	if ((type & ABS) && (type & PIXEL))
	{
		pos->x = (float)(pos->x - p->rect.x) / (float)p->rect.w;
		pos->y = (float)(pos->y - p->rect.y) / (float)p->rect.h;
	}
	else if ((type & ABS))
	{
		pos->x -= (float)p->rect.x / (float)canvas->rect.w;
		pos->y -= (float)p->rect.y / (float)canvas->rect.h;
	}
	else if ((type & PIXEL))
	{
		pos->x = pos->x / (float)p->rect.w;
		pos->y = pos->y / (float)p->rect.h;
	}
}
