/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_event_focus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 05:55:32 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/12 10:52:55 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_win_event_focus_lost(t_ui_main *m, void *a)
{
	(void)a;
	m->raycaster->focused_win = NULL;
}

void	ui_win_event_focus_gained(t_ui_main *m, void *a)
{
	t_ui_win    *w;

	w = (t_ui_win *)a;
	m->raycaster->focused_win = w;
	m->focused_el = NULL;
}
