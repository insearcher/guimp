/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_setup_default_scroll_menu_elem.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 21:40:00 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/12 10:48:43 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_setup_default_scroll_menu_elem(t_ui_el *el)
{
	el->params |= EL_IS_SCROLLABLE;
	el->params |= EL_IS_DEPENDENT;
	ui_event_add_listener(el->events->onScrollUp, ui_el_event_scroll_child_menu_up);
	ui_event_add_listener(el->events->onScrollDown, ui_el_event_scroll_child_menu_down);
#ifdef DEBUG_STATUS
	ui_event_add_listener(el->events->onScrollUp, ui_log_el_scroll_up);
	ui_event_add_listener(el->events->onScrollDown, ui_log_el_scroll_down);
#endif
}
