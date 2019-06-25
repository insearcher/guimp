/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_fill_default_fonts.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 05:34:14 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/07 23:42:37 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_fill_default_fonts(t_ui_main *m)
{
	ui_main_add_font_by_path(m, "fonts/Duma-Bold.ttf", "DumaBold");
	ui_main_add_font_by_path(m, "fonts/HighTide.ttf", "HighTide");
	ui_main_add_font_by_path(m, "fonts/DiabloHeavy.ttf", "Diablo");
	ui_main_add_font_by_path(m, "fonts/NecoA29.ttf", "Neco");
	ui_main_add_font_by_path(m, "fonts/BonkOffset.ttf", "BonkOffset");
	ui_main_add_font_by_path(m, "fonts/BraveOldWorld.ttf", "BraveOldWorld");
	ui_main_add_font_by_path(m, "fonts/BodoniTwinsCaps.ttf", "BodoniTwinsCaps");
	ui_main_add_font_by_path(m, "fonts/DemocraticPeaceWarriors.ttf", "PeaceWarriors");
	ui_main_add_font_by_path(m, "fonts/CavePaintings.ttf", "CavePaintings");
	ui_main_add_font_by_path(m, "fonts/Crosses.ttf", "Crosses");
	ui_main_add_font_by_path(m, "fonts/Microsoft Sans Serif.ttf", "SansSerif");
}
