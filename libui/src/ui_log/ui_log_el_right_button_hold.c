/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_log_el_right_button_hold.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 07:55:57 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/24 13:52:02 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_log_el_right_button_hold(void *a1, void *a2)
{
	t_ui_main	*m;
	t_ui_el		*el;

	m = (t_ui_main *)a1;
	el = (t_ui_el *)a2;
	SDL_Log("%s%-15s%sglobal = %3d;%-3d   local = %3d;%-3d   elementID = %-3d   windowID = %-3d\n",
		KBLU,
		"RMB HOLD",
		KNRM,
		m->sdl_event.motion.x,
		m->sdl_event.motion.y,
		el->ptr_rel_pos.x,
		el->ptr_rel_pos.y,
		el->id,
		m->sdl_event.window.windowID
	);
}