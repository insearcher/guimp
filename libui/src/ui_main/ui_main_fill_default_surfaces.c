/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_fill_default_surfaces.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 05:03:28 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/23 05:18:50 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_main_fill_default_surfaces(t_ui_main *m)
{
	ui_main_add_surface_by_path(m, "images/bl.png", 1);
	ui_main_add_surface_by_path(m, "images/flower.png", 2);
	ui_main_add_surface_by_path(m, "images/fractal_dick.png", 3);
	ui_main_add_surface_by_path(m, "images/frolushka.jpeg", 4);
	ui_main_add_surface_by_path(m, "images/priso.jpg", 5);
	ui_main_add_surface_by_path(m, "images/prison.jpg", 6);
	ui_main_add_surface_by_path(m, "images/test.bmp", 7);
	ui_main_add_surface_by_path(m, "images/test2.jpg", 8);
	ui_main_add_surface_by_path(m, "images/test3.jpg", 9);
	ui_main_add_surface_by_path(m, "images/test4.jpeg", 10);
	ui_main_add_surface_by_path(m, "images/test5.png", 11);
	ui_main_add_surface_by_path(m, "images/test6.jpeg", 12);
	ui_main_add_surface_by_path(m, "images/test31.jpg", 13);
}
