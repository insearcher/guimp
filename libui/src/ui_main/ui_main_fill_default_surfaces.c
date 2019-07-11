/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_fill_default_surfaces.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 05:03:28 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/11 21:27:49 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void add_icons(t_ui_main *m)
{
	ui_main_add_surface_by_path(m, "images/brush_icon.png", "brush_icon");
	ui_main_add_surface_by_path(m, "images/fill_icon.png", "fill_icon");
	ui_main_add_surface_by_path(m, "images/zoom_icon.png", "zoom_icon");
	ui_main_add_surface_by_path(m, "images/eraser_icon.png", "eraser_icon");
	ui_main_add_surface_by_path(m, "images/text_icon.png", "text_icon");
	ui_main_add_surface_by_path(m, "images/hand_icon.png", "hand_icon");
	ui_main_add_surface_by_path(m, "images/pipette_icon.png", "pipette_icon");
	ui_main_add_surface_by_path(m, "images/save_icon.png", "save_icon");
	ui_main_add_surface_by_path(m, "images/open_file_icon.png", "open_icon");
	ui_main_add_surface_by_path(m, "images/filler.png", "filler_icon");
	ui_main_add_surface_by_path(m, "images/question_icon.png", "question_icon");
	ui_main_add_surface_by_path(m, "images/empty_circle_icon.png", "empty_circle_icon");
	ui_main_add_surface_by_path(m, "images/line_icon.png", "line_icon");
	ui_main_add_surface_by_path(m, "images/rect_icon.png", "rect_icon");
	ui_main_add_surface_by_path(m, "images/square_icon.png", "square_icon");
	ui_main_add_surface_by_path(m, "images/circle_icon.png", "circle_icon");
}

static void	add_brushes(t_ui_main *m)
{
	ui_main_add_surface_by_path(m, "images/brush_circle.png", "brush_circle");
	ui_main_add_surface_by_path(m, "images/brush_rect.png", "brush_rect");
	ui_main_add_surface_by_path(m, "images/brush_cloud.png", "brush_cloud");
	ui_main_add_surface_by_path(m, "images/brush_star.png", "brush_star");
}

void	ui_main_fill_default_surfaces(t_ui_main *m)
{
	ui_main_add_surface_by_path(m, "images/bl.png", "bl");
	ui_main_add_surface_by_path(m, "images/flower.png", "flower");
	ui_main_add_surface_by_path(m, "images/fractal_dick.png", "fractal_dick");
	ui_main_add_surface_by_path(m, "images/frolushka.jpeg", "frolushka");
	ui_main_add_surface_by_path(m, "images/priso.jpg", "priso");
	ui_main_add_surface_by_path(m, "images/prison.jpg", "prison");
	ui_main_add_surface_by_path(m, "images/test.bmp", "test");
	ui_main_add_surface_by_path(m, "images/test2.jpg", "test2");
	ui_main_add_surface_by_path(m, "images/test3.jpg", "test3");
	ui_main_add_surface_by_path(m, "images/test4.jpeg", "test4");
	ui_main_add_surface_by_path(m, "images/test5.png", "test5");
	ui_main_add_surface_by_path(m, "images/test6.jpeg", "test6");
	ui_main_add_surface_by_path(m, "images/test31.jpg", "test31");
	ui_main_add_surface_by_path(m, "images/layer_place.png", "layer_place");
	ui_main_add_surface_by_path(m, "images/layer_onPtr.png", "layer_onPtr");
	ui_main_add_surface_by_path(m, "images/layer_active.png", "layer_active");
	ui_main_add_surface_by_path(m, "images/new_layer.png", "new_layer_place");
	ui_main_add_surface_by_path(m, "images/tomb.jpg", "tomb");
	ui_main_add_surface_by_path(m, "images/brush.png", "brush");
	ui_main_add_surface_by_path(m, "images/pencil.png", "pencil_icon");
	ui_main_add_surface_by_path(m, "images/frolushka-meme.png", "frolushka_meme");
	ui_main_add_surface_by_path(m, "images/background.png", "background");
	add_icons(m);
	add_brushes(m);
}
