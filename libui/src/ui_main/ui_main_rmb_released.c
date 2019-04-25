/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_rmb_released.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:39:05 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/24 17:07:34 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_rmb_released(void *a1, void *a2)
{
	t_ui_main	*m;

	m = (t_ui_main *)a1;
	(void)a2;
	m->params &= ~MAIN_RMB_HOLD;
	m->params |= MAIN_RMB_RELEASED;
}
