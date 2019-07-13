/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_for_find_el_by_id.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 03:01:35 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 05:49:57 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int  ui_win_check_el_by_id(void *el_v, Uint32 id)
{
	t_ui_el *el;

	el = (t_ui_el *)el_v;
	if (el->id == id)
		return (1);
	return (0);
}

static void	*bfs_find_el_by_id(const t_list *root, Uint32 id)
{
	QUEUE   *q;
	void    *tmp;
	void    *res;

	q = NULL;
	res = NULL;
	q_push(&q, (t_list *)root);
	while (q)
	{
		tmp = q_pop(&q);
		q_push(&q, CAST_X_TO_Y(tmp, t_ui_el *)->children);
		if (ui_win_check_el_by_id(tmp, id))
		{
			while (q)
				q_pop(&q);
			return (tmp);
		}
	}
	return (NULL);
}

t_ui_el		*bfs_for_find_el_by_id(const t_ui_el *root, Uint32 id)
{
	t_list  *lst;
	t_ui_el *res;

	lst = ft_lstnew(NULL, 0);
	lst->content = CAST_X_TO_Y(root, void *);
	res = CAST_X_TO_Y(bfs_find_el_by_id((const t_list *)lst, id), t_ui_el*);
	free(lst);
	return (res);
}
