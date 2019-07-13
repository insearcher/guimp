/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_log_key_released.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 08:00:48 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/13 09:31:13 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_log_key_released(t_ui_main *m, void *a)
{
	(void)a;
	SDL_Log("Key released: %d\n", m->sdl_event->key.keysym.scancode);
	return (1);
}
