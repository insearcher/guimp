/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_setup_default_scrollable.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:47:25 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/25 20:48:33 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_setup_default_scrollable(t_ui_el *el)
{
	el->params |= EL_IS_SCROLLABLE;
	ui_event_add_listener(&(el->events.onScrollUp), ui_log_el_scroll_up);
	ui_event_add_listener(&(el->events.onScrollDown), ui_log_el_scroll_down);
}

