/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_get_mouse_win_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 04:09:48 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/22 04:16:32 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_get_mouse_win_pos_x(t_ui_main *m)
{
	return (m->sdl_event.motion.x);
}

int	ui_get_mouse_win_pos_y(t_ui_main *m)
{
	return (m->sdl_event.motion.y);
}

int	ui_get_mouse_el_pos_x(t_ui_main *m)
{
	if (m->raycaster.selected == NULL)
		return (-1);
	return (m->sdl_event.motion.x - m->raycaster.selected->rect.x);
}

int	ui_get_mouse_el_pos_y(t_ui_main *m)
{
	if (m->raycaster.selected == NULL)
		return (-1);
	return (m->sdl_event.motion.y - m->raycaster.selected->rect.y);
}
