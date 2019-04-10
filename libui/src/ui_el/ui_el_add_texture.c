/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_add_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:27:11 by edraugr-          #+#    #+#             */
/*   Updated: 2019/04/10 09:25:19 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int	check_texture_id(t_list_texture *lst, int texture_id)
{
	while (lst)
	{
		if (lst->content_size == (size_t)texture_id)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int			ui_el_add_texture_from_file(t_ui_el *el, const char *path, int texture_id)
{
	t_list_texture	*tmp_lst;
	SDL_Texture		*tmp_texture;

	if (check_texture_id(el->sdl_textures, texture_id) || !(tmp_lst = ft_lstnew(NULL, 0)))
		return(FUNCTION_FAILURE);
	if (ui_el_load_surface_from(el, path) == FUNCTION_FAILURE
		|| (tmp_texture = ui_el_create_texture_from_surface(el)) == NULL)
	{
		free(tmp_lst);
		return(FUNCTION_FAILURE);
	}
	tmp_lst->content_size = texture_id;
	tmp_lst->content = (void *)tmp_texture;
	ft_lstadd(&(el->sdl_textures), tmp_lst);
	return(FUNCTION_SUCCESS);
}
