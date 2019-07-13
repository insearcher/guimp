/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_setup_menu_resizable.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 20:22:08 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/12 10:32:57 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_setup_menu_resizable(t_ui_el *el)
{
	ui_event_add_listener(el->events->onResize, ui_el_event_menu_resize);
}
