/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_fill_default_functions.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:44:15 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/21 18:58:16 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	ui_main_fill_default_functions(t_ui_main *m)
{
	ui_main_add_function_by_id(m, move_windows, "move_windows");
	ui_main_add_function_by_id(m, ui_win_update_size, "ui_win_update_size");
	ui_main_add_function_by_id(m, ui_main_close_program, "ui_main_close_program");
	ui_main_add_function_by_id(m, ui_main_close_window, "ui_main_close_window");
	//ui_main_add_function_by_id(m, start_zoom_in, "start_zoom_in");
	//ui_main_add_function_by_id(m, start_zoom_out, "start_zoom_out");
}
