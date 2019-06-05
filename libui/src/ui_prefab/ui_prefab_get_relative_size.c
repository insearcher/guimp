/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_prefab_get_relative_size.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:01:29 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/05 04:47:09 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_prefab_get_relative_size(t_ui_el *p, t_ui_el *canvas, int type, t_fvec2 *size)
{
	if (type == 0)
		return ;
	if ((type & PIXEL))
	{
		size->x /= (float)p->rect.w;
		size->y /= (float)p->rect.h;
	}
	else if ((type & ABS))
	{
		size->x = (float)p->rect.w / (float)canvas->rect.w - size->x;
		size->y = (float)p->rect.h / (float)canvas->rect.h - size->y;
	}
}
