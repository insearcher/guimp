/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_create_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 02:16:36 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/17 05:09:55 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_create_win(t_env *e, const char *name)
{
	if (!(e->sdl.win = SDL_CreateWindow(name,
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, e->w, e->h, 0)))
		ui_exit_with_msg(e, "libui: unable to create window");
	SDL_RaiseWindow(e->sdl.win);
	if (!(e->sdl.ren = SDL_CreateRenderer(e->sdl.win, -1,
	SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_SOFTWARE)))
		ui_exit_with_msg(e, "libui: unable to create renderer");
	if (!(e->sur = ui_create_sur(e->w, e->h)))
		ui_exit_with_msg(e, "libui: unable to create surface");
}
