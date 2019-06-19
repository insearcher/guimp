/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 04:30:10 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/19 02:32:18 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_ui_el	*ui_raycast(t_ui_main *m, t_ui_win *w)
{
	t_ui_el		*res;

	if (w != NULL)
	{
		res = bfs_root(m, w->canvas, ui_el_is_pointer_inside);
		return (res);
	}
	return (NULL);
}
