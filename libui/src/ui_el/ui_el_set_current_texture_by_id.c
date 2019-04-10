/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_current_texture_by_id.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 05:06:00 by edraugr-          #+#    #+#             */
/*   Updated: 2019/04/10 06:36:38 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_el_set_current_texture_by_id(t_ui_el *el, int texture_id)
{
	t_list_texture	*tmp;

	tmp = el->sdl_textures;
	if (tmp == NULL)
		return (FUNCTION_FAILURE);
	while (tmp)
	{
		if (tmp->content_size == (size_t)texture_id)
		{
			el->current_texture = texture_id;
			return(FUNCTION_SUCCESS);
		}
		tmp = tmp->next;
	}
	return (FUNCTION_FAILURE);
}
