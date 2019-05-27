/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 07:13:34 by sbecker           #+#    #+#             */
/*   Updated: 2019/05/27 07:40:18 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp_test.h"

int	main()
{
	t_guimp	guimp;

	ui_sdl_init();
	initialization_main_and_default_surfaces(&guimp);
	initialization_w1(&guimp);
	scroll_menu1(&guimp);
//	initialization_flex_menu1(&guimp);
//	initialization_popap_menu1(&guimp);
	ui_main_add_window(&(guimp.m), &(guimp.w1));
	ui_main_loop(&(guimp.m));
}
