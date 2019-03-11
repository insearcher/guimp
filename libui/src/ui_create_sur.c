/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_create_sur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 02:20:33 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/12 02:33:14 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

SDL_Surface	*ui_sur_create(const int h, const int w)
{
	SDL_Surface	*res;

	if (!(res = SDL_CreateRGBSurface(0, w, h, 32,
	0xFF000000, 0xFF0000, 0xFF00, 0xFF)))
		return (NULL);
	return (res);
}
