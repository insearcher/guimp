/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_event_pointer_moved.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 05:03:30 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 09:21:34 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_main_event_pointer_moved(t_ui_main *m, void *a)
{
	(void)a;
	m->raycaster->focused_win = ui_main_find_window_by_sdl_id(m, m->sdl_event->motion.windowID);
	m->ptr_pos.x = m->sdl_event->motion.x;
	m->ptr_pos.y = m->sdl_event->motion.y;
	return (1);
}
