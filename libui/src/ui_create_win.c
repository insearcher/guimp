/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_create_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 02:16:36 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/16 22:17:50 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_create_win(const char *name, t_env *e)
{
	if (!(e->sdl.win = SDL_CreateWindow(name,
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_W, WIN_H, 0)))
		ui_exit_with_msg("libui: unable to create window", e);
	SDL_RaiseWindow(e->sdl.win);
	if (!(e->sdl.ren = SDL_CreateRenderer(e->sdl.win, -1,
	SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_SOFTWARE)))
		ui_exit_with_msg("libui: unable to create renderer", e);
	if (!(e->sur = ui_create_sur(WIN_H, WIN_W)))
		ui_exit_with_msg("libui: unable to create surface", e);
}
