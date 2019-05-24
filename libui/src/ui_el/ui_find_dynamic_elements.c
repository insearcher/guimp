/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_find_dynamic_elements.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 04:04:46 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/24 17:13:34 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void	find_new_size(void *a1, void *a2)
{
	t_ui_el	*el = (t_ui_el *)a1;
	(void)a2;

	if (!(el->params & EL_DYNAMIC_SIZE))
		return ;
	el->rect.x = (float)el->parent->rect.w * el->relative_rect.x;
	el->rect.y = (float)el->parent->rect.h * el->relative_rect.y;
	el->rect.w = (float)el->parent->rect.w * el->relative_rect.w;
	el->rect.h = (float)el->parent->rect.h * el->relative_rect.h;
	el->cut_rect = el->rect;
}

void		ui_find_dynamic_elements(void *a1, void *a2)
{
	t_ui_win	*w;

	w = (t_ui_win *)a2;
	(void)a1;
	if (w != NULL)
		bfs_iter_root(&(w->canvas), &find_new_size, NULL);
}
