/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_get_current_texture.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 05:05:14 by edraugr-          #+#    #+#             */
/*   Updated: 2019/05/24 19:46:22 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

SDL_Texture	*ui_el_get_current_texture(t_ui_el *el)
{
	t_list_texture	*tmp;

	tmp = el->sdl_textures;
	if (tmp == NULL)
		return (NULL);
	while (tmp)
	{
		if (tmp->content_size == el->current_texture)
			return ((SDL_Texture *)tmp->content);
		tmp = tmp->next;
	}
	return (NULL);
}
