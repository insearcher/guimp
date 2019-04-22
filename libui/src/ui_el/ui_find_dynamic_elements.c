/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_find_dynamic_elements.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 04:04:46 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/22 04:05:54 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void	find_new_size(void *a1, void *a2)
{
	t_ui_el	*el = (t_ui_el *)a1;
	(void)a2;

	if (!(el->params & EL_DYNAMIC_SIZE))
		return ;
	ui_el_set_rel_size(el, el->frect.w, el->frect.h);
}

void		ui_find_dynamic_elements(void *a1, void *a2)
{
	t_ui_win	*w;

	w = (t_ui_win *)a2;
	(void)a1;
	if (w != NULL)
	{
		bfs_iter_root(&(w->canvas), &find_new_size, NULL);
	}
}
