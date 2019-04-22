/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_handle_mouse_event.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:47:51 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/22 05:00:27 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_handle_mouse_event(t_ui_main *m)
{
	Uint32		windowID;
	t_ui_win	*win;
	t_ui_event	*event;

	windowID = m->sdl_event.window.windowID;
	if (windowID == 0)
		return ;
	if ((win = ui_main_find_window_by_id(m, windowID)) == NULL)
	{
		SDL_Log("Window with id %d is not presented in main\n", windowID);
		ui_sdl_deinit(EXIT_FAILURE);
		// return ; // TODO: FIX
	}
	event = NULL;
	if (m->sdl_event.type == SDL_MOUSEMOTION)
		event = &(win->events.onMouseMoved);
	if (m->sdl_event.type == SDL_MOUSEBUTTONDOWN)
		event = &(win->events.onMouseButtonDown);
	if (m->sdl_event.type == SDL_MOUSEBUTTONUP)
		event = &(win->events.onMouseButtonUp);
	if (m->sdl_event.type == SDL_MOUSEWHEEL)
	{
		if (m->sdl_event.wheel.y > 0)
			event = &(win->events.onScrollUp);
		else if (m->sdl_event.wheel.y < 0)
			event = &(win->events.onScrollDown);
	}
	if (event != NULL)
		ui_event_invoke(event, m, &windowID);
}
