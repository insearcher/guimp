/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:20:31 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/19 01:34:25 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_ui_main	*ui_main_init(void)
{
	t_ui_main	*m;

	if (!(m = (t_ui_main *)malloc(sizeof(t_ui_main))))
		return (NULL);
	ft_bzero(m, sizeof(t_ui_main));
	if (!(m->raycaster = (t_ui_raycaster *)malloc(sizeof(t_ui_raycaster))))
		return (NULL);
	ft_bzero(m->raycaster, sizeof(t_ui_raycaster));
	if (!(m->sdl_event = (SDL_Event *)malloc(sizeof(SDL_Event))))
		return (NULL);
	ft_bzero(m->sdl_event, sizeof(SDL_Event));
	return (m);
}
