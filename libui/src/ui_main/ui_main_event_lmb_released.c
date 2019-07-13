/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_event_lmb_released.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 05:06:57 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 09:21:19 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_main_event_lmb_released(t_ui_main *m, void *a)
{
	(void)a;
	m->params &= ~MAIN_LMB_HOLD;
	m->params |= MAIN_LMB_RELEASED;
	return (1);
}
