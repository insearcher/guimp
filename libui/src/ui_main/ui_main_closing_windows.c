/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_closing_windows.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:21:44 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/22 18:39:39 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void ft_lstdelones_without_cont(t_list **alst)
{
	if (!alst)
		return ;
	free(*alst);
	*alst = NULL;
}

void	ui_main_close_window(void *a1, void *a2)
{
	t_ui_main	*m;
	t_ui_win	*w;
	t_ui_win	*cur_w;
	t_list		*cur;
	t_list		*prev;

	m = (t_ui_main *)a1;
	w = (t_ui_win *)a2;
	prev = NULL;
	cur = m->windows;
	while (cur)
	{
		cur_w = (t_ui_win *)(cur->content);
		if (w->sdl_windowID == cur_w->sdl_windowID)
		{
			if (prev == NULL)
				m->windows = cur->next;
			else
				prev->next = cur->next;
			ui_win_close(cur_w);
			ft_lstdelones_without_cont(&cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}

void	ui_main_close_program(void *a1, void *a2)
{
	t_ui_main	*m;

	m = (t_ui_main *)a1;
	a2 = 0;
	m->params |= MAIN_ON_QUIT;
	ui_sdl_deinit(EXIT_SUCCESS);
}
