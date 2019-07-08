/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_setup_font_params.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 05:01:47 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/08 23:15:16 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_main_set_font_params(t_ui_main *m, const char *font_id, t_font_params params)
{
	TTF_Font	*font;

	if (!(font = ui_main_get_font_by_id(m, font_id)))
		ui_sdl_deinit(228);
	TTF_SetFontStyle(font, params.style);
	TTF_SetFontHinting(font, params.hinting);
	TTF_SetFontKerning(font, params.kerning);
	TTF_SetFontOutline(font, params.outline);
	return (FUNCTION_SUCCESS);
}
