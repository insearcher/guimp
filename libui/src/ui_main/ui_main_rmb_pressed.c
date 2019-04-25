/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_rmb_pressed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:38:59 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/25 18:39:20 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_rmb_pressed(void *a1, void *a2)
{
	t_ui_main	*m;

	m = (t_ui_main *)a1;
	(void)a2;
	m->params |= MAIN_RMB_PRESSED | MAIN_RMB_HOLD;
}
