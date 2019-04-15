/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:26:26 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/15 03:01:36 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_loop(t_ui_main *m)
{
	m->target_tick = 0;
	while (1)
	{
		m->cur_tick = SDL_GetTicks();
		if (SDL_PollEvent(&(m->sdl_event)))
		{
			ui_main_handle_event(m);
			ui_draw(m);
		}
		if (m->cur_tick >= m->target_tick)
		{
			m->target_tick = m->cur_tick + 1000 / FPS;
			ui_main_handle_raycast(m);
			ui_draw(m);
		}
		// SDL_PollEvent(&(m->sdl_event));
		// ui_main_handle_event(m);
		// ui_draw(m);
	}
}
