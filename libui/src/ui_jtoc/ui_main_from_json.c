/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_from_json.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:06:58 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/19 20:16:30 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_main_from_json(t_ui_main *m, const char *p)
{
	t_jnode	*root;
	t_jnode	*win;

	if (!(root = jtoc_read(p)))
		return (FUNCTION_FAILURE);
	if (!(win = jtoc_node_get_by_path(root, "windows")) || win->type != array)
		return (ui_sdl_log_error("MAIN: WINDOWS/TYPE"));
	win = win->down;
	while (win)
	{
		if (win->type != object)
			return (ui_sdl_log_error("MAIN: TYPE"));
		if (ui_win_from_json(m, win))
			return (ui_sdl_log_error("MAIN: PARSING WINDOW"));
		win = win->right;
	}
	jtoc_node_clear(root);
	return (FUNCTION_SUCCESS);
}
