/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_cursor_to_default.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 20:12:29 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/12 03:14:57 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_cursor_to_default(t_ui_main *m, void *a)
{
	SDL_Cursor	*current_cursor;

	(void)m;
	(void)a;
	if ((current_cursor = SDL_GetCursor()))
		SDL_FreeCursor(current_cursor);
}
