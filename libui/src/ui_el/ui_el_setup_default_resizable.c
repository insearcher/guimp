/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_setup_default_resizable.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 19:51:18 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/19 01:58:23 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_setup_default_resizable(t_ui_el *el)
{
	ui_event_add_listener(el->events->onResize, ui_el_default_resize);
}
