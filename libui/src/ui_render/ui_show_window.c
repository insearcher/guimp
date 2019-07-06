/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_show_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 06:18:39 by edraugr-          #+#    #+#             */
/*   Updated: 2019/07/06 19:22:38 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void ui_show_window(t_ui_win *w)
{
	int check;
	SDL_RendererInfo *info;
	
	info = (SDL_RendererInfo *)malloc(sizeof(SDL_RendererInfo));
	check = SDL_GetRendererInfo(w->sdl_renderer, info);
	free(info);
	if (check != 0)
	{
		SDL_Log("error: %s\n", SDL_GetError());
		return ;
	}
	if (w && w->sdl_renderer)
		SDL_RenderPresent(w->sdl_renderer);
}
