/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_fill_default_surfaces.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 05:03:28 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/24 19:03:25 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

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
}
