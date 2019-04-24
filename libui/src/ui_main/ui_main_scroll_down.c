/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_scroll_down.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:39:30 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/24 16:39:50 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_scroll_down(void *a1, void *a2)
{
	t_ui_main	*m;

	m = (t_ui_main *)a1;
	(void)a2;
	m->params |= MAIN_SCROLL_DOWN;
}
