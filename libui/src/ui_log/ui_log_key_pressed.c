/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_log_key_pressed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 07:58:55 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/12 03:33:09 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_log_key_pressed(t_ui_main *m, void *a)
{
	(void)a;
	SDL_Log("Key pressed: %d\n", m->sdl_event->key.keysym.scancode);
}
