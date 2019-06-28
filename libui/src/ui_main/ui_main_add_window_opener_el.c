/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_add_window_opener_el.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 06:26:44 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/28 07:51:53 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_main_add_window_opener_el(t_ui_main *m, t_ui_el *el)
{
	t_list	*node;

	if (!(node = ft_lstnew(NULL, 0)))
		return (FUNCTION_FAILURE);
	node->content = (void *)el;
	if (m->modal_win_els == NULL)
		m->modal_win_els = node;
	else
		ft_lstadd(&(m->modal_win_els), node);
	return (FUNCTION_SUCCESS);
}
