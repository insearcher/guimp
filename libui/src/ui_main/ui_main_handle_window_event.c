/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_handle_window_event.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 02:19:12 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/22 20:03:56 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_handle_window_event(t_ui_main *m)
{
	Uint32		windowID;
	t_ui_win	*win;
	t_ui_event	*event;

	windowID = m->sdl_event->window.windowID;
	if ((win = ui_main_find_window_by_sdl_id(m, windowID)) == NULL)
		return ;
	event = NULL;
	if (m->sdl_event->window.event == SDL_WINDOWEVENT_CLOSE)
		event = win->events->onClose;
//	else if (m->sdl_event->window.event == SDL_WINDOWEVENT_RESIZED)
	else if (m->sdl_event->window.event == SDL_WINDOWEVENT_ENTER)
		event = win->events->onPointerEnter;
	else if (m->sdl_event->window.event == SDL_WINDOWEVENT_LEAVE)
		event = win->events->onPointerExit;
	else if (m->sdl_event->window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
		event = win->events->onResize;
	else if (m->sdl_event->window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
		event = win->events->onFocusGained;
	else if (m->sdl_event->window.event == SDL_WINDOWEVENT_FOCUS_LOST)
		event = win->events->onFocusLost;
	else if (m->sdl_event->window.event == SDL_WINDOWEVENT_MOVED)
		event = win->events->onMoved;
	if (event != NULL)
		ui_event_invoke(event, m, win);
}
