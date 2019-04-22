/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_get_texture_by_id.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 04:44:09 by edraugr-          #+#    #+#             */
/*   Updated: 2019/04/22 04:54:18 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

SDL_Texture	*ui_el_get_texture_by_id(t_ui_el *el, int id)
{
	SDL_Texture		*res;
	t_list_texture	*tmp;

	res = NULL;
	if (!el)
		return (res);
	tmp = el->sdl_textures;
	while (tmp && !res)
	{
		if (tmp->content_size == (size_t)id)
			res = (SDL_Texture *)tmp->content;
		tmp = tmp->next;
	}
	return (res);
}
