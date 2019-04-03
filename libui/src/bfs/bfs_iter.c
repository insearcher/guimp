/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:15:05 by edraugr-          #+#    #+#             */
/*   Updated: 2019/04/04 02:25:23 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	bfs_iter(const t_list *root, void(*f)(const void *arg))
{
	QUEUE	*q;
	void	*tmp;

	q = NULL;
	q_push(&q, (t_list *)root);
	while (q)
	{
		tmp = q_pop(&q);
		q_push(&q, CAST_X_TO_Y(tmp, t_ui_el *)->children);
		if (f)
			f(tmp);
	}
}

void	bfs_iter_root(const t_ui_el *root, void(*f)(const void *arg))
{
	t_list *lst;

	lst = ft_lstnew(NULL, 0);
	lst->content = CAST_X_TO_Y(root, void *);
	bfs_iter((const t_list *)lst, f);
	free(lst);
}

