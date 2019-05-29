/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_setup_default_scroll_menu_elem.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 21:40:00 by sbecker           #+#    #+#             */
/*   Updated: 2019/05/24 08:45:52 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_setup_default_scroll_menu_elem(t_ui_el *el, t_ui_el *el_parent)
{
	ui_el_setup_default(el);
	el->params |= EL_IS_SCROLLABLE;
	el->params |= EL_IS_DEPENDENT;
	ui_event_add_listener(&(el->events.onScrollUp), ui_el_scroll_child_menu_up);
	ui_event_add_listener(&(el->events.onScrollUp), ui_log_el_scroll_up);
	ui_event_add_listener(&(el->events.onScrollDown), ui_el_scroll_child_menu_down);
	ui_event_add_listener(&(el->events.onScrollDown), ui_log_el_scroll_down);
	ui_el_add_child(el_parent, el);
}
