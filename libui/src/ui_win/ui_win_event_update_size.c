/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_event_update_size.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 05:57:22 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/12 10:51:27 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void	bfs_resize_iter(const t_list *root, const void *arg)
{
	QUEUE   *q;
	void    *tmp;

	q = NULL;
	q_push(&q, (t_list *)root);
	while (q)
	{
		tmp = q_pop(&q);
		q_push(&q, CAST_X_TO_Y(tmp, t_ui_el *)->children);
		ui_event_invoke(((t_ui_el *)tmp)->events->onResize, tmp, (void *)arg);
	}
}

static void	bfs_for_resize(const t_ui_el *root, const void *arg)
{
	t_list *lst;

	lst = ft_lstnew(NULL, 0);
	lst->content = CAST_X_TO_Y(root, void *);
	bfs_resize_iter((const t_list *)lst, arg);
	free(lst);
}

void		ui_win_event_update_size(t_ui_main *m, void *a)
{
	t_ui_win	*w;

	(void)m;
	w = (t_ui_win *)a;
	if (w != NULL)
	{
		SDL_GetRendererOutputSize(w->sdl_renderer, &(w->size.x), &(w->size.y));
		if (w->size.x < 800 || w->size.y < 450)
			SDL_SetWindowSize(w->sdl_window, 800, 450);
		else
		{
			int x = (int)sqrt(w->size.x * w->size.y / 16.0f / 9);
			int width, h;
			width = 16 * x;
			h = 9 * x;
			SDL_SetWindowSize(w->sdl_window, width, h);
		}
		w->canvas->rect.w = w->size.x;
		w->canvas->rect.h = w->size.y;
		w->canvas->cut_rect = w->canvas->rect;
		bfs_for_resize(NULL, w->canvas);
	}
}
