/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_for_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 02:54:17 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 05:36:31 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int  check_border(t_ui_el *el)
{
	if (el->rect.x > el->parent->cut_rect.x + el->parent->cut_rect.w ||
			el->rect.x + el->rect.w < el->parent->cut_rect.x ||
			el->rect.y > el->parent->cut_rect.y + el->parent->cut_rect.h ||
			el->rect.y + el->rect.h < el->parent->cut_rect.y)
		return (0);
	return (1);
}

static void	bfs_iter_draw(t_ui_main *m, const t_list *root)
{
	QUEUE   *q;
	void    *tmp;
	t_ui_el *cur_el;

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
			ui_event_invoke(((t_ui_el *)tmp)->events->onRender, m, tmp);
		}
	}
}

void		bfs_for_draw(t_ui_main *m, const t_ui_el *root)
{
	t_list *lst;

	lst = ft_lstnew(NULL, 0);
	lst->content = CAST_X_TO_Y(root, void *);
	bfs_iter_draw(m, (const t_list *)lst);
	free(lst);
}
