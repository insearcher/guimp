/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:26:26 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/10 12:23:34 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_loop(t_ui_main *m)
{
	while (1)
	{
		// if (SDL_PollEvent(&(m->sdl_event)))
		// {
		// 	ui_main_handle_event(m);
		// 	ui_draw(m);
		// }
		SDL_PollEvent(&(m->sdl_event));
		ui_main_handle_event(m);
		ui_draw(m);
	}
}
