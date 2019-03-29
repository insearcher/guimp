/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init_enviroment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 22:39:47 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/29 22:46:27 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_init_enviroment(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0 ||
		IMG_Init(IMG_INIT_JPG) < 0 ||
		TTF_Init() < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
			"Couldn't initialize enviroment: %s", SDL_GetError());
		return (FUNCTION_FAILURE);
	}
	return (FUNCTION_SUCCESS);
}
