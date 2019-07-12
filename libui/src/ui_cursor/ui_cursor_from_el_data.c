/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_cursor_from_el_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 19:49:00 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/12 03:15:58 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_cursor_from_el_data(t_ui_main *m, void *a)
{
	SDL_Cursor	*current_cursor;
	SDL_Cursor	*new_cursor;
	t_cursor	*rc;
	t_ui_el		*el;

	(void)m;
	el = (t_ui_el *)a;
	if ((current_cursor = SDL_GetCursor()))
		SDL_FreeCursor(current_cursor);
	if (!(rc = (t_cursor *)el->data) ||
		!(new_cursor = SDL_CreateColorCursor(rc->s, rc->hot_x, rc->hot_y)))
		return ; // ПОШЛО ВСЕ НАХУЙ
	SDL_SetCursor(new_cursor);
}
