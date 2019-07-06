/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_log_el_right_button_hold.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 07:55:57 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/03 14:08:08 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_log_el_right_button_hold(void *a1, void *a2)
{
	t_ui_main	*m;
	t_ui_el		*el;

	m = (t_ui_main *)a1;
	el = (t_ui_el *)a2;
	SDL_Log("%s%-15s%sglobal = %3d;%-3d   local = %3d;%-3d   elementID = %-3d",   //windowID = %-3d\n",
		KMAG,
		"RMB HOLD",
		KNRM,
		m->ptr_pos.x,
		m->ptr_pos.y,
		el->ptr_rel_pos.x,
		el->ptr_rel_pos.y,
		el->id
//		m->raycaster->focused_win->id
	);
}
