/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_default_pointer_enter.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 00:26:52 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/15 00:48:04 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_default_pointer_enter(void *a1, void *a2)
{
	t_ui_el		*el;

	(void)a1;
	el = (t_ui_el *)a2;
	el->params |= EL_IS_PTR_INSIDE;
}
