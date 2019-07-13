/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_event_children_set_default.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 03:29:13 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 09:14:29 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_el_event_children_set_default(t_ui_main *m, void *a)
{
	t_list	*node;
	t_ui_el	*el;

	(void)m;
	el = (t_ui_el *)a;
	node = el->parent->children;
	while (node)
	{
		ui_el_set_current_texture_by_id((t_ui_el *)node->content, "default");
		node = node->next;
	}
	ui_el_set_current_texture_by_id(el, "onActive");
	return (1);
}
