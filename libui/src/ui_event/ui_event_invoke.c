/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_event_invoke.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:38:40 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/13 05:47:05 by sbecker          ###   ########.fr       */
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
		f = (pred_ptr_event)(*((long *)node->content));
		(*f)(m, a);
		t_ui_win *w = (t_ui_win*)a; //for test
		(void)w;
		if ((m->params & HUITA))
		{
			m->params &= ~HUITA;
			return ;
		}
		node = node->next;
	}
}
