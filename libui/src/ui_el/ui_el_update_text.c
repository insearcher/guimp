/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_update_text.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 05:38:20 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/24 19:26:01 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_el_update_text(t_ui_el *el, const char *text)
{
	t_ui_text	*td;
	t_list		*n;

	td = (t_ui_text *)el->data;
	if (!(el->sdl_surface = TTF_RenderText_Solid(td->font, text, td->color)) ||
		!(n = ft_lstnew(NULL, 0)))
		return (FUNCTION_FAILURE);
	n->content = ui_el_create_texture(el);
	n->content_size = ft_strhash("default");
	if (el->sdl_textures)
	{
		SDL_DestroyTexture((SDL_Texture *)el->sdl_textures->content);
		free(el->sdl_textures);
	}
	ft_lstadd(&(el->sdl_textures), n);
	return (FUNCTION_SUCCESS);
}
