/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_setup_default.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 05:50:32 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/15 05:51:08 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_setup_default(t_ui_el *el)
{
	ui_event_add_listener(&(el->events.onPointerEnter), &ui_log_el_pointer_enter);
	ui_event_add_listener(&(el->events.onPointerEnter), &ui_el_default_pointer_enter);
	ui_event_add_listener(&(el->events.onPointerExit), &ui_log_el_pointer_exit);
	ui_event_add_listener(&(el->events.onPointerExit), &ui_el_default_pointer_exit);
	ui_event_add_listener(&(el->events.onPointerStay), &ui_log_el_pointer_stay);
}
