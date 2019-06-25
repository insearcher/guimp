/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_children_set_default.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:22:26 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/25 19:46:57 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_children_set_default(void *a1, void *a2)
{
	t_list	*node;
	t_ui_el	*el;

	(void)a1;
	el = (t_ui_el *)a2;
	node = el->parent->children;
	while (node)
	{
		ui_el_set_current_texture_by_id((t_ui_el *)node->content, "default");
		node = node->next;
	}
	ui_el_set_current_texture_by_id(el, "onActive");
}