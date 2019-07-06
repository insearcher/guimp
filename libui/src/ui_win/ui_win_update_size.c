/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_update_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 04:01:55 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/06 17:43:02 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_win_update_size(void *a1, void *a2)
{
	t_ui_main	*m;
	t_ui_win	*w;

	m = (t_ui_main *)a1;
	w = (t_ui_win *)a2;
	if (w != NULL)
	{
//		SDL_GetWindowSize(w->sdl_window, &(w->size.x), &(w->size.y));
//		vrode perestalo viletat', no ne tochno
		SDL_GetRendererOutputSize(w->sdl_renderer, &(w->size.x), &(w->size.y));
		int x = (int)sqrt(w->size.x * w->size.y / 16.0f / 9);
		int width, h;
		width = 16 * x;
		h = 9 * x;
		SDL_SetWindowSize(w->sdl_window, width, h);
//		if (w->size.x < 800 || w->size.y < 600)
//			SDL_SetWindowSize(w->sdl_window, 800, 600);
		w->canvas->rect.w = w->size.x;
		w->canvas->rect.h = w->size.y;
		w->canvas->cut_rect = w->canvas->rect;
		ui_el_resize_elems(a1, (void *)w);
	}
}
