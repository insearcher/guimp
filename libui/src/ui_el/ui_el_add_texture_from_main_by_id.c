/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_add_texture_from_main_by_id.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 05:08:46 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/23 05:15:15 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_el_add_texture_from_main_by_id(t_ui_main *m, t_ui_el *el,
size_t id, int texture_id)
{
	SDL_Surface	*s;
	SDL_Texture	*t;
	t_list		*n;

	s = ui_main_get_surface_by_id(m, id);
	t = ui_el_create_texture_from_surface(el, s);
	if (!(n = ft_lstnew(NULL, 0)))
		return (FUNCTION_FAILURE);
	n->content_size = texture_id;
	n->content = (void *)t;
	ft_lstadd(&(el->sdl_textures), n);
	return (FUNCTION_SUCCESS);
}
