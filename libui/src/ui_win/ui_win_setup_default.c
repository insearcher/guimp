/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_setup_default.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 05:38:36 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/12 05:55:07 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_win_setup_default(t_ui_win *w)
{
	register int	i;

	i = SDL_SCANCODE_A - 1;
	while (++i <= SDL_SCANCODE_0)
		ui_event_add_listener(w->events->onKeyDown[i], ui_win_event_change_text_in_focused_el);
	ui_event_add_listener(w->events->onKeyDown[SDL_SCANCODE_SPACE], ui_win_event_change_text_in_focused_el);
	ui_event_add_listener(w->events->onKeyDown[SDL_SCANCODE_BACKSPACE], ui_win_event_change_text_in_focused_el);
	ui_event_add_listener(w->events->onPointerMoved, ui_main_event_pointer_moved);
	ui_event_add_listener(w->events->onPointerLeftButtonPressed, ui_main_event_lmb_pressed);
	ui_event_add_listener(w->events->onPointerLeftButtonReleased, ui_main_event_lmb_released);
	ui_event_add_listener(w->events->onPointerRightButtonPressed, ui_main_event_rmb_pressed);
	ui_event_add_listener(w->events->onPointerRightButtonReleased, ui_main_event_rmb_released);
	ui_event_add_listener(w->events->onScrollUp, ui_main_event_scroll_up);
	ui_event_add_listener(w->events->onScrollDown, ui_main_event_scroll_down);
	ui_event_add_listener(w->events->onFocusGained, ui_win_event_focus_gained);
	ui_event_add_listener(w->events->onFocusLost, ui_win_event_focus_lost);
	ui_event_add_listener(w->events->onFocusLost, ui_main_event_lmb_released);
	ui_event_add_listener(w->events->onFocusLost, ui_main_event_rmb_released);

#ifdef DEBUG_STATUS
	ui_event_add_listener(w->events->onFocusLost, ui_log_window_focus_lost);
	ui_event_add_listener(w->events->onFocusGained, ui_log_window_focus_gained);
	ui_event_add_listener(w->events->onResize, ui_log_window_resized);
	ui_event_add_listener(w->events->onClose, ui_log_window_closed);
	ui_event_add_listener(w->events->onMoved, ui_log_window_moved);
#endif
}
