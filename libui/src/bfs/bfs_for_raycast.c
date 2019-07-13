/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_for_raycast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 02:40:16 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 05:50:26 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void	*bfs(t_ui_main *m, const t_list *root, pred_ptr p)
{
	QUEUE   *q;
	void    *tmp;
	void    *res;
	t_ui_el *cur_el;

	q = NULL;
	res = NULL;
	q_push(&q, (t_list *)root);
	while (q)
	{
		tmp = q_pop(&q);
		cur_el = (t_ui_el *)tmp;
		if (!(cur_el->params & EL_IGNOR_RAYCAST))
		{
			q_push(&q, CAST_X_TO_Y(tmp, t_ui_el *)->children);
			if (p && p(m, tmp))
				res = tmp;
		}
	}
	return (res);
}

t_ui_el		*bfs_for_raycast(t_ui_main *m, const t_ui_el *root, pred_ptr p)
{
	t_list  *lst;
	t_ui_el *res;

	lst = ft_lstnew(NULL, 0);
	lst->content = CAST_X_TO_Y(root, void *);
	res = CAST_X_TO_Y(bfs(m, (const t_list *)lst, p), t_ui_el *);
	free(lst);
	return (res);
}
