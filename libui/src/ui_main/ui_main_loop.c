/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:26:26 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/01 00:20:08 by sbecker          ###   ########.fr       */
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
//		SDL_Delay((Uint32)(100.0f / FPS));
	}
	return (0);
}

void		ui_main_loop(t_ui_main *m)
{
	SDL_Thread	*thread;

	thread = SDL_CreateThread(ui_main_loop_non_sdl, "ui_main_loop_non_sdl", (void *)m);
	SDL_DetachThread(thread);
	SDL_Log("CHECK LOOP1\n");
	while (1)
	{
		if (SDL_PollEvent(m->sdl_event))
			ui_main_handle_event(m);
		ui_win_try_to_create_modal_window(m);
//		ui_win_try_to_close_window(m); пройдется по всем окнам и проверит, есть ли у них флаг на закрытие (который ставится в рейкасте, при нажатии на элемент)
	}
}
