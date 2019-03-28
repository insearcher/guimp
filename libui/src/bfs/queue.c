/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:17:14 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/28 12:19:00 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	q_push(QUEUE **q, t_list *el)
{
	t_list	*tmp;

	if (!el || !*el || !q)
		return ;
	tmp = CAST_X_TO_Y(*q, t_list *);
	while (*tmp && tmp->next)
		tmp = tmp->next;
	if (!*tmp)
	{
		tmp = ft_lstnew(&(el->content), sizeof(char *));
		el = el->next;
	}
	while (el)
	{
		tmp->next = ft_lstnew(&(el->content), sizeof(char *));
		el = el->next;
		tmp = tmp->next;
	}
}

void	*q_pull(QUEUE **q)
{
	void	*res;
	QUEUE	*tmp;

	if (!q || !*q || !**q)
		return (NULL);
	res = *((*q)->content);
	tmp = *q;
	*q = (*q)->next;
	free(tmp->content);
	free(tmp);
	return (res);
}
