/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_menu_resize.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 20:22:08 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/01 20:24:00 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_set_menu_resize(t_ui_el *el)
{
	ui_event_add_listener(&(el->events.onResize), &ui_el_menu_resize);
}
