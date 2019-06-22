/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_log_mouse_motion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:37:29 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/22 18:20:40 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_log_mouse_motion(void *a1, void *a2)
{
	t_ui_main	*m;
	t_ui_win	*w;

	m = (t_ui_main *)a1;
	w = (t_ui_win *)a2;
	if (w != NULL)
	{
		SDL_Log("Mouse moved to (%d,%d) in win with ID=%d\n",
				m->ptr_pos.x,
				m->ptr_pos.y,
				w->id);
	}
}
