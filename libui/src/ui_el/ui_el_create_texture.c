/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_create_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:54:15 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/23 05:31:36 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

/*
** OBSOLETE
*/

SDL_Texture	*ui_el_create_texture(t_ui_el *el)
{
	SDL_Texture	*tmp;

	if (!el->sdl_surface || !el->sdl_renderer ||
		!(tmp = SDL_CreateTextureFromSurface(el->sdl_renderer, el->sdl_surface)))
		return (NULL);
	return (tmp);
}
