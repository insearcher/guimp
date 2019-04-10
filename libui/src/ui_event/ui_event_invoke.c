/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_event_invoke.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:38:40 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/10 10:46:40 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_event_invoke(t_ui_event *e, void *a1, void *a2)
{
	t_list		*node;
	func_ptr	f;

	node = e->events;
	while (node)
	{
		f = (func_ptr)(*((long *)node->content));
			(*f)(a1, a2);
		node = node->next;
	}
}
