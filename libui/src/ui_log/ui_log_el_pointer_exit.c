/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_log_el_pointer_exit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 04:14:00 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/22 07:43:34 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_log_el_pointer_exit(void *a1, void *a2)
{
	t_ui_main	*m;
	t_ui_el		*el;

	m = (t_ui_main *)a1;
	el = (t_ui_el *)a2;
	SDL_Log("%sPOINTER EXIT%s\tglobal=(%d;%d)\tlocal=(%d;%d)\telementID=%d\twindowID=%d\n",
		KRED,
		KNRM,
		m->sdl_event.motion.x,
		m->sdl_event.motion.y,
		el->ptr_rel_pos.x,
		el->ptr_rel_pos.y,
		el->id,
		m->sdl_event.window.windowID
	);
}
