/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_default_draggable.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 19:49:49 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/01 19:49:59 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_set_default_draggable(t_ui_el *el)
{
	ui_event_add_listener(&(el->events.onPointerLeftButtonHold), &ui_el_drag);
}
