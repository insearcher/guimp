/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_handle_event.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 22:13:11 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/04 01:40:27 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_handle_event(t_ui_main *m)
{
	if (m->sdl_event.type == SDL_MOUSEMOTION ||
		m->sdl_event.type == SDL_MOUSEBUTTONDOWN ||
		m->sdl_event.type ==  SDL_MOUSEBUTTONUP)
		ui_main_handle_mouse_event(m);
	else if (m->sdl_event.type == SDL_KEYDOWN)
		ui_main_handle_key_down(m);
	else if (m->sdl_event.type == SDL_KEYUP)
		ui_main_handle_key_up(m);
	else if (m->sdl_event.type == SDL_WINDOWEVENT)
		ui_main_handle_window_event(m);
}
