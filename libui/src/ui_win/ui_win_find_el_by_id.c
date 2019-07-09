/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_find_el_by_id.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 16:15:52 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/19 01:23:01 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int	ui_win_check_el_by_id(void *el_v, Uint32 id)
{
	t_ui_el	*el;

	el = (t_ui_el *)el_v;
	if (el->id == id)
		return (1);
	return (0);
}

static void		*bfs_find_el_by_id(const t_list *root, Uint32 id)
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

static t_ui_el	*bfs_root_find_el_by_id(const t_ui_el *root, Uint32 id)
{
	t_list  *lst;
	t_ui_el *res;

	lst = ft_lstnew(NULL, 0);
	lst->content = CAST_X_TO_Y(root, void *);
	res = CAST_X_TO_Y(bfs_find_el_by_id((const t_list *)lst, id), t_ui_el*);
	free(lst);
	return (res);
}

t_ui_el		*ui_win_find_el_by_id(t_ui_win *w, Uint32 id)
{
	if (w != NULL)
		return (bfs_root_find_el_by_id(w->canvas, id));
	return (NULL);
}
