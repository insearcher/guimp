/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_event_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:16:15 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/27 17:31:23 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_event_add(t_event *e, void(*f)(const void *i))
{
	t_list	*node;

	if (e->root == NULL)
	{
		if ((e->root = ft_lstnew(f, sizeof(*f))) == NULL)
			return (1);
		return (0);
	}
	else
	{
		if ((node = ft_lstnew(f, sizeof(*f))) == NULL)
			return (1);
		ft_lstadd_back(&(e->root), node);
		return (0);
	}
}
