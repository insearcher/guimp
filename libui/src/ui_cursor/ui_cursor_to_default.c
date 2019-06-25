/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_cursor_to_default.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 20:12:29 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/22 20:14:58 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_cursor_to_default(void *a1, void *a2)
{
	SDL_Cursor	*current_cursor;

	(void)a1;
	(void)a2;
	if ((current_cursor = SDL_GetCursor()))
		SDL_FreeCursor(current_cursor);
}
