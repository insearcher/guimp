/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_cursor_from.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 20:09:20 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/22 20:12:54 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_cursor_from(t_cursor *c)
{
	SDL_Cursor	*current_cursor;
	SDL_Cursor	*new_cursor;

	if ((current_cursor = SDL_GetCursor()))
		SDL_FreeCursor(current_cursor);
	if (!(new_cursor = SDL_CreateColorCursor(c->s, c->hot_x, c->hor_y)))
		return ; // ПОШЛО ВСЕ НАХУЙ
	SDL_SetCursor(new_cursor);
}
