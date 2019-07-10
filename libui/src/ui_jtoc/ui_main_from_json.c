/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_from_json.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:06:58 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/08 23:15:16 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_main_from_json(t_ui_main *m, const char *p)
{
	t_jnode	*root;
	t_jnode	*win;

	if (!(root = jtoc_read(p)))
		return (ui_sdl_log_error("JSON", -1));
	if (!(win = jtoc_node_get_by_path(root, "windows")) || win->type != array)
		return (ui_sdl_log_error("NODE WINDOWS", -1));
	win = win->down;
	while (win)
	{
		if (win->type != object)
			return (ui_sdl_log_error("NODE WINDOW (TYPE)", -1));
		if (ui_win_from_json(m, win))
			ui_sdl_deinit(228);
		win = win->right;
	}
	jtoc_node_clear(root);
	return (FUNCTION_SUCCESS);
}
