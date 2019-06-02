/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_find_dynamic_elements.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 04:04:46 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/31 20:50:51 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		ui_el_resize_elems(void *a1, void *a2)
{
	t_ui_win	*w;

	w = (t_ui_win *)a2;
	(void)a1;
	if (w != NULL)
		bfs_for_resize(&(w->canvas), NULL);
}
