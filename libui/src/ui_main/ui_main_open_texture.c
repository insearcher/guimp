/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_open_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:35:28 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/05 16:46:46 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_open_texture(t_ui_el *e, const char *path)
{
	t_list	*l;

	SDL_DestroyTexture((SDL_Texture *)e->sdl_textures->content);
	ui_el_add_texture_from_file(e, path, "default1");
	e->sdl_textures->content = ui_el_get_texture_by_id(e, "default1");
}