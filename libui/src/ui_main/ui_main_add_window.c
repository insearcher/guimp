/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_add_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 22:02:32 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/15 09:05:07 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_main_add_window(t_ui_main *m, t_ui_win *w)
{
	t_list	*node;

	// if (!(node = ft_lstnew((void *)w, sizeof(t_ui_win))))
	// 	return (FUNCTION_FAILURE);
	if (!(node = ft_lstnew(NULL, 0)))
		return (FUNCTION_FAILURE);
	node->content = (void *)w;
	if (m->windows == NULL)
		m->windows = node;
	else
		ft_lstadd(&(m->windows), node);
	return (FUNCTION_SUCCESS);
}
