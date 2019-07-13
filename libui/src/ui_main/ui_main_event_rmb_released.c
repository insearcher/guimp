/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_event_rmb_released.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 05:08:23 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 05:59:50 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_event_rmb_released(t_ui_main *m, void *a)
{
	(void)a;
	m->params &= ~MAIN_RMB_HOLD;
	m->params |= MAIN_RMB_RELEASED;
}
