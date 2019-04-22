/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_setup_default.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 05:38:36 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/22 05:58:47 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_win_setup_default(t_ui_win *w)
{
	// ui_event_add_listener(&(w->events.onMouseMoved), &ui_log_mouse_motion);
	// ui_event_add_listener(&(w->events.onMouseButtonDown), &ui_log_mouse_button_down);
	// ui_event_add_listener(&(w->events.onMouseButtonUp), &ui_log_mouse_button_up);
	ui_event_add_listener(&(w->events.onFocusGained), &ui_log_window_focus_gained);
	ui_event_add_listener(&(w->events.onFocusLost), &ui_log_window_focus_lost);
	ui_event_add_listener(&(w->events.onResize), &ui_log_window_resized);
	ui_event_add_listener(&(w->events.onClose), &ui_log_window_closed);
	w->canvas.rect = (t_rect){0, 0, w->size.x, w->size.y};
	w->canvas.frect = (t_frect){0, 0, 1, 1};
}
