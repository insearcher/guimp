/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_setup_horizontal_draggable.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:52:20 by edraugr-          #+#    #+#             */
/*   Updated: 2019/06/18 20:07:20 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_setup_horizontal_draggable(t_ui_el *el)
{
	ui_event_add_listener(&(el->events.onPointerLeftButtonHold),
		&ui_el_hor_slider_drug);
}
