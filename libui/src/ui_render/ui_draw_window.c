/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_draw_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 05:49:45 by edraugr-          #+#    #+#             */
/*   Updated: 2019/07/06 16:06:26 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int	check_border(t_ui_el *el)
{
	if (el->rect.x > el->parent->cut_rect.x + el->parent->cut_rect.w ||
			el->rect.x + el->rect.w < el->parent->cut_rect.x ||
			el->rect.y > el->parent->cut_rect.y + el->parent->cut_rect.h ||
			el->rect.y + el->rect.h < el->parent->cut_rect.y)
		return (0);
	return (1);
}

static void	bfs_iter_draw(const t_list *root, const void *arg)
{
	QUEUE   *q;
	void    *tmp;
	t_ui_el	*cur_el;

	q = NULL;
	q_push(&q, (t_list *)root);
	while (q)
	{
		tmp = q_pop(&q);
		cur_el = (t_ui_el *)tmp;
		if (!(cur_el->params & EL_IS_HIDDEN))
		{
			if ((cur_el->params & EL_IS_DEPENDENT) && (!(check_border(cur_el))))
				continue;
			q_push(&q, CAST_X_TO_Y(tmp, t_ui_el *)->children);
			ui_event_invoke(((t_ui_el *)tmp)->events->onRender, tmp, (void *)arg);
		}
	}
}

static void	bfs_iter_root_draw(const t_ui_el *root, const void *arg)
{
	t_list *lst;

	lst = ft_lstnew(NULL, 0);
	lst->content = CAST_X_TO_Y(root, void *);
	bfs_iter_draw((const t_list *)lst, arg);
	free(lst);
}

void	ui_draw_window(t_ui_win *w, t_ui_main *m)
{
	bfs_iter_root_draw(w->canvas, (void *)m);
}
