/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_find_window_by_sdl_id.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 17:56:16 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/22 20:18:17 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_ui_win	*ui_main_find_window_by_sdl_id(t_ui_main *m, Uint32 windowID)
{
	t_list		*node;
	t_ui_win	*win;

	node = m->windows;
	while (node)
	{
		win = (t_ui_win *)(node->content);
		if (win->sdl_windowID == windowID)
			return (win);
		node = node->next;
	}
	return (NULL);
}

t_ui_win    *ui_main_find_window_by_id(t_ui_main *m, Uint32 windowID)
{
	t_list      *node;
	t_ui_win    *win;

	node = m->windows;
	while (node)
	{
		win = (t_ui_win *)(node->content);
		if (win->id == windowID)
			return (win);
		node = node->next;
	}
	return (NULL);
}
