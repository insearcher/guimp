/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_add_texture_from_main_by_id.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 05:08:46 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/08 23:15:16 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_el_add_texture_from_main_by_id(t_ui_main *m, t_ui_el *el,
		const char *id, const char *texture_id)
{
	SDL_Surface	*s;
	SDL_Texture	*t;
	t_list		*n;
	int			h;

	s = ui_main_get_surface_by_id(m, id);
	t = ui_el_create_texture_from_surface(el, s);
	if (!(n = ft_lstnew(NULL, 0)))
		ui_sdl_deinit(228);
	h = ft_strhash(texture_id);
	if (h == ft_strhash("default"))
		el->current_texture = h;
	n->content_size = h;
	n->content = (void *)t;
	ft_lstadd(&(el->sdl_textures), n);
	return (FUNCTION_SUCCESS);
}
