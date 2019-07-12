/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_jtoc_main_from_json.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 06:52:57 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/12 07:04:43 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_jtoc_main_from_json(t_ui_main *m, const char *p)
{
	t_jnode	*root;
	t_jnode	*win;

	if (!(root = jtoc_read(p)))
		return (ui_jtoc_sdl_log_error("JSON", -1));
	if (!(win = jtoc_node_get_by_path(root, "windows")) || win->type != array)
		return (ui_jtoc_sdl_log_error("NODE WINDOWS", -1));
	win = win->down;
	while (win)
	{
		if (win->type != object)
			return (ui_jtoc_sdl_log_error("NODE WINDOW (TYPE)", -1));
		if (ui_jtoc_win_from_json(m, win))
			ui_sdl_deinit(228);
		win = win->right;
	}
	jtoc_node_clear(root);
	return (FUNCTION_SUCCESS);
}
