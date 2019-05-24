/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_setup_text.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 05:40:57 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/24 19:01:28 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_el_setup_text(t_ui_main *m, t_ui_el *el, SDL_Color c, const char *font_id)
{
	t_ui_text	*t;

	if (!(t = (t_ui_text *)malloc(sizeof(t_ui_text))))
		return (FUNCTION_FAILURE);
	t->font = ui_main_get_font_by_id(m, font_id);
	t->color.a = c.a;
	t->color.b = c.b;
	t->color.g = c.g;
	t->color.r = c.r;
	el->data = t;
	return (FUNCTION_SUCCESS);
}
