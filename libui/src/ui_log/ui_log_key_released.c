/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_log_key_released.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 08:00:48 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/19 01:35:05 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_log_key_released(void *a1, void *a2)
{
	t_ui_main	*m;

	m = (t_ui_main *)a1;
	(void)a2;
	SDL_Log("Key released: %d\n", m->sdl_event->key.keysym.scancode);
}
