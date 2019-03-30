/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_handle_mouse_motion.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 22:26:34 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/31 00:04:47 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_handle_mouse_motion(t_ui_main *m)
{
	printf("Mouse moved to: %d %d in win #%d\n", m->sdl_event.motion.x, m->sdl_event.motion.y, m->sdl_event.window.windowID);
}
