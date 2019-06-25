/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_add_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:27:11 by edraugr-          #+#    #+#             */
/*   Updated: 2019/06/25 20:01:24 by edraugr-         ###   ########.fr       */
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

int			ui_el_add_texture_from_file(t_ui_el *el, const char *path, const char *texture_id)
{
	t_list_texture	*tmp_lst;
	SDL_Texture		*tmp_texture;
	int				hash;

	hash = ft_strhash(texture_id);
	if (check_texture_id(el->sdl_textures, hash) || !(tmp_lst = ft_lstnew(NULL, 0)))
		return (FUNCTION_FAILURE);
	if (ui_el_load_surface_from(el, path) == FUNCTION_FAILURE
		|| (tmp_texture = ui_el_create_texture(el)) == NULL)
	{
		free(tmp_lst);
		return(FUNCTION_FAILURE);
	}
	tmp_lst->content_size = hash;
	tmp_lst->content = (void *)tmp_texture;
	ft_lstadd(&(el->sdl_textures), tmp_lst);
	return (FUNCTION_SUCCESS);
}

int			ui_el_add_empty_texture(t_ui_el *el, int w, int h, const char *texture_id)
{
	t_list_texture	*tmp_lst;
	SDL_Texture		*tmp_texture;
	int				hash;

	hash = ft_strhash(texture_id);
	if (check_texture_id(el->sdl_textures, hash) || !(tmp_lst = ft_lstnew(NULL, 0)))
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
	tmp_lst->content_size = hash;
	tmp_lst->content = (void *)tmp_texture;
	ft_lstadd(&(el->sdl_textures), tmp_lst);
	return(FUNCTION_SUCCESS);
}

int			ui_el_add_white_texture(t_ui_el *el, int w, int h, const char *texture_id)
{
	t_list_texture	*tmp_lst;
	SDL_Texture		*tmp_texture;
	int				hash;

	hash = ft_strhash(texture_id);
	if (check_texture_id(el->sdl_textures, hash) || !(tmp_lst = ft_lstnew(NULL, 0)))
		return(FUNCTION_FAILURE);
	if ((tmp_texture = SDL_CreateTexture(el->sdl_renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, w, h)) == NULL)
	{
		free(tmp_lst);
		return(FUNCTION_FAILURE);
	}
	SDL_SetRenderTarget(el->sdl_renderer, tmp_texture);
	SDL_SetRenderDrawBlendMode(el->sdl_renderer, SDL_BLENDMODE_NONE);
	SDL_SetRenderDrawColor(el->sdl_renderer, 255, 255, 255, 255);
	SDL_SetTextureBlendMode(tmp_texture, SDL_BLENDMODE_BLEND);
	SDL_RenderFillRect(el->sdl_renderer, NULL);
	SDL_SetRenderDrawBlendMode(el->sdl_renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderTarget(el->sdl_renderer, NULL);
	SDL_SetRenderDrawColor(el->sdl_renderer, 0, 0, 0, 255);
	tmp_lst->content_size = hash;
	tmp_lst->content = (void *)tmp_texture;
	ft_lstadd(&(el->sdl_textures), tmp_lst);
	return(FUNCTION_SUCCESS);
}

int			ui_el_add_gradient_texture(t_ui_el *el, t_vec2 wh, int color, const char *texture_id)
{
	t_list_texture	*tmp_lst;
	SDL_Texture		*tmp_texture;
	int				hash;
	int				i;

	hash = ft_strhash(texture_id);
	i = -1;
	if (check_texture_id(el->sdl_textures, hash) || !(tmp_lst = ft_lstnew(NULL, 0)))
		return(FUNCTION_FAILURE);
	if ((tmp_texture = SDL_CreateTexture(el->sdl_renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, wh.x, wh.y)) == NULL)
	{
		free(tmp_lst);
		return(FUNCTION_FAILURE);
	}
	SDL_SetRenderTarget(el->sdl_renderer, tmp_texture);
	while (++i < wh.x)
	{
		SDL_SetRenderDrawColor(el->sdl_renderer,
			((color & 0xFF0000) >> 16) * ((float)i / (float)wh.x),
			((color & 0x00FF00) >> 8) * ((float)i / (float)wh.x),
			(color & 0x0000FF) * ((float)i / (float)wh.x), 255);
		SDL_RenderDrawLine(el->sdl_renderer, i, 0, i, wh.y);
	}
	SDL_SetRenderTarget(el->sdl_renderer, NULL);
	SDL_SetRenderDrawColor(el->sdl_renderer, 0, 0, 0, 255);
	tmp_lst->content_size = hash;
	tmp_lst->content = (void *)tmp_texture;
	ft_lstadd(&(el->sdl_textures), tmp_lst);
	return(FUNCTION_SUCCESS);
}

int			ui_el_add_color_texture(t_ui_el *el, t_vec2 wh, int color, const char *texture_id)
{
	t_list_texture	*tmp_lst;
	SDL_Texture		*tmp_texture;
	int				hash;

	hash = ft_strhash(texture_id);
	if (check_texture_id(el->sdl_textures, hash) || !(tmp_lst = ft_lstnew(NULL, 0)))
		return(FUNCTION_FAILURE);
	if ((tmp_texture = SDL_CreateTexture(el->sdl_renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, wh.x, wh.y)) == NULL)
	{
		free(tmp_lst);
		return(FUNCTION_FAILURE);
	}
	SDL_SetRenderTarget(el->sdl_renderer, tmp_texture);
	SDL_SetRenderDrawColor(el->sdl_renderer,
		((color & 0xFF0000) >> 16),
		((color & 0x00FF00) >> 8),
		(color & 0x0000FF), 255);
	SDL_RenderFillRect(el->sdl_renderer, NULL);
	SDL_SetRenderTarget(el->sdl_renderer, NULL);
	SDL_SetRenderDrawColor(el->sdl_renderer, 0, 0, 0, 255);
	tmp_lst->content_size = hash;
	tmp_lst->content = (void *)tmp_texture;
	ft_lstadd(&(el->sdl_textures), tmp_lst);
	return(FUNCTION_SUCCESS);
}
