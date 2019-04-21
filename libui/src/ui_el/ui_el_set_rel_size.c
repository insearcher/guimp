/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_rel_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:35:05 by edraugr-          #+#    #+#             */
/*   Updated: 2019/04/12 20:19:05 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_set_rel_size(t_ui_el *el, float w, float h)
{
	t_ui_el	*p;

	if (!el || !(p = el->parent) || w == 0.0 || h == 0.0)
		return ;
	el->frect.w = w;
	el->frect.h = h;
	el->rect.w = (int)((float)p->rect.w * w);
	el->rect.h = (int)((float)p->rect.h * h);
}
