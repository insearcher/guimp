/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_setup_default_draggable.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:14:47 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/25 20:17:43 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_setup_default_draggable(t_ui_el *el)
{
	el->params |= EL_IS_SCROLLABLE;
	ui_event_add_listener(&(el->events.onPointerLeftButtonPressed), &ui_el_begin_drag);
	ui_event_add_listener(&(el->events.onPointerLeftButtonHold), &ui_el_drag);
	ui_event_add_listener(&(el->events.onPointerLeftButtonReleased), &ui_el_end_drag);
}
