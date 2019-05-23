/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_setup_default.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 05:38:36 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/23 11:52:32 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_win_setup_default(t_ui_win *w)
{
	ui_event_add_listener(&(w->events.onPointerMoved), &ui_main_pointer_moved);
	ui_event_add_listener(&(w->events.onPointerLeftButtonPressed), &ui_main_lmb_pressed);
	ui_event_add_listener(&(w->events.onPointerLeftButtonReleased), &ui_main_lmb_released);
	ui_event_add_listener(&(w->events.onPointerRightButtonPressed), &ui_main_rmb_pressed);
	ui_event_add_listener(&(w->events.onPointerRightButtonReleased), &ui_main_rmb_released);
	ui_event_add_listener(&(w->events.onScrollUp), &ui_main_scroll_up);
	ui_event_add_listener(&(w->events.onScrollDown), &ui_main_scroll_down);
	ui_event_add_listener(&(w->events.onFocusGained), &ui_log_window_focus_gained);
	ui_event_add_listener(&(w->events.onFocusLost), &ui_log_window_focus_lost);
	ui_event_add_listener(&(w->events.onResize), &ui_log_window_resized);
	ui_event_add_listener(&(w->events.onKeyDown[SDL_SCANCODE_ESCAPE]), &ui_log_window_closed);
	ui_event_add_listener(&(w->events.onClose), &ui_log_window_closed);
	w->canvas.rect = (t_rect){0, 0, w->size.x, w->size.y};
}
