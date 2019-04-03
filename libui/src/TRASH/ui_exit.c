/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 00:59:30 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/12 02:25:22 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_exit(t_env *e)
{
	SDL_DestroyWindow(e->sdl.win);
	SDL_DestroyRenderer(e->sdl.ren);
	SDL_FreeSurface(e->sur);
	TTF_Quit();
	SDL_Quit();
	exit(EXIT_SUCCESS);
}
