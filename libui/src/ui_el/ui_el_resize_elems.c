/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_resize_elems.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 04:04:46 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/19 01:23:01 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		ui_el_resize_elems(void *a1, void *a2)
{
	t_ui_win	*w;

	w = (t_ui_win *)a2;
	(void)a1;
	if (w != NULL)
		bfs_for_resize(w->canvas, NULL);
}
