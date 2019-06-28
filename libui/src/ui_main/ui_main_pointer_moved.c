/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_pointer_moved.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:42:30 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/27 20:47:51 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_pointer_moved(void *a1, void *a2)
{
	t_ui_main	*m;

	m = (t_ui_main *)a1;
	(void)a2;
	m->raycaster->focused_win = ui_main_find_window_by_sdl_id(m, m->sdl_event->motion.windowID);
	m->ptr_pos.x = m->sdl_event->motion.x;
	m->ptr_pos.y = m->sdl_event->motion.y;
}
