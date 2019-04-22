/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_handle_raycast.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 00:43:05 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/22 07:29:30 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_handle_raycast(t_ui_main *m)
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
	if (prev == NULL && cur != NULL)
	{
		ui_event_invoke(&(cur->events.onPointerEnter), m, cur);
		m->raycaster.selected = cur;
	}
	if (cur == NULL && prev != NULL)
	{
		ui_event_invoke(&(prev->events.onPointerExit), m, prev);
		m->raycaster.selected = NULL;
	}

	if (cur != NULL)
	{
		if (m->sdl_event.button.button == SDL_BUTTON_LEFT)
		{
			if (m->sdl_event.type == SDL_MOUSEBUTTONDOWN && !(cur->params & EL_IS_LMB_PRESSED))
			{
				ui_event_invoke(&(cur->events.onPointerLeftButtonPressed), m, cur);
				cur->params |= EL_IS_LMB_PRESSED | EL_NOT_RELEASED;
			}
			else if (m->sdl_event.type == SDL_MOUSEBUTTONUP && cur->params & EL_NOT_RELEASED)
			{
				ui_event_invoke(&(cur->events.onPointerLeftButtonReleased), m, cur);
				cur->params &= ~(EL_IS_LMB_PRESSED | EL_NOT_RELEASED);
			}
		}
		if (m->sdl_event.button.button == SDL_BUTTON_RIGHT)
		{
			if (m->sdl_event.type == SDL_MOUSEBUTTONDOWN && !(cur->params & EL_IS_RMB_PRESSED))
			{
				ui_event_invoke(&(cur->events.onPointerRightButtonPressed), m, cur);
				cur->params |= EL_IS_RMB_PRESSED | EL_NOT_RELEASED;
			}
			else if (m->sdl_event.type == SDL_MOUSEBUTTONUP && cur->params & EL_NOT_RELEASED)
			{
				ui_event_invoke(&(cur->events.onPointerRightButtonReleased), m, cur);
				cur->params &= ~(EL_IS_LMB_PRESSED | EL_NOT_RELEASED);
			}
		}
		if (cur->params & EL_IS_SCROLLABLE && m->sdl_event.type == SDL_MOUSEWHEEL)
		{
			if (m->sdl_event.wheel.y > 0)
				ui_event_invoke(&(cur->events.onScrollDown), m, cur);
			if (m->sdl_event.wheel.y < 0)
				ui_event_invoke(&(cur->events.onScrollUp), m, cur);
		}
	}
	ui_main_handle_continious_event(m, cur);
}
