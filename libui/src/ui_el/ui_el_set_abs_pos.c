/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_abs_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:35:28 by edraugr-          #+#    #+#             */
/*   Updated: 2019/05/23 14:35:51 by edraugr-         ###   ########.fr       */
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
	el->cut_rect.x = x;
	el->cut_rect.y = y;
	el->relative_rect.x = (float)((float)el->rect.x / (float)p->rect.w);
	el->relative_rect.y = (float)((float)el->rect.y / (float)p->rect.h);
}
