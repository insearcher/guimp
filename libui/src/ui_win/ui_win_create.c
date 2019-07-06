/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:00:14 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/06 19:59:59 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_win_create(t_ui_win *w)
{
	if ((w->sdl_window = SDL_CreateWindow(w->title, w->pos.x,
		w->pos.y, w->size.x, w->size.y, 0)) == NULL)
		// ui_exit_with_msg(w, "libui: unable to create window"); // TODO
		;
	w->sdl_renderer = SDL_CreateRenderer(w->sdl_window, -1, SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC);
	w->sdl_windowID = SDL_GetWindowID(w->sdl_window);
	w->canvas->id = 0;
	w->canvas->sdl_renderer = w->sdl_renderer;
	w->canvas->rect = (t_rect){0, 0, w->size.x, w->size.y};
	w->canvas->cut_rect = w->canvas->rect;
	SDL_SetWindowResizable(w->sdl_window, (w->params) & WIN_RESIZABLE ? SDL_TRUE : SDL_FALSE);
	SDL_RaiseWindow(w->sdl_window);
}
