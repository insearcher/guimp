/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_event_show_child.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 03:28:25 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 07:22:16 by sbecker          ###   ########.fr       */
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
		if (!(el->params & EL_IS_ICON))
			el->params |= (EL_IS_HIDDEN | EL_IGNOR_RAYCAST);
		node = node->next;
	}
}

void	ui_el_event_show_child(t_ui_main *m, void *a)
{
	t_list	*node;
	t_ui_el	*el;

	(void)m;
	el = (t_ui_el *)a;
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
		if (!(el->params & EL_IS_ICON))
			el->params &= ~(EL_IS_HIDDEN | EL_IGNOR_RAYCAST);
		node = node->next;
	}
}
