/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_log_mouse_button_down.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:39:31 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/12 03:33:50 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_log_mouse_button_down(t_ui_main *m, void *a)
{
	t_ui_win	*w;

	w = (t_ui_win *)a;
	if (w != NULL)
	{
		SDL_Log("Mouse button %d DOWN on pixel (%d,%d) in win with ID=%d\n",
				m->sdl_event->button.button,
				m->ptr_pos.x,
				m->ptr_pos.y,
				w->id);
	}
}
