/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_for_resize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 20:44:38 by sbecker           #+#    #+#             */
/*   Updated: 2019/05/31 21:10:59 by sbecker          ###   ########.fr       */
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
		ui_event_invoke(&(((t_ui_el *)tmp)->events.onResize), tmp, (void *)arg);
	}
}

void		bfs_for_resize(const t_ui_el *root, const void *arg)
{
	t_list *lst;

	lst = ft_lstnew(NULL, 0);
	lst->content = CAST_X_TO_Y(root, void *);
	bfs_resize_iter((const t_list *)lst, arg);
	free(lst);
}
