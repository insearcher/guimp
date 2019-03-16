/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_get_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 23:35:01 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/16 23:46:07 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_get_events(int (*event)(t_env *e), t_env *e)
{
	SDL_PollEvent(&(e->sdl.evt));
	e->state = SDL_GetKeyboardState(0);
	SDL_GetMouseState(&(e.m_pos[0]), &(e.m_pos[1]));
	event(e);
	SDL_FlushEvent(SDL_KEYDOWN);
	return (0);
}
