/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_switch_radio.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:47:51 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/11 19:54:28 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_switch_radio(void *a1, void *a2)
{
	t_ui_main	*m;
	t_ui_el		*el;

	m = (t_ui_main *) a1;
	el = (t_ui_el *) a2;
	if (!(((t_ui_el *)el->children->content)->params & EL_IS_HIDDEN))
		((t_ui_el *)el->children->content)->params |= EL_IS_HIDDEN;
	else
		((t_ui_el *)el->children->content)->params &= ~EL_IS_HIDDEN;
}