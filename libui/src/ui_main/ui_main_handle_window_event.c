/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_handle_window_event.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 02:19:12 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/21 09:08:11 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_handle_window_event(t_ui_main *m)
{
	Uint32		windowID;
	t_ui_win	*win;
	t_ui_event	*event;

	windowID = m->sdl_event.window.windowID;
	if ((win = ui_main_find_window_by_id(m, windowID)) == NULL)
		return ;
	event = NULL;
	if (m->sdl_event.window.event == SDL_WINDOWEVENT_CLOSE)
		event = &(win->events.onClose);
	else if (m->sdl_event.window.event == SDL_WINDOWEVENT_RESIZED)
		event = &(win->events.onResize);
	else if (m->sdl_event.window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
		event = &(win->events.onFocusGained);
	else if (m->sdl_event.window.event == SDL_WINDOWEVENT_FOCUS_LOST)
		event = &(win->events.onFocusLost);
	if (event != NULL)
		ui_event_invoke(event, m, &windowID);
}
