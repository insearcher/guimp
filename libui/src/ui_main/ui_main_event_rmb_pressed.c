/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_event_rmb_pressed.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 05:08:10 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 05:59:35 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_event_rmb_pressed(t_ui_main *m, void *a)
{
	(void)a;
	m->params |= MAIN_RMB_PRESSED | MAIN_RMB_HOLD;
}
