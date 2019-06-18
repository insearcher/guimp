/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_handle_continious_event.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 00:45:47 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/19 02:01:04 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int	ui_get_mouse_el_pos_x(t_ui_main *m)
{
	if (m->raycaster->selected == NULL)
		return (-1);
	return (m->ptr_pos.x - m->raycaster->selected->rect.x);
}

static int	ui_get_mouse_el_pos_y(t_ui_main *m)
{
	if (m->raycaster->selected == NULL)
		return (-1);
	return (m->ptr_pos.y - m->raycaster->selected->rect.y);
}

void	ui_main_handle_continious_event(t_ui_main *m, t_ui_el *el)
{
	if (el == NULL)
		return ;
	if (el->params & EL_IS_PTR_INSIDE)
		ui_event_invoke(el->events->onPointerStay, m, el);
	if (m->params & MAIN_LMB_HOLD)
		ui_event_invoke(el->events->onPointerLeftButtonHold, m, el);
	if (m->params & MAIN_RMB_HOLD)
		ui_event_invoke(el->events->onPointerRightButtonHold, m, el);
	el->ptr_rel_pos.x = ui_get_mouse_el_pos_x(m);
	el->ptr_rel_pos.y = ui_get_mouse_el_pos_y(m);
}
