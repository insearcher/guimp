/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_log_window_closed.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:51:02 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/19 02:22:07 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void	close_notmain(t_ui_main *m, Uint32 windowID)
{
	ui_main_remove_window_by_id(m, windowID);
}

static void	close_main()
{
	ui_sdl_deinit(EXIT_SUCCESS);
}

void		ui_log_window_closed(void *a1, void *a2)
{
	t_ui_main	*m;
	t_ui_win	*w;

	m = (t_ui_main *)a1;
	w = (t_ui_win *)a2;
	if (w != NULL)
	{
		SDL_Log("%s%-15s%swindowID = %d\n",
			KYEL,
			"WIN CLOSED",
			KNRM,
			m->sdl_event->window.windowID
		);
		if (w->params & WIN_MAIN)
		{
			m->params |= MAIN_ON_QUIT;
			close_main();
		}
		else
			close_notmain(m, w->sdl_windowID);
	}
}
