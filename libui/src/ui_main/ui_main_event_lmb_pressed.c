/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_event_lmb_pressed.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 05:05:29 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/12 05:05:34 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_event_lmb_pressed(t_ui_main *m, void *a)
{
	(void)a;
	m->params |= MAIN_LMB_PRESSED | MAIN_LMB_HOLD;
}
