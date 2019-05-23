/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_create_texture_from_surface.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:57:39 by edraugr-          #+#    #+#             */
/*   Updated: 2019/05/23 05:30:30 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

/*
** OBSOLETE
*/

SDL_Texture	*ui_el_create_texture_from_surface(t_ui_el *el, SDL_Surface *s)
{
	el->sdl_surface = s;
	return (ui_el_create_texture(el));
}
