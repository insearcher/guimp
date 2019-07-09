/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_add_texture_from_file_dialog.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 23:16:17 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/09 18:47:26 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_el_add_texture_from_file_dialog(t_ui_el *el)
{
	char	*path;

	path = NULL;
	if (ui_open_file_dialog(&path) < 0)
		ui_sdl_deinit(228);
	ui_el_add_texture_from_file(el, path, "default");
	free(path);
	return (FUNCTION_SUCCESS);
}

int	ui_el_add_texture_from_file_dialog_with_size(t_ui_el *el, int w, int h)
{
	char		*path;
	SDL_Texture	*tmp_src;
	SDL_Texture	*tmp;
	t_list		*tmp_lst;

	path = NULL;
	tmp_src = NULL;
	tmp_lst = NULL;
	tmp = NULL;
	if (ui_open_file_dialog(&path) < 0 || !(tmp_lst = ft_lstnew(NULL, 0)) ||
		!(tmp = SDL_CreateTexture(el->sdl_renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, w, h)) ||
		ui_el_load_surface_from(el, path) < 0 ||
		!(tmp_src = ui_el_create_texture(el)))
		ui_sdl_deinit(228);
	SDL_SetRenderTarget(el->sdl_renderer, tmp);
	SDL_RenderCopy(el->sdl_renderer, tmp_src, NULL, NULL);
	SDL_SetRenderTarget(el->sdl_renderer, NULL);
	free(path);
	tmp_lst->content_size = ft_strhash("default");
	tmp_lst->content = (void *)tmp;
	ft_lstadd(&(el->sdl_textures), tmp_lst);
	return(FUNCTION_SUCCESS);
}
