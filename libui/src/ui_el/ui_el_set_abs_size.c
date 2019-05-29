/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_abs_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:33:27 by edraugr-          #+#    #+#             */
/*   Updated: 2019/05/23 14:34:19 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_set_abs_size(t_ui_el *el, int w, int h)
{
	t_ui_el	*p;

	if (!el || !(p = el->parent) || w == 0 || h == 0)
		return ;
	el->rect.w = w;
	el->rect.h = h;
	el->cut_rect.w = w;
	el->cut_rect.h = h;
	el->relative_rect.w = (float)((float)w / (float)p->rect.w);
	el->relative_rect.h = (float)((float)h / (float)p->rect.h);
}
