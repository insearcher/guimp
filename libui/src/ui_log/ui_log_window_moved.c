/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_log_window_moved.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 03:40:52 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/06 03:41:22 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void    ui_log_window_moved(void *a1, void *a2)
{
	t_ui_main   *m;
	t_ui_win    *w;
	Uint32      windowID;

	m = (t_ui_main *)a1;
	windowID = *((Uint32 *)a2);
	w = ui_main_find_window_by_id(m, windowID);
	if (w != NULL)
	{
		SDL_Log("%s%-15s%swindowID = %d\n",
				KYEL,
				"WIN MOVED",
				KNRM,
				m->sdl_event.window.windowID
			   );
	}
}
