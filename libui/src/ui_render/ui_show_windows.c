/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_show_windows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 06:26:19 by edraugr-          #+#    #+#             */
/*   Updated: 2019/04/06 18:35:19 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_show_windows(t_ui_main *m)
{
	t_list	*node;

	node = m->windows;
	while (node)
	{
		ui_show_window((t_ui_win *)node->content);
		node = node->next;
	}
}
