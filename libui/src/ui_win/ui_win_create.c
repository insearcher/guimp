/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:00:14 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/23 05:24:09 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_win_create(t_ui_win *w)
{
	if ((w->sdl_window = SDL_CreateWindow(w->title, SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, w->size.x, w->size.y,
		0)) == NULL)
		// ui_exit_with_msg(w, "libui: unable to create window"); // TODO
		;
	w->sdl_renderer = SDL_CreateRenderer(w->sdl_window, -1, 0);
	w->sdl_windowID = SDL_GetWindowID(w->sdl_window);
	SDL_SetWindowResizable(w->sdl_window, (w->params) & WIN_RESIZABLE ? SDL_TRUE : SDL_FALSE);
	SDL_RaiseWindow(w->sdl_window);
}
