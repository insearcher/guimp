/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_handle_continious_event.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 00:45:47 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/22 08:29:26 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_handle_continious_event(t_ui_main *m, t_ui_el *el)
{
	if (el == NULL)
		return ;
	if (el->params & EL_IS_PTR_INSIDE)
		ui_event_invoke(&(el->events.onPointerStay), m, el);
	if (el->params & EL_IS_LMB_PRESSED)
		ui_event_invoke(&(el->events.onPointerLeftButtonHold), m, el);
	if (el->params & EL_IS_RMB_PRESSED)
		ui_event_invoke(&(el->events.onPointerRightButtonHold), m, el);
	el->ptr_rel_pos.x = ui_get_mouse_el_pos_x(m);
	el->ptr_rel_pos.y = ui_get_mouse_el_pos_y(m);
}
