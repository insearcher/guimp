/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_create_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 04:48:47 by edraugr-          #+#    #+#             */
/*   Updated: 2019/04/06 18:24:48 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_el_create_texture(t_ui_el *el)
{
	SDL_Texture	*tmp;

	if (!el->sdl_surface || !el->sdl_renderer ||
		!(tmp = SDL_CreateTextureFromSurface(el->sdl_renderer, el->sdl_surface)))
		return (FUNCTION_FAILURE);
	el->sdl_texture = tmp;
	return (FUNCTION_SUCCESS);
}
