/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_event_lmb_released.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 05:06:57 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/12 05:07:00 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_event_lmb_released(t_ui_main *m, void *a)
{
	(void)a;
	m->params &= ~MAIN_LMB_HOLD;
	m->params |= MAIN_LMB_RELEASED;
}
