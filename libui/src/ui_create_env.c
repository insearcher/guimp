/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_create_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 01:08:48 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/16 22:18:18 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_create_env(t_env *e)
{
	ft_bzero(e, sizeof(t_env));
	ft_bzero(&(e->sdl), sizeof(t_sdl));
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ui_exit_with_msg("libui: unable to initialize SDL2", e);
	if (TTF_Init() < 0)
		ui_exit_with_msg("libui: unable to initialize SDL2 TTF", e);
}
