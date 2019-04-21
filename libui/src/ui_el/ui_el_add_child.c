/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_add_child.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:55:52 by edraugr-          #+#    #+#             */
/*   Updated: 2019/04/15 06:40:12 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_el_add_child(t_ui_el *el, t_ui_el *child)
{
	t_list	*node;

	if ((node = ft_lstnew(NULL, 0)) == NULL)
		return (FUNCTION_FAILURE);
	child->parent = el;
	node->content = (void *)child;
	ft_lstadd_back(&(el->children), node);
	return (FUNCTION_SUCCESS);
}
