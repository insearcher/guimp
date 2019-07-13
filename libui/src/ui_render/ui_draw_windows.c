/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_draw_windows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 06:06:48 by edraugr-          #+#    #+#             */
/*   Updated: 2019/07/13 02:57:16 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_draw_windows(t_ui_main *m)
{
	t_list	*node;

	node = m->windows;
	while (node)
	{
		bfs_for_draw(m, ((t_ui_win *)node->content)->canvas);
		node = node->next;
	}
}
