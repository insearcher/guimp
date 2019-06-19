/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_focus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 02:27:11 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/19 02:30:45 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_win_focus_lost(void *a1, void *a2)
{
	t_ui_main   *m;

	m = (t_ui_main *)a1;
	(void)a2;
	m->raycaster->selected_win = NULL;
}

void	ui_win_focus_gained(void *a1, void *a2)
{
	t_ui_main   *m;
	t_ui_win    *w;

	m = (t_ui_main *)a1;
	w = (t_ui_win *)a2;
	m->raycaster->selected_win = w;
}