/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_update_text.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 05:38:20 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/08 03:47:24 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int	get_surface_from_text(t_ui_el *el)
{
	if (el->sdl_surface != NULL)
	{
		SDL_FreeSurface(el->sdl_surface);
		el->sdl_surface = NULL;
	}
	if (el->text_area->render_param & TEXT_IS_SOLID)
	{
		if (!(el->sdl_surface = TTF_RenderText_Solid(el->text_area->font,
						el->text_area->text, el->text_area->text_color)))
		{
			return (FUNCTION_FAILURE);
		}
	}
	else if ((el->text_area->render_param & TEXT_IS_BLENDED) || el->text_area->render_param == 0)
	{
		if (!(el->sdl_surface = TTF_RenderText_Blended(el->text_area->font,
						el->text_area->text, el->text_area->text_color)))
		{
			return (FUNCTION_FAILURE);
		}
	}
	else
	{
		if (!(el->sdl_surface = TTF_RenderText_Shaded(el->text_area->font,
			el->text_area->text, el->text_area->text_color, el->text_area->bg_color)))
		{
			return (FUNCTION_FAILURE);
		}
	}
	return (FUNCTION_SUCCESS);
}

static void	clear_el_text(t_ui_el *el)
{
	if (el->text_area->text != NULL)
		free(el->text_area->text);
	el->text_area->text = NULL;
}

void	free_sdl_texture(void *v_texture, size_t hash)
{
	SDL_Texture *texture;

	texture = (SDL_Texture *)v_texture;
	hash = 0;
	if (texture)
		SDL_DestroyTexture(texture);
}

int	ui_el_update_text(t_ui_el *el, const char *text)
{
	t_list		*n;
	size_t		len;

	if (text == NULL)
		return (FUNCTION_SUCCESS);
	len = ft_strlen(text);
	if (el->text_area->max_text_size == 0 || len <= el->text_area->max_text_size)
	{
		clear_el_text(el);
		el->text_area->text = ft_strdup(text);
	}
	else
	{
		if (el->text_area->text != NULL)
			return (FUNCTION_SUCCESS);
		else
		{
			clear_el_text(el);
			el->text_area->text = ft_strsub(text, 0, el->text_area->max_text_size);
		}
	}
	//	ft_lstdel(&el->sdl_textures, &free_sdl_texture);
	//	el->sdl_textures = NULL;
	if (get_surface_from_text(el) == FUNCTION_FAILURE)
		ui_el_add_empty_texture(el, el->rect.w, el->rect.h, "default");
	else
	{
		SDL_Rect *rect = (SDL_Rect *)malloc(sizeof(SDL_Rect));

		SDL_GetClipRect(el->sdl_surface, rect);
//		SDL_Log("rect: (%d, %d)\n", rect->w, rect->h);
		if (rect->w > 6000 || rect->h > 3000)
			return (FUNCTION_SUCCESS);
		if (!(n = ft_lstnew(NULL, 0)))
			return (FUNCTION_FAILURE);
		n->content = ui_el_create_texture(el);
		n->content_size = ft_strhash("default");
		ft_lstadd(&(el->sdl_textures), n);
	}
	return (FUNCTION_SUCCESS);
}
