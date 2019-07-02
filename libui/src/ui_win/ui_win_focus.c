/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_focus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 02:27:11 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/02 09:07:18 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_win_focus_lost(void *a1, void *a2)
{
	t_ui_main   *m;

	m = (t_ui_main *)a1;
	(void)a2;
	m->raycaster->focused_win = NULL;
}

void	ui_win_focus_gained(void *a1, void *a2)
{
	t_ui_main   *m;
	t_ui_win    *w;

	m = (t_ui_main *)a1;
	w = (t_ui_win *)a2;
	m->raycaster->focused_win = w;
	m->focused_el = NULL;
}
