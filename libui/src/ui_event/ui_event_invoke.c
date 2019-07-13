/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_event_invoke.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:38:40 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/13 10:42:06 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_event_invoke(t_ui_event *e, t_ui_main *m, void *a)
{
	t_list			*node;
	pred_ptr_event	f;

	node = e->events;
	while (node)
	{
		if ((long)(node->next) < 20 && (long)(node->next) != 0)
		{
			node->next = node->next;
		}
		f = (pred_ptr_event)(*((long *)node->content));
		if (!((*f)(m, a)))
			return ;
		t_ui_win *w = (t_ui_win*)a; //for test
		(void)w;
/* 		if ((m->params & HUITA))
		{
			m->params &= ~HUITA;
			return ;
		}*/
		if ((long)(node->next) < 20 && (long)(node->next) != 0)
		{
			node->next = node->next;
		}
		node = node->next;
	}
}
