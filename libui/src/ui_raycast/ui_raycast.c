/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 04:30:10 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/22 05:37:32 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_ui_el	*ui_raycast(t_ui_main *m, Uint32 windowID)
{
	t_ui_el		*res;
	t_ui_win	*w;

	w = ui_main_find_window_by_id(m, windowID);
	if (w != NULL)
	{
		res = bfs_root(m, &(w->canvas), &ui_el_is_pointer_inside);
		return (res);
	}
	return (NULL);
}
