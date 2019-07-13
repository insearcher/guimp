/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_event_switch_radio.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 07:50:40 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 09:20:03 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_el_event_switch_radio(t_ui_main *m, void *a)
{
	t_ui_el		*el;

	(void)m;
	el = (t_ui_el *) a;
	if (!(((t_ui_el *)el->children->content)->params & EL_IS_HIDDEN))
		((t_ui_el *)el->children->content)->params |= EL_IS_HIDDEN;
	else
		((t_ui_el *)el->children->content)->params &= ~EL_IS_HIDDEN;
	return (1);
}
