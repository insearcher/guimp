/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_log_mouse_button_up.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:41:33 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/25 19:49:41 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_log_mouse_button_up(void *a1, void *a2)
{
	t_ui_main	*m;
	t_ui_win	*w;
	Uint32		windowID;

	m = (t_ui_main *)a1;
	windowID = *((Uint32 *)a2);
	w = ui_main_find_window_by_id(m, windowID);
	if (w != NULL)
	{
		SDL_Log("Mouse button %d UP on pixel (%d,%d) in win with ID=%d\n", m->sdl_event.button.button, m->ptr_pos.x, m->ptr_pos.y, windowID);
	}
}
