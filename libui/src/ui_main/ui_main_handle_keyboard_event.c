/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_handle_keyboard_event.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 07:49:09 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/04 08:07:59 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_handle_keyboard_event(t_ui_main *m)
{
	Uint32		windowID;
	t_ui_win	*win;
	t_ui_event	*event;

	windowID = m->sdl_event.window.windowID;
	if ((win = ui_main_find_window_by_id(m, windowID)) == NULL)
	{
		SDL_Log("Window with id %d is not presented in main\n", windowID);
		ui_sdl_deinit(EXIT_FAILURE);
		return ; // TODO: FIX
	}
	event = NULL;
	if (m->sdl_event.window.type == SDL_KEYDOWN && !m->sdl_event.key.repeat)
		event = &(win->events.onKeyDown[m->sdl_event.key.keysym.scancode]);
	else if (m->sdl_event.window.type == SDL_KEYUP)
		event = &(win->events.onKeyUp[m->sdl_event.key.keysym.scancode]);
	if (event != NULL)
		ui_event_invoke(event, m, &windowID);
}