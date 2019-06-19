/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_from_json.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:06:58 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/05 23:14:02 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_main_from_json(t_ui_main *m, const char *p)
{
	t_jnode	*root;
	t_jnode	*win;

	if (!(root = jtoc_read(p)))
		return (FUNCTION_FAILURE);
	if ((win = jtoc_node_get_by_path(root, "windows"))	)
	{
		win = win->down;
		while (win)
		{
			if (ui_win_from_json(m, win))
				return (FUNCTION_FAILURE);
			win = win->right;
		}
	}
	jtoc_node_clear(root);
	return (FUNCTION_SUCCESS);
}
