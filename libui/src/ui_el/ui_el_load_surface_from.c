/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_load_surface_from.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 04:32:52 by edraugr-          #+#    #+#             */
/*   Updated: 2019/04/06 18:25:56 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_el_load_surface_from(t_ui_el *el, const char *path)//, const int img_flag)
{
	SDL_Surface	*tmp;

	if (!(tmp = IMG_Load(path)))
		return (FUNCTION_FAILURE);
	el->sdl_surface = tmp;
	return (FUNCTION_SUCCESS);
}
