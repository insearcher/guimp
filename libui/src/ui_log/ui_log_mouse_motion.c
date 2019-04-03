/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_log_mouse_motion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:37:29 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/03 23:55:17 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_log_mouse_motion(void *a1, void *a2)
{
	t_ui_main	*m;
	t_ui_win	*w;
	Uint32		windowID;

	m = (t_ui_main *)a1;
	windowID = *((Uint32 *)a2);
	w = ui_main_find_window_by_id(m, windowID);
	if (w == NULL)
	{
		SDL_Log("Window with ID=%d doesn't exists in main!!!\n", windowID);
	}
	else
	{
		SDL_Log("Mouse moved to (%d,%d) in win with ID=%d\n", m->sdl_event.motion.x, m->sdl_event.motion.y, windowID);
	}
}
