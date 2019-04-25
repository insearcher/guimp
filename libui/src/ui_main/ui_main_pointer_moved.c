/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_pointer_moved.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:42:30 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/25 19:44:03 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_pointer_moved(void *a1, void *a2)
{
	t_ui_main	*m;

	m = (t_ui_main *)a1;
	(void)a2;
	m->ptr_pos.x = m->sdl_event.motion.x;
	m->ptr_pos.y = m->sdl_event.motion.y;
}
