/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_setup_default_draggable.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 19:49:49 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/12 10:44:39 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_setup_default_draggable(t_ui_el *el)
{
	ui_event_add_listener(el->events->onPointerLeftButtonHold, ui_el_event_drag);
}
