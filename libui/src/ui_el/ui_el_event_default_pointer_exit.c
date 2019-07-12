/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_event_default_pointer_exit.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 04:45:09 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/12 10:35:33 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_event_default_pointer_exit(t_ui_main *m, void *a)
{
	t_ui_el		*el;

	(void)m;
	el = (t_ui_el *)a;
	el->params &= ~(EL_IS_PTR_INSIDE);
}
