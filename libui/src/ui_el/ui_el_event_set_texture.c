/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_event_set_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 07:28:18 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 07:28:21 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_event_set_default_texture(t_ui_main *m, void *a)
{
	t_ui_el		*el;

	(void)m;
	el = (t_ui_el *)a;
	ui_el_set_current_texture_by_id(el, "default");
}

void	ui_el_event_set_focused_texture(t_ui_main *m, void *a)
{
	t_ui_el		*el;

	(void)m;
	el = (t_ui_el *)a;
	ui_el_set_current_texture_by_id(el, "onFocus");
}

void	ui_el_event_set_active_texture(t_ui_main *m, void *a)
{
	t_ui_el		*el;

	(void)m;
	el = (t_ui_el *)a;
	ui_el_set_current_texture_by_id(el, "onActive");
}
