/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:00:14 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/19 01:24:28 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_win_create(t_ui_win *w)
{
	if ((w->sdl_window = SDL_CreateWindow(w->title, w->pos.x,
		w->pos.y, w->size.x, w->size.y, 0)) == NULL)
		// ui_exit_with_msg(w, "libui: unable to create window"); // TODO
		;
	w->sdl_renderer = SDL_CreateRenderer(w->sdl_window, -1, 0);
	w->sdl_windowID = SDL_GetWindowID(w->sdl_window);
	w->canvas->id = 0;
	w->canvas->sdl_renderer = w->sdl_renderer;
	SDL_SetWindowResizable(w->sdl_window, (w->params) & WIN_RESIZABLE ? SDL_TRUE : SDL_FALSE);
	SDL_RaiseWindow(w->sdl_window);
}
