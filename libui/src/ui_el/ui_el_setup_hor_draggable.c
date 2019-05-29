/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_setup_hor_draggable.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:52:20 by edraugr-          #+#    #+#             */
/*   Updated: 2019/05/23 15:53:18 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_setup_hor_draggable(t_ui_el *el)
{
	ui_event_add_listener(&(el->events.onPointerLeftButtonHold),
		&ui_el_hor_slider_drug);
}
