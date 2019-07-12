/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_event_default_pointer_enter.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 04:45:00 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/12 10:35:17 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_event_default_pointer_enter(t_ui_main *m, void *a)
{
	t_ui_el		*el;

	(void)m;
	el = (t_ui_el *)a;
	el->params |= EL_IS_PTR_INSIDE;
}
