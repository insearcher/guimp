/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_log_mouse_motion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:37:29 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/12 03:34:29 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_log_mouse_motion(t_ui_main *m, void *a)
{
	t_ui_win	*w;

	w = (t_ui_win *)a;
	if (w != NULL)
	{
		SDL_Log("Mouse moved to (%d,%d) in win with ID=%d\n",
				m->ptr_pos.x,
				m->ptr_pos.y,
				w->id);
	}
}
