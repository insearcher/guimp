/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_create_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 01:08:48 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/29 22:46:55 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_create_env(t_env *e, const int w, const int h)
{
	ft_bzero(e, sizeof(t_env));
	ft_bzero(&(e->sdl), sizeof(t_sdl));
	e->w = w;
	e->h = h;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ui_exit_with_msg(e, "libui: unable to initialize SDL2");
	if (TTF_Init() < 0)
		ui_exit_with_msg(e, "libui: unable to initialize SDL2 TTF");
}
