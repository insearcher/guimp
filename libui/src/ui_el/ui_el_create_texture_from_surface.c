/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_create_texture_from_surface.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:57:39 by edraugr-          #+#    #+#             */
/*   Updated: 2019/04/10 04:59:14 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

SDL_Texture	*ui_el_create_texture_from_surface(t_ui_el *el)
{
	SDL_Texture	*tmp;

	if (!el->sdl_surface || !el->sdl_renderer ||
		!(tmp = SDL_CreateTextureFromSurface(el->sdl_renderer, el->sdl_surface)))
		return (NULL);
	return (tmp);
}
