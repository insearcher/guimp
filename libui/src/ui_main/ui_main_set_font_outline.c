/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_set_font_outline.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 21:34:05 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/07 21:41:42 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_set_font_outline(t_ui_main *m, const char *font_id, int outline)
{
	TTF_SetFontOutline(ui_main_get_font_by_id(m, font_id), outline);
}
