/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_handle_event.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 22:13:11 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/31 15:00:13 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_handle_event(t_ui_main *m)
{
	if (m->sdl_event.type == SDL_KEYDOWN)
		ui_main_handle_key_down(m);
	else if (m->sdl_event.type == SDL_KEYUP)
		ui_main_handle_key_up(m);
	else if (m->sdl_event.type == SDL_MOUSEMOTION)
		ui_main_handle_mouse_motion(m);
	else if (m->sdl_event.type == SDL_MOUSEBUTTONDOWN)
		ui_main_handle_mouse_button_down(m);
	else if (m->sdl_event.type == SDL_MOUSEBUTTONUP)
		ui_main_handle_mouse_button_up(m);
	else if (m->sdl_event.type == SDL_WINDOWEVENT)
		ui_main_handle_window_event(m);
}
