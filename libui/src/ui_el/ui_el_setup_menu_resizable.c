/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_setup_menu_resizable.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 20:22:08 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/18 20:07:53 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_setup_menu_resizable(t_ui_el *el)
{
	ui_event_add_listener(&(el->events.onResize), &ui_el_menu_resize);
}
