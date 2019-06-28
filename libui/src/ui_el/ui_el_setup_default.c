/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_setup_default.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 05:50:32 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/27 15:24:57 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_setup_default(t_ui_el *el)
{
	el->current_texture = ft_strhash("default");
	ui_event_add_listener(el->events->onRender, ui_el_draw_event);
	ui_event_add_listener(el->events->onPointerEnter, ui_el_default_pointer_enter);
	ui_event_add_listener(el->events->onPointerExit, ui_el_default_pointer_exit);
	if (DEBUG_STATUS == 1)
	{
		ui_event_add_listener(el->events->onPointerEnter, ui_log_el_pointer_enter);
		ui_event_add_listener(el->events->onPointerExit, ui_log_el_pointer_exit);
		ui_event_add_listener(el->events->onPointerStay, ui_log_el_pointer_stay);
		ui_event_add_listener(el->events->onPointerLeftButtonHold, ui_log_el_left_button_hold);
		ui_event_add_listener(el->events->onPointerLeftButtonPressed, ui_log_el_left_button_pressed);
		ui_event_add_listener(el->events->onPointerLeftButtonReleased, ui_log_el_left_button_released);
		ui_event_add_listener(el->events->onPointerRightButtonHold, ui_log_el_right_button_hold);
		ui_event_add_listener(el->events->onPointerRightButtonPressed, ui_log_el_right_button_pressed);
		ui_event_add_listener(el->events->onPointerRightButtonReleased, ui_log_el_right_button_released);
	}
}
