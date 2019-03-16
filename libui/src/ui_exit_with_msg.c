/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_exit_with_msg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 20:40:28 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/16 23:07:17 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_exit_with_msg(t_env *e, const char *msg)
{
	if (e->sdl.win)
		SDL_DestroyWindow(e->sdl.win);
	if (e->sdl.ren)
		SDL_DestroyRenderer(e->sdl.ren);
	if (e->sur)
		SDL_FreeSurface(e->sur);
	TTF_Quit();
	SDL_Quit();
	perror(msg);
	exit(EXIT_FAILURE);
}
