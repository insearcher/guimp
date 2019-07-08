/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_add_child.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:55:52 by edraugr-          #+#    #+#             */
/*   Updated: 2019/07/08 23:15:23 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_el_add_child(t_ui_el *el, t_ui_el *child)
{
	t_list	*node;

	if (!(node = ft_lstnew(NULL, 0)))
		ui_sdl_deinit(228);
	child->parent = el;
	child->sdl_renderer = el->sdl_renderer;
	node->content = (void *)child;
	node->content_size = child->id;
	ft_lstadd_back(&(el->children), node);
	return (FUNCTION_SUCCESS);
}
