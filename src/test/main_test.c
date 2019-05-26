/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 07:13:34 by sbecker           #+#    #+#             */
/*   Updated: 2019/05/26 17:48:41 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp_test.h"

int	main()
{
	t_guimp	guimp;

	t_list	*list;

//	ui_sdl_init();
	initialization_main_and_default_surfaces(&guimp);
	initialization_w1(&guimp);
	scroll_menu1(&guimp);
	list = guimp.w1.canvas.children;
	printf("1.1 %p\n", list);
	while (list)
	{
		printf("M1 elID: %d\n", ((t_ui_el *)list->content)->id);
		list = list->next;
	}
	printf("1.2 %p\n", list);
	printf("end\n");
	list = guimp.w1.canvas.children;
	printf("2.1 %p\n", list);
	while (list)
	{
		printf("M1 elID: %d\n", ((t_ui_el *)list->content)->id);
		list = list->next;
	}
	printf("2.2 %p\n", list);
	printf("end\n");
	list = guimp.w1.canvas.children;
	printf("3.1 %p\n", list);
	while (list)
	{
		printf("M1 elID: %d\n", ((t_ui_el *)list->content)->id);
		list = list->next;
	}
	printf("3.2%p\n", list);
	printf("end\n");
//	initialization_flex_menu1(&guimp);
//	initialization_popap_menu1(&guimp);
	ui_main_add_window(&(guimp.m), &(guimp.w1));
	printf("M canvas id: %d\n", guimp.w1.canvas.id);
	list = guimp.w1.canvas.children;
	while (list)
	{
		printf("M2 elID: %d\n", ((t_ui_el *)list->content)->id);
		list = list->next;
	}
//	ui_main_loop(&(guimp.m));
}
