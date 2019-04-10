/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_handle_event.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 22:13:11 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/10 13:06:05 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void	ui_main_handle_raycast_mouse_l_button(t_ui_main *m, t_ui_el *cur)
{
	if (cur != NULL && m->sdl_event.button.button == SDL_BUTTON_LEFT)
	{
		if (m->sdl_event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (cur->l_butt_status == BUTTON_OFF)
			{
				ui_event_invoke(&(cur->events.onPointerLeftButtonPressed),
					m, cur);
				cur->l_butt_status = BUTTON_ON;
			}
			else
				ui_event_invoke(&(cur->events.onPointerLeftButtonHold), m, cur);
		}
		if (m->sdl_event.type == SDL_MOUSEBUTTONUP)
		{
			ui_event_invoke(&(cur->events.onPointerLeftButtonReleased), m, cur);
			cur->l_butt_status = BUTTON_OFF;
		}
	}
}

static void	ui_main_handle_raycast_mouse_r_button(t_ui_main *m, t_ui_el *cur)
{
	if (cur != NULL && m->sdl_event.button.button == SDL_BUTTON_RIGHT)
	{
		if (m->sdl_event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (cur->r_butt_status == BUTTON_OFF)
			{
				ui_event_invoke(&(cur->events.onPointerRightButtonPressed),
					m, cur);
				cur->r_butt_status = BUTTON_ON;
			}
			else
				ui_event_invoke(&(cur->events.onPointerRightButtonHold),
					m, cur);
		}
		if (m->sdl_event.type == SDL_MOUSEBUTTONUP)
		{
			ui_event_invoke(&(cur->events.onPointerRightButtonReleased),
				m, cur);
			cur->r_butt_status = BUTTON_OFF;
		}
	}
}

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
	if (prev == NULL && cur != NULL) //e
	{
		ui_event_invoke(&(cur->events.onPointerEnter), m, cur);
		m->raycaster.selected = cur;
	}
	if (cur == NULL && prev != NULL) //e
	{
		ui_event_invoke(&(prev->events.onPointerExit), m, prev);
		m->raycaster.selected = NULL;
	}
	if (cur != NULL) //e
	{
		ui_event_invoke(&(cur->events.onPointerStay), m, cur);
	}
	ui_main_handle_raycast_mouse_l_button(m, cur);
	ui_main_handle_raycast_mouse_r_button(m, cur);
}

void	ui_main_handle_event(t_ui_main *m)
{
	if (m->sdl_event.type == SDL_MOUSEMOTION ||
		m->sdl_event.type == SDL_MOUSEBUTTONDOWN ||
		m->sdl_event.type ==  SDL_MOUSEBUTTONUP)
		ui_main_handle_mouse_event(m);
	if (m->sdl_event.type == SDL_KEYDOWN || //else
		m->sdl_event.type == SDL_KEYUP)
		ui_main_handle_keyboard_event(m);
	if (m->sdl_event.type == SDL_WINDOWEVENT) //else
		ui_main_handle_window_event(m);
	ui_main_handle_raycast(m);
}
