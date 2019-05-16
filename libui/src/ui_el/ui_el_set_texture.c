/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:57:14 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/07 04:45:35 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_set_default_texture(void *a1, void *a2)
{
	t_ui_el		*el;

	(void)a1;
	el = (t_ui_el *)a2;
	ui_el_set_current_texture_by_id(el, TID_DEFAULT);
}

void	ui_el_set_focused_texture(void *a1, void *a2)
{
	t_ui_el		*el;

	(void)a1;
	el = (t_ui_el *)a2;
	ui_el_set_current_texture_by_id(el, TID_ONFOCUSED);
}

void	ui_el_set_active_texture(void *a1, void *a2)
{
	t_ui_el		*el;

	(void)a1;
	el = (t_ui_el *)a2;
	ui_el_set_current_texture_by_id(el, TID_ONACTIVE);
}
