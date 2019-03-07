/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 00:08:32 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/08 00:11:36 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*cur;

	if (!alst)
		return ;
	if (!(*alst))
		*alst = new;
	else
	{
		cur = *alst;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
}