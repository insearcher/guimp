/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:15:05 by edraugr-          #+#    #+#             */
/*   Updated: 2019/04/04 03:45:11 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void		bfs_iter(const t_list *root, void(*f)(const void *arg))
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

void			bfs_iter_root(const t_ui_el *root, void(*f)(const void *arg))
{
	t_list *lst;

	lst = ft_lstnew(NULL, 0);
	lst->content = CAST_X_TO_Y(root, void *);
	bfs_iter((const t_list *)lst, f);
	free(lst);
}

static void		*bfs(const t_list *root, int(*f)(const void *arg))
{
	QUEUE	*q;
	void	*tmp;
	void	*res;

	q = NULL;
	q_push(&q, (t_list *)root);
	while (q)
	{
		tmp = q_pop(&q);
		q_push(&q, CAST_X_TO_Y(tmp, t_ui_el *)->children);
		if (f)
			if(f(tmp))
				res = tmp;
	}
	return (res);
}

t_ui_el			*bfs_root(const t_ui_el *root, int(*f)(const void *arg))
{
	t_list	*lst;
	t_ui_el	*res;

	lst = ft_lstnew(NULL, 0);
	lst->content = CAST_X_TO_Y(root, void *);
	res = CAST_X_TO_Y(bfs((const t_list *)lst, f), t_ui_el *);
	free(lst);
	return (res);
}


