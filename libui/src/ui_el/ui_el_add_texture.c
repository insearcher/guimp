/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_add_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:27:11 by edraugr-          #+#    #+#             */
/*   Updated: 2019/05/23 05:33:37 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int	check_texture_id(t_list_texture *lst, int texture_id)
{
	while (lst)
	{
		if (lst->content_size == (size_t)texture_id)
			return (FUNCTION_FAILURE);
		lst = lst->next;
	}
	return (FUNCTION_SUCCESS);
}

/*
** OBSOLETE
*/

int			ui_el_add_texture_from_file(t_ui_el *el, const char *path, int texture_id)
{
	t_list_texture	*tmp_lst;
	SDL_Texture		*tmp_texture;

	if (check_texture_id(el->sdl_textures, texture_id) || !(tmp_lst = ft_lstnew(NULL, 0)))
		return(FUNCTION_FAILURE);
	if (ui_el_load_surface_from(el, path) == FUNCTION_FAILURE
		|| (tmp_texture = ui_el_create_texture(el)) == NULL)
	{
		free(tmp_lst);
		return(FUNCTION_FAILURE);
	}
	tmp_lst->content_size = texture_id;
	tmp_lst->content = (void *)tmp_texture;
	ft_lstadd(&(el->sdl_textures), tmp_lst);
	return (FUNCTION_SUCCESS);
}

int			ui_el_add_empty_texture(t_ui_el *el, int w, int h, int texture_id)
{
	t_list_texture	*tmp_lst;
	SDL_Texture		*tmp_texture;

	if (check_texture_id(el->sdl_textures, texture_id) || !(tmp_lst = ft_lstnew(NULL, 0)))
		return(FUNCTION_FAILURE);
	if ((tmp_texture = SDL_CreateTexture(el->sdl_renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, w, h)) == NULL)
	{
		free(tmp_lst);
		return(FUNCTION_FAILURE);
	}
	SDL_SetRenderTarget(el->sdl_renderer, tmp_texture);
	SDL_SetRenderDrawBlendMode(el->sdl_renderer, SDL_BLENDMODE_NONE);
	SDL_SetRenderDrawColor(el->sdl_renderer, 255, 255, 255, 0);
	SDL_SetTextureBlendMode(tmp_texture, SDL_BLENDMODE_BLEND);
	SDL_RenderFillRect(el->sdl_renderer, NULL);
	SDL_SetRenderDrawBlendMode(el->sdl_renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderTarget(el->sdl_renderer, NULL);
	SDL_SetRenderDrawColor(el->sdl_renderer, 0, 0, 0, 255);
	tmp_lst->content_size = texture_id;
	tmp_lst->content = (void *)tmp_texture;
	ft_lstadd(&(el->sdl_textures), tmp_lst);
	return(FUNCTION_SUCCESS);
}
