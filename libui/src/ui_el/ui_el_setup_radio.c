/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_setup_radio.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:46:25 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/11 19:54:28 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_setup_radio(t_ui_el *el)
{
	ui_event_add_listener(el->events->onPointerLeftButtonPressed, ui_el_switch_radio);
}