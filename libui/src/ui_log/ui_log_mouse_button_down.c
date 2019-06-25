/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_log_mouse_button_down.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:39:31 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/22 18:18:47 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_log_mouse_button_down(void *a1, void *a2)
{
	t_ui_main	*m;
	t_ui_win	*w;

	m = (t_ui_main *)a1;
	w = (t_ui_win *)a2;
	if (w != NULL)
	{
		SDL_Log("Mouse button %d DOWN on pixel (%d,%d) in win with ID=%d\n",
				m->sdl_event->button.button,
				m->ptr_pos.x,
				m->ptr_pos.y,
				w->id);
	}
}
