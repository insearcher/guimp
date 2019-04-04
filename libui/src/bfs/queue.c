/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:17:14 by edraugr-          #+#    #+#             */
/*   Updated: 2019/04/04 03:27:04 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	q_push(QUEUE **q, t_list *el)
{
	t_list	*tmp;

	if (!el || !q)
		return ;
	tmp = CAST_X_TO_Y(*q, t_list *);
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!tmp)
	{
		tmp = ft_lstnew(NULL, 0);
		tmp->content = el->content;
		el = el->next;
		*q = tmp;
	}
	while (el)
	{
		tmp->next = ft_lstnew(NULL, 0);
		tmp = tmp->next;
		tmp->content = el->content;
		el = el->next;
	}
}

void	*q_pop(QUEUE **q)
{
	void	*res;
	QUEUE	*tmp;

	if (!q || !*q)
		return (NULL);
	res = (*q)->content;
	tmp = *q;
	*q = (*q)->next;
	free(tmp);
	return (res);
}
