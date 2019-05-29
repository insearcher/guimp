/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_rel_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:35:28 by edraugr-          #+#    #+#             */
/*   Updated: 2019/05/23 14:38:13 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_set_rel_pos(t_ui_el *el, float x, float y)
{
	t_ui_el	*p;

	if (!el || !(p = el->parent))
		return ;
	el->relative_rect.x = x;
	el->relative_rect.y = y;
	el->rect.x = (int)((float)p->rect.w * x);
	el->rect.y = (int)((float)p->rect.h * y);
	el->cut_rect.x = el->rect.x;
	el->cut_rect.y = el->rect.y;
}
