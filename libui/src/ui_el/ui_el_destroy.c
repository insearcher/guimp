/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:14:50 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/09 21:34:14 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_destroy(t_ui_el *e)
{
	t_list	*tmp;

	if (e->sdl_surface)
		SDL_FreeSurface(e->sdl_surface);
	tmp = e->sdl_textures;
	while (e->sdl_textures)
	{
		SDL_DestroyTexture((SDL_Texture *)e->sdl_textures->content);
		e->sdl_textures = e->sdl_textures->next;
		free(tmp);
		tmp = e->sdl_textures;
	}
	ui_el_destroy_children(e->children);
	if (e->text_area)
		ui_text_destroy(e->text_area);
	if (e->modal_win)
		ui_modal_win_destroy(e->modal_win);
	ui_el_events_destroy(e->events);
	free(e);
}