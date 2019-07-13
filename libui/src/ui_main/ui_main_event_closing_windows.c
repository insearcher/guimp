/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_event_closing_windows.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 05:12:51 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 11:32:45 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

/* static void ft_lstdelones_without_cont(t_list **alst)
{
	t_list	*tmp;

	if (!alst)
		return ;
	tmp = *alst;
	*alst = NULL;
	free(tmp);
}*/

int		ui_main_event_close_window(t_ui_main *m, void *a)
{
	t_ui_win	*w;
	t_ui_win	*cur_w;
	t_list		*cur;
	t_list		*prev;

	SDL_LockMutex(m->mutex);
	w = (t_ui_win *)a;
	prev = NULL;
	cur = m->windows;
	while (cur)
	{
		cur_w = (t_ui_win *)(cur->content);
		if (w->id == cur_w->id)
		{
			ui_win_destroy(cur_w);
			if (prev == NULL)
				m->windows = cur->next;
			else
				prev->next = cur->next;
			free(cur);
//			ft_lstdelones_without_cont(&cur);
			m->params |= HUITA;
			if (m->raycaster->focused_win && m->raycaster->focused_win->id == cur_w->id)
			{
				m->raycaster->focused_win = NULL;
				m->raycaster->selected = NULL;
			}
			SDL_UnlockMutex(m->mutex);
			return (0);
		}
		prev = cur;
		cur = cur->next;
	}
	SDL_UnlockMutex(m->mutex);
	return (1);
}

int		ui_main_event_close_program(t_ui_main *m, void *a)
{
	(void)a;
	m->params |= MAIN_ON_QUIT;
	ui_sdl_deinit(EXIT_SUCCESS);
	return (0);
}
