/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:10:21 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/30 23:42:30 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_win_close(t_ui_win *w)
{
	// SDL_FreeSurface(w->sdl_surface);
	SDL_DestroyWindow(w->sdl_window);
	// ui_el_free(w->canvas);
	ft_memdel((void **)&(w->title));
}
