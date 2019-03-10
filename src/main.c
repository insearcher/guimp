/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:09:10 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/10 19:42:04 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "guimp.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_putstr("SDL_Init error:");
		ft_putendl(SDL_GetError());
		return (1);
	}
	SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (!win)
	{
		ft_putstr("SDL_CreateWindow error:");
		ft_putendl(SDL_GetError());
		SDL_Quit();
		return (1);
	}
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!ren)
	{
		SDL_DestroyWindow(win);
		ft_putstr("SDL_CreateRenderer error:");
		ft_putendl(SDL_GetError());
		SDL_Quit();
		return (1);
	}
	SDL_Delay(3000);
	SDL_Quit();
	return (0);
}
