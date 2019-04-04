/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_handle_event.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 22:13:11 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/04 07:55:52 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void	ui_main_handle_raycast(t_ui_main *m)
{
	t_ui_el		*prev;
	t_ui_el		*cur;

	prev = m->raycaster.selected;
	cur = ui_raycast(m, m->sdl_event.window.windowID);
	if (prev != NULL && cur != NULL && prev->id != cur->id)
	{
		ui_event_invoke(&(prev->events.onPointerExit), m, prev);
		ui_event_invoke(&(cur->events.onPointerEnter), m, cur);
		m->raycaster.selected = cur;
	}
	else if (prev == NULL && cur != NULL)
	{
		ui_event_invoke(&(cur->events.onPointerEnter), m, cur);
		m->raycaster.selected = cur;
	}
	else if (cur == NULL && prev != NULL)
	{
		ui_event_invoke(&(prev->events.onPointerExit), m, prev);
		m->raycaster.selected = NULL;
	}
	else if (cur != NULL)
	{
		ui_event_invoke(&(cur->events.onPointerStay), m, cur);
	}
}

void	ui_main_handle_event(t_ui_main *m)
{
	if (m->sdl_event.type == SDL_MOUSEMOTION ||
		m->sdl_event.type == SDL_MOUSEBUTTONDOWN ||
		m->sdl_event.type ==  SDL_MOUSEBUTTONUP)
		ui_main_handle_mouse_event(m);
	else if (m->sdl_event.type == SDL_KEYDOWN ||
		m->sdl_event.type == SDL_KEYUP)
		ui_main_handle_keyboard_event(m);
	else if (m->sdl_event.type == SDL_WINDOWEVENT)
		ui_main_handle_window_event(m);
	ui_main_handle_raycast(m);
}
