/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_init_opener_el.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 14:44:28 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/05 14:51:48 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_el_init_opener_el(t_ui_el *el, int type)
{
	if ((type & EL_MODAL_OK) || type == 0)
		el->params |= EL_MODAL_OK;
	if (!(el->modal_win = (t_ui_modal_win *)ft_memalloc(sizeof(t_ui_modal_win))))
		return (FUNCTION_FAILURE);
	return (FUNCTION_SUCCESS);
}
