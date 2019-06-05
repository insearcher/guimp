/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 07:13:34 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/05 04:18:37 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp_test.h"

int	main()
{
	t_guimp	guimp;
	t_ui_el	*el;

	ui_sdl_init();
	initialization_main_and_default_surfaces(&guimp);
	initialization_w1(&guimp);
	el1(&guimp);
	scroll_menu1(&guimp);
	el = ui_win_find_el_by_id(&(guimp.w1), 0);
	if (el != 0)
		printf("%d\n", el->rect.x);
	else
		printf("ulya /\\ox\n");
//	initialization_flex_menu1(&guimp);
//	initialization_popap_menu1(&guimp);
	ui_main_add_window(&(guimp.m), &(guimp.w1));
	ui_main_loop(&(guimp.m));
}
