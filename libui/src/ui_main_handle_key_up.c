/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_handle_key_up.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 22:18:26 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/31 14:55:21 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_handle_key_up(t_ui_main *m)
{
	SDL_Log("Key up: %d\n", m->sdl_event.key.keysym.scancode);
}
