/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_log_window_closed.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:51:02 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/27 15:24:57 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		ui_log_window_closed(void *a1, void *a2)
{
	t_ui_main	*m;
	t_ui_win	*w;

	m = (t_ui_main *)a1;
	w = (t_ui_win *)a2;
//	if (w != NULL)
//	{
		SDL_Log("%s%-15s%swindowID = %d\n",
			KYEL,
			"WIN CLOSED",
			KNRM,
			w->id
		);
//	}
}
