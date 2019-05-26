/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:57:14 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/24 19:07:00 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_set_default_texture(void *a1, void *a2)
{
	t_ui_el		*el;

	(void)a1;
	el = (t_ui_el *)a2;
	ui_el_set_current_texture_by_id(el, "default");
}

void	ui_el_set_focused_texture(void *a1, void *a2)
{
	t_ui_el		*el;

	(void)a1;
	el = (t_ui_el *)a2;
	ui_el_set_current_texture_by_id(el, "focused");
}

void	ui_el_set_active_texture(void *a1, void *a2)
{
	t_ui_el		*el;

	(void)a1;
	el = (t_ui_el *)a2;
	ui_el_set_current_texture_by_id(el, "active");
}
