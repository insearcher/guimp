/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:14:50 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/12 10:56:33 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void	ui_el_text_destroy(t_ui_text *t)
{
	free(t->text);
	free(t);
}

static void	ui_el_modal_win_destroy(t_ui_modal_win *mw)
{
	int i;

	free(mw->text);
	free(mw->output_text);
	i = -1;
	while (mw->text[++i])
		free(mw->text[++i]);
	free(mw->text);
	free(mw);
}

void		ui_el_destroy(t_ui_el *e)
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
		ui_el_text_destroy(e->text_area);
	if (e->modal_win)
		ui_el_modal_win_destroy(e->modal_win);
	ui_event_el_events_destroy(e->events);
	free(e);
}
