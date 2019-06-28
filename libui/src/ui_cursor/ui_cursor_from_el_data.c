/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_cursor_from_el_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 19:49:00 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/27 15:24:57 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_cursor_from_el_data(void *a1, void *a2)
{
	SDL_Cursor	*current_cursor;
	SDL_Cursor	*new_cursor;
	t_cursor	*rc;
	t_ui_el		*el;

	(void)a1;
	el = (t_ui_el *)a2;
	if ((current_cursor = SDL_GetCursor()))
		SDL_FreeCursor(current_cursor);
	if (!(rc = (t_cursor *)el->data) ||
		!(new_cursor = SDL_CreateColorCursor(rc->s, rc->hot_x, rc->hot_y)))
		return ; // ПОШЛО ВСЕ НАХУЙ
	SDL_SetCursor(new_cursor);
}
