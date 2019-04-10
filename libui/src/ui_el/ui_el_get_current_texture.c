/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_get_current_texture.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 05:05:14 by edraugr-          #+#    #+#             */
/*   Updated: 2019/04/10 06:38:19 by edraugr-         ###   ########.fr       */
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
			return(CAST_X_TO_Y(tmp->content, SDL_Texture *));
		tmp = tmp->next;
	}
	return (NULL);
}
