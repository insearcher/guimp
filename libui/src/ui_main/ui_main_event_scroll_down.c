/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_event_scroll_down.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 05:09:28 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 06:00:23 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_event_scroll_down(t_ui_main *m, void *a)
{
	(void)a;
	m->params |= MAIN_SCROLL_DOWN;
}
