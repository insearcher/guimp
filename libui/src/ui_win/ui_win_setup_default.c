/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_setup_default.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 05:38:36 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/27 15:24:57 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_win_setup_default(t_ui_win *w)
{
	register int	i;

	i = SDL_SCANCODE_A;
	while (i <= SDL_SCANCODE_0)
	{
		ui_event_add_listener(w->events->onKeyDown[i], ui_win_change_text_in_focused_el);
		i++;
	}
	ui_event_add_listener(w->events->onKeyDown[SDL_SCANCODE_SPACE], ui_win_change_text_in_focused_el);
	ui_event_add_listener(w->events->onKeyDown[SDL_SCANCODE_BACKSPACE], ui_win_change_text_in_focused_el);
	ui_event_add_listener(w->events->onPointerMoved, ui_main_pointer_moved);
	ui_event_add_listener(w->events->onPointerLeftButtonPressed, ui_main_lmb_pressed);
	ui_event_add_listener(w->events->onPointerLeftButtonReleased, ui_main_lmb_released);
	ui_event_add_listener(w->events->onPointerRightButtonPressed, ui_main_rmb_pressed);
	ui_event_add_listener(w->events->onPointerRightButtonReleased, ui_main_rmb_released);
	ui_event_add_listener(w->events->onScrollUp, ui_main_scroll_up);
	ui_event_add_listener(w->events->onScrollDown, ui_main_scroll_down);
	ui_event_add_listener(w->events->onFocusGained, ui_win_focus_gained);
	ui_event_add_listener(w->events->onFocusGained, ui_log_window_focus_gained);
	ui_event_add_listener(w->events->onFocusLost, ui_win_focus_lost);
	ui_event_add_listener(w->events->onFocusLost, ui_log_window_focus_lost);
	ui_event_add_listener(w->events->onResize, ui_log_window_resized);
	ui_event_add_listener(w->events->onClose, ui_log_window_closed);
	ui_event_add_listener(w->events->onMoved, ui_log_window_moved);
	w->canvas->rect = (t_rect){0, 0, w->size.x, w->size.y};
	w->canvas->cut_rect = w->canvas->rect;
}
