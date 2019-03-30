/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_find_window_by_id.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 23:24:13 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/30 23:35:51 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_ui_win	*ui_main_find_window_by_id(t_ui_main *m, Uint32 windowID)
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
