/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_handle_continious_event.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 00:45:47 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/22 05:34:24 by sbednar          ###   ########.fr       */
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
}
