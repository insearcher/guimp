/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_relative_pos_and_size.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:02:38 by sbecker           #+#    #+#             */
/*   Updated: 2019/05/23 11:07:28 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_set_relative_pos_and_size(t_ui_el *el)
{
	t_ui_el *p;

	if (!el || !(p = el->parent) || p->rect.w == 0 || p->rect.h == 0)
		return ;
	el->relative_rect.x = el->rect.x / (float)p->rect.w;
	el->relative_rect.y = el->rect.y / (float)p->rect.h;
	el->relative_rect.w = el->rect.w / (float)p->rect.w;
	el->relative_rect.h = el->rect.h / (float)p->rect.h;
}
