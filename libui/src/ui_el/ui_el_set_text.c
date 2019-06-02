/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 19:58:32 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/01 19:58:34 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_el_set_text(t_ui_main *m, t_ui_el *el, SDL_Color c, const char *font_id)
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
