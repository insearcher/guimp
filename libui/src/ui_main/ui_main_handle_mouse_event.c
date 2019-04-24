/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_handle_mouse_event.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:47:51 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/24 16:50:19 by sbednar          ###   ########.fr       */
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
		event = &(win->events.onPointerMoved);
	else if (m->sdl_event.type == SDL_MOUSEBUTTONDOWN && m->sdl_event.button.button == SDL_BUTTON_LEFT)
		event = &(win->events.onPointerLeftButtonPressed);
	else if (m->sdl_event.type == SDL_MOUSEBUTTONDOWN && m->sdl_event.button.button == SDL_BUTTON_RIGHT)
		event = &(win->events.onPointerRightButtonPressed);
	else if (m->sdl_event.type == SDL_MOUSEBUTTONUP && m->sdl_event.button.button == SDL_BUTTON_LEFT)
		event = &(win->events.onPointerLeftButtonReleased);
	else if (m->sdl_event.type == SDL_MOUSEBUTTONUP && m->sdl_event.button.button == SDL_BUTTON_RIGHT)
		event = &(win->events.onPointerRightButtonReleased);
	else if (m->sdl_event.type == SDL_MOUSEWHEEL)
	{
		if (m->sdl_event.wheel.y > 0)
			event = &(win->events.onScrollUp);
		else if (m->sdl_event.wheel.y < 0)
			event = &(win->events.onScrollDown);
	}
	if (event != NULL)
		ui_event_invoke(event, m, &windowID);
}
