/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_log_window_moved.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 03:40:52 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/22 18:36:43 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void    ui_log_window_moved(void *a1, void *a2)
{
	t_ui_main   *m;
	t_ui_win    *w;

	m = (t_ui_main *)a1;
	w = (t_ui_win *)a2;
	if (w != NULL)
	{
		SDL_Log("%s%-15s%swindowID = %d\n",
				KYEL,
				"WIN MOVED",
				KNRM,
				w->id
			   );
	}
}
