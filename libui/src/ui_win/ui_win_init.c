/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:57:36 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/19 01:55:20 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_ui_win	*ui_win_init(void)
{
	t_ui_win	*win;

	if (!(win = (t_ui_win *)malloc(sizeof(t_ui_win))))
		ui_sdl_deinit(228);
	ft_bzero(win, sizeof(t_ui_win));
	if (!(win->canvas = ui_el_init()))
		ui_sdl_deinit(228);
	if (!(win->events = ui_win_events_init()))
		ui_sdl_deinit(228);
	return (win);
}
