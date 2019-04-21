/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_remove_window_by_id.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 23:34:51 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/15 09:55:47 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void	ft_lstdelones_without_cont(t_list **alst)
{
	if (!alst)
		return ;
	free(*alst);
	*alst = NULL;
}

void		ui_main_remove_window_by_id(t_ui_main *m, Uint32 windowID)
{
	t_list		*prev;
	t_list		*cur;
	t_ui_win	*win;

	prev = NULL;
	cur = m->windows;
	while (cur)
	{
		win = (t_ui_win *)(cur->content);
		if (win->sdl_windowID == windowID)
		{
			if (prev == NULL)
				m->windows = cur->next;
			else
				prev->next = cur->next;
			ui_win_close(win);
			ft_lstdelones_without_cont(&cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}
