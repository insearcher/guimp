/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_create_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 23:51:29 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/16 23:54:50 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_create_frame(void (*frame)(t_env *e), t_env *e)
{
	if ((SDL_RenderClear(e->sdl.ren)) != 0)
		ui_exit_with_msg(e, "libui: error while clearing the renderer");
	frame(e);
	if (!(e->tex = SDL_CreateTextureFromSurface(
	e->sdl.ren, e->sur)))
		ui_exit_with_msg(e, "libui: error while creating the texture");
	if ((SDL_RenderCopy(e->sdl.ren, e->tex, 0, 0)) != 0)
		ui_exit_with_msg(e, "libui: error while RenderCopy");
	SDL_DestroyTexture(e->tex);
	SDL_RenderPresent(e->sdl.ren);
}
