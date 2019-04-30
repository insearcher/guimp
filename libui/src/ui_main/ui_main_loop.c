/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:26:26 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/30 17:21:01 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int	ui_main_loop_non_sdl(void *d)
{
	t_ui_main	*m;

	m = (t_ui_main *)d;
	while (1)
	{
		if (m->params & MAIN_ON_QUIT)
			return (1);
		ui_main_handle_raycast(m);
		ui_draw(m);
		SDL_Delay((Uint32)(1000.0f / FPS));
	}
	return (0);
}

void		ui_main_loop(t_ui_main *m)
{
	SDL_Thread	*thread;

	thread = SDL_CreateThread(ui_main_loop_non_sdl, "ui_main_loop_non_sdl", (void *)m);
	SDL_DetachThread(thread);
	m->target_tick = 0;
	while (1)
	{
		m->cur_tick = SDL_GetTicks();
		if (SDL_PollEvent(&(m->sdl_event)))
			ui_main_handle_event(m);
	}
}
