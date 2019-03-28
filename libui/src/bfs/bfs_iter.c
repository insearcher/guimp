/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:15:05 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/28 13:50:20 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void	draw_placeholder(void *el)
{
	char	*tmp;

	tmp = ft_itoa(CAST_X_TO_Y(tmp, t_ui_el *)->test);
	ft_putendl(tmp);
	free(tmp);
}

void		bfs_iter(const t_list *root, void(*f)(const void *arg))
{
	QUEUE	*q;
	void	*tmp;

	q = NULL;
	q_push(&q, root);
	while (*q)
	{
		tmp = q_pull(&q);
		q_push(&q, CAST_X_TO_Y(tmp, t_ui_el *)->children);
		f(tmp);
	}
}
