/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 01:55:53 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/28 08:54:30 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int ui_el_set_text_for_modal_window(t_ui_main *m, t_ui_el *el,
		const char *font_id, t_text_params text_params)
{
	if (!(el->modal_win.font = ui_main_get_font_by_id(m, font_id)))
		return (FUNCTION_FAILURE);
	el->modal_win.text_color = text_params.text_color;
	el->modal_win.render_param = text_params.render_param;
	if (text_params.params & TEXT_IS_CENTERED)
		el->modal_win.params |= TEXT_IS_CENTERED;
	if (text_params.params & TEXT_IS_BIG)
		el->modal_win.params |= TEXT_IS_BIG;
	if (text_params.params & TEXT_IS_INPUTTING)
		el->modal_win.params |= TEXT_IS_INPUTTING;
	el->modal_win.bg_color = text_params.bg_color;
	el->params |= EL_IS_TEXT;
//	ui_el_update_text(el, "");
	return (FUNCTION_SUCCESS);
}

int ui_el_set_text(t_ui_main *m, t_ui_el *el, const char *font_id, t_text_params text_params)
{
	if (!(el->text.font = ui_main_get_font_by_id(m, font_id)))
		return (FUNCTION_FAILURE);
	el->text.max_text_size = text_params.max_text_size;
	el->text.text_color = text_params.text_color;
	el->text.render_param = text_params.render_param;
	if (text_params.params & TEXT_IS_CENTERED)
		el->text.params |= TEXT_IS_CENTERED;
	if (text_params.params & TEXT_IS_BIG)
		el->text.params |= TEXT_IS_BIG;
	if (text_params.params & TEXT_IS_INPUTTING)
		el->text.params |= TEXT_IS_INPUTTING;
	el->text.bg_color = text_params.bg_color;
	el->text.cursor_pos = 0;
	el->params |= EL_IS_TEXT;
	ui_el_update_text(el, "");
	return (FUNCTION_SUCCESS);
}
