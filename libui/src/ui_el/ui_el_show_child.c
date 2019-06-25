/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_show_child.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 22:13:22 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/25 19:46:57 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

// static void	ui_el_show_child2(t_ui_el **cur, t_ui_el *new)
// {
// 	if (*cur)
// 		(*cur)->params |= EL_IS_HIDDEN;

// 	SDL_Log("KEEEEEEEEEK %d", new->id);
// 	*cur = (t_ui_el *)new->children->content;
// 	(*cur)->params &= ~EL_IS_HIDDEN;
// }

static void	ui_el_hide_element(t_ui_el *el)
{
	t_list	*node;

	node = el->children;
	while (node)
	{
		el = (t_ui_el *)node->content;
		if (!(el->params & EL_IGNOR_RAYCAST))
			el->params |= EL_IS_HIDDEN;
		node = node->next;
	}
}

void	ui_el_show_child(void *a1, void *a2)
{
	t_list	*node;
	t_ui_el	*el;

	(void)a1;
	el = (t_ui_el *)a2;
	node = el->parent->children;
	while (node)
	{
		ui_el_hide_element((t_ui_el *)node->content);
		node = node->next;
	}
	node = el->children;
	while (node)
	{
		el = (t_ui_el *)node->content;
		el->params &= ~EL_IS_HIDDEN;
		node = node->next;
	}
}
