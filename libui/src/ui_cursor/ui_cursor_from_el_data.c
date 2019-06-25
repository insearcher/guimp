/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_cursor_from_el_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 19:49:00 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/25 21:26:26 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_cursor_from_el_data(void *a1, void *a2)
{
	SDL_Cursor	*current_cursor;
	SDL_Cursor	*new_cursor;
	SDL_Surface	*new_surface;
	t_cursor	*rc;
	t_ui_el		*el;

	(void)a1;
	el = (t_ui_el *)a2;
	if ((current_cursor = SDL_GetCursor()))
		SDL_FreeCursor(current_cursor);
	if (!(new_surface = SDL_CreateRGBSurface(0, 15, 15, 32, 0, 0, 0, 0)))
		return ;
	if (!(rc = (t_cursor *)el->data) ||
		SDL_BlitScaled(rc->s, NULL, new_surface, NULL) ||
		!(new_cursor = SDL_CreateColorCursor(new_surface, rc->hot_x, rc->hot_y)))
		return ; // ПОШЛО ВСЕ НАХУЙ
	SDL_SetCursor(new_cursor);
}
