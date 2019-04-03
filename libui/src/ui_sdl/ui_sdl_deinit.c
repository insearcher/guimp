/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_sdl_deinit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 22:46:42 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/03 23:51:12 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_sdl_deinit(int exit_status)
{
	SDL_Quit();
	IMG_Quit();
	TTF_Quit();
	exit(exit_status);
}
