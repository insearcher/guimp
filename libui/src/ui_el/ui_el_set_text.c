/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_set_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 01:55:53 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/08 21:31:55 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int ui_el_set_text_for_modal_window(t_ui_main *m, t_ui_el *el,
		const char *font_id, t_text_params text_params)
{
	if (!(el->modal_win->font = ui_main_get_font_by_id(m, font_id)))
		return (FUNCTION_FAILURE);
	el->modal_win->text_color = text_params.text_color;
	el->modal_win->render_param = text_params.render_param;
	if (text_params.params & TEXT_IS_CENTERED)
		el->modal_win->params |= TEXT_IS_CENTERED;
	if (text_params.params & TEXT_IS_INPUTTING)
		el->modal_win->params |= TEXT_IS_INPUTTING;
	el->modal_win->bg_color = text_params.bg_color;
	return (FUNCTION_SUCCESS);
}

int ui_el_set_text(t_ui_main *m, t_ui_el *el, const char *font_id, t_text_params text_params)
{
	el->text_area = (t_ui_text *)ft_memalloc(sizeof(t_ui_text));
	if (!(el->text_area->font = ui_main_get_font_by_id(m, font_id)))
		return (FUNCTION_FAILURE);
	el->text_area->string_len = text_params.string_len;
	el->text_area->text_color = text_params.text_color;
	el->text_area->render_param = text_params.render_param;
	if (text_params.params & TEXT_IS_CENTERED)
		el->text_area->params |= TEXT_IS_CENTERED;
	if (text_params.params & TEXT_IS_INPUTTING)
		el->text_area->params |= TEXT_IS_INPUTTING;
	el->text_area->bg_color = text_params.bg_color;
//	el->text_area->cursor_pos = 0;
	el->params |= EL_IS_TEXT;
	ui_el_update_text(el, "");
	return (FUNCTION_SUCCESS);
}
