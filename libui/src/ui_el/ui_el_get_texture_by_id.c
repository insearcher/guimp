/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_get_texture_by_id.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 04:44:09 by edraugr-          #+#    #+#             */
/*   Updated: 2019/05/24 19:31:38 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

SDL_Texture	*ui_el_get_texture_by_id(t_ui_el *el, const char *id)
{
	SDL_Texture		*res;
	t_list_texture	*tmp;
	int				hash;

	res = NULL;
	if (!el)
		return (res);
	tmp = el->sdl_textures;
	hash = ft_strhash(id);
	while (tmp && !res)
	{
		if (tmp->content_size == (size_t)hash)
			res = (SDL_Texture *)tmp->content;
		tmp = tmp->next;
	}
	return (res);
}
