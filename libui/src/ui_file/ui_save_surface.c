/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_save_surface.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 23:29:01 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/08 23:15:17 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_save_surface(SDL_Surface *sur)
{
	char	*path;

	path = NULL;
	if (ui_open_file_dialog(&path) < 0)
		ui_sdl_deinit(228);
	IMG_SaveJPG(sur, path, 0);
	free(path);
	return (FUNCTION_SUCCESS);
}
