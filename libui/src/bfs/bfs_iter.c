/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:15:05 by edraugr-          #+#    #+#             */
/*   Updated: 2019/05/23 12:10:15 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void			bfs_iter(const t_list *root, const func_ptr f,
		const void *arg)
{
	QUEUE	*q;
	void	*tmp;

	q = NULL;
	q_push(&q, (t_list *)root);
	if (f)
		while (q)
		{
			tmp = q_pop(&q);
			q_push(&q, CAST_X_TO_Y(tmp, t_ui_el *)->children);
			f(tmp, (void *)arg);
		}
	else
		while (q)
		{
			tmp = q_pop(&q);
			if (!(((t_ui_el *)tmp)->params & EL_IS_HIDDEN))
			{
				q_push(&q, CAST_X_TO_Y(tmp, t_ui_el *)->children);
				ui_event_invoke(&(((t_ui_el *)tmp)->events.onRender), tmp, (void *)arg);
			}
		}
}

void			bfs_iter_root(const t_ui_el *root, const func_ptr f,
		const void *arg)
{
	t_list *lst;

	lst = ft_lstnew(NULL, 0);
	lst->content = CAST_X_TO_Y(root, void *);
	bfs_iter((const t_list *)lst, f, arg);
	free(lst);
}

void			*bfs(t_ui_main *m, const t_list *root, pred_ptr p)
{
	QUEUE	*q;
	void	*tmp;
	void	*res;

	q = NULL;
	res = NULL;
	q_push(&q, (t_list *)root);
	while (q)
	{
		tmp = q_pop(&q);
		if (!(((t_ui_el *)tmp)->params & EL_IGNOR_RAYCAST))
		{
			q_push(&q, CAST_X_TO_Y(tmp, t_ui_el *)->children);
			if (p && p(m, tmp))
				res = tmp;
		}
	}
	return (res);
}

t_ui_el			*bfs_root(t_ui_main *m, const t_ui_el *root, pred_ptr p)
{
	t_list	*lst;
	t_ui_el	*res;

	lst = ft_lstnew(NULL, 0);
	lst->content = CAST_X_TO_Y(root, void *);
	res = CAST_X_TO_Y(bfs(m, (const t_list *)lst, p), t_ui_el *);
	free(lst);
	return (res);
}
