/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 01:48:27 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/27 23:38:30 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*cur;

	if (!lst || !f)
		return (NULL);
	cur = f(lst);
	new = cur;
	while (lst->next)
	{
		lst = lst->next;
		if (!(cur->next = f(lst)))
		{
			ft_lstdels(&new);
			return (NULL);
		}
		cur = cur->next;
	}
	return (new);
}
