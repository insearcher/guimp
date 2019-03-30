/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_handle_quit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 23:27:06 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/31 02:09:00 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_handle_quit(t_ui_main *m)
{
	Uint32		windowID;
	t_ui_win	*win;

	windowID = m->sdl_event.window.windowID;
	if ((win = ui_main_find_window_by_id(m, windowID)) == NULL)
	{
		SDL_Log("Window with id %d is not presented in main\n", windowID);
		ui_sdl_deinit();
		exit(EXIT_FAILURE);
	}
	if (win->properties & WIN_MAIN)
		ui_sdl_deinit();
	else
		ui_main_remove_window_by_id(m, windowID);
}
