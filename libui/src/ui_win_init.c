/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:57:36 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/29 22:31:49 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_win_init(t_ui_win *w)
{
	ft_bzero(w, sizeof(t_ui_win));
	w->sdl_window = NULL;
	w->sdl_surface = NULL;
	w->sdl_event = NULL;
	w->title = NULL;
}
