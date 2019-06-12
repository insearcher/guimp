/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 01:55:53 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/12 05:41:13 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int ui_el_set_text(t_ui_main *m, t_ui_el *el, const char *font_id, t_text_params params)
{
	if (!(el->text.font = ui_main_get_font_by_id(m, font_id)))
		return (FUNCTION_FAILURE);
	el->text.max_text_size = params.max_text_size;
	el->text.text_color = params.text_color;
	el->text.render_param |= params.render_param;
	if (params.is_text_centered == 1)
		el->text.params |= TEXT_IS_CENTERED;
	el->text.bg_color = params.bg_color;
	el->text.cursor_pos = 0;
	el->params |= EL_IS_TEXT;
	return (FUNCTION_SUCCESS);
}
