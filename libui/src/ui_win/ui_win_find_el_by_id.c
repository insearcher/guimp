/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_find_el_by_id.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 16:15:52 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 06:02:09 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_ui_el		*ui_win_find_el_by_id(t_ui_win *w, Uint32 id)
{
	if (w != NULL)
		return (bfs_for_find_el_by_id(w->canvas, id));
	return (NULL);
}
