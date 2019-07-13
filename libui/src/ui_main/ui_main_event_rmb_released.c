/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_event_rmb_released.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 05:08:23 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 09:23:16 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_main_event_rmb_released(t_ui_main *m, void *a)
{
	(void)a;
	m->params &= ~MAIN_RMB_HOLD;
	m->params |= MAIN_RMB_RELEASED;
	return (1);
}
