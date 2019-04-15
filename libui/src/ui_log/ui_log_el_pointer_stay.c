/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_log_el_pointer_stay.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 06:10:29 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/15 00:48:17 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_log_el_pointer_stay(void *a1, void *a2)
{
	t_ui_main	*m;
	t_ui_el		*el;

	m = (t_ui_main *)a1;
	el = (t_ui_el *)a2;
	SDL_Log("Pointer stay at position (%d,%d) in element ID=%d in window ID=%d\n", m->sdl_event.motion.x, m->sdl_event.motion.y, el->id, m->sdl_event.window.windowID);
}
