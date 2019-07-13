/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_fill_default_functions.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:44:15 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/12 18:07:42 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

static void	add_choose_functions(t_ui_main *m)
{

	ui_main_add_function_by_id(m, choose_brush, "choose_brush");
	ui_main_add_function_by_id(m, choose_eraser, "choose_eraser");
	ui_main_add_function_by_id(m, choose_zoom, "choose_zoom");
	ui_main_add_function_by_id(m, choose_hand, "choose_hand");
	ui_main_add_function_by_id(m, choose_size, "choose_size");
	ui_main_add_function_by_id(m, choose_alpha, "choose_alpha");
	ui_main_add_function_by_id(m, choose_pipette, "choose_pipette");
	ui_main_add_function_by_id(m, choose_fill, "choose_fill");
	ui_main_add_function_by_id(m, choose_rect, "choose_rect");
	ui_main_add_function_by_id(m, choose_square, "choose_square");
	ui_main_add_function_by_id(m, choose_ellipse, "choose_ellipse");
	ui_main_add_function_by_id(m, choose_line, "choose_line");
	ui_main_add_function_by_id(m, choose_text, "choose_text");
	ui_main_add_function_by_id(m, choose_fill_mode, "choose_fill_mode");
	ui_main_add_function_by_id(m, choose_empty_mode, "choose_empty_mode");
	ui_main_add_function_by_id(m, choose_red_color, "choose_red_color");
	ui_main_add_function_by_id(m, choose_green_color, "choose_green_color");
	ui_main_add_function_by_id(m, choose_blue_color, "choose_blue_color");
}


void	ui_main_fill_default_functions(t_ui_main *m)
{
	ui_main_add_function_by_id(m, move_windows, "move_windows");
	ui_main_add_function_by_id(m, ui_win_update_size, "ui_win_update_size");
	ui_main_add_function_by_id(m, ui_main_close_program, "ui_main_close_program");
	ui_main_add_function_by_id(m, ui_main_close_window, "ui_main_close_window");
	add_choose_functions(m);
}
