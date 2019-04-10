/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_load_surface_from.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 04:32:52 by edraugr-          #+#    #+#             */
/*   Updated: 2019/04/10 05:02:45 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_el_load_surface_from(t_ui_el *el, const char *path)
{
	SDL_Surface	*tmp;

	if (!(tmp = IMG_Load(path)))
		return (FUNCTION_FAILURE);
	SDL_FreeSurface(el->sdl_surface);
	el->sdl_surface = tmp;
	return (FUNCTION_SUCCESS);
}
