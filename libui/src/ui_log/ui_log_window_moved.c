/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_log_window_moved.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 03:40:52 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/12 11:07:54 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void    ui_log_window_moved(t_ui_main *m, void *a)
{
	t_ui_win    *w;

	(void)m;
	w = (t_ui_win *)a;
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
