/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_handle_keyboard_event.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 07:49:09 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/02 07:11:48 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_handle_keyboard_event(t_ui_main *m)
{
	Uint32			windowID;
	t_ui_win		*win;
	t_ui_event		*event;

	windowID = m->sdl_event->window.windowID;
	if ((win = ui_main_find_window_by_sdl_id(m, windowID)) == NULL)
			return ;
	if (!(win->params & WIN_IS_READY))
		return ;
	event = NULL;
	SDL_Log("keycode: %d\n", m->sdl_event->key.keysym.scancode);
	if (m->sdl_event->window.type == SDL_KEYDOWN)
	{
		m->cur_keycode = m->sdl_event->key.keysym.scancode;
		event = win->events->onKeyDown[m->sdl_event->key.keysym.scancode];
	}
	else if (m->sdl_event->window.type == SDL_KEYUP)
		event = win->events->onKeyUp[m->sdl_event->key.keysym.scancode];
	if (event != NULL)
		ui_event_invoke(event, m, win);
}
