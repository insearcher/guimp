/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 07:13:34 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/02 03:26:05 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp_test.h"

int	main()
{
	t_guimp	guimp;

	ui_sdl_init();
	ft_bzero((void *)(&guimp), sizeof(t_guimp));
	if (!(guimp.m = ui_main_init()))
	{
		printf("ui_main malloc error in struct guimp\n");
		return (0);
	}
	ui_main_fill_default_surfaces(guimp.m);
	ui_main_fill_default_fonts(guimp.m);
	ui_main_set_font_params(guimp.m, "neco", (t_font_params){0, 0, 1, 0});
	ui_main_add_function_by_id(guimp.m, ui_el_draw_event, "ui_el_draw_event");
	ui_main_add_function_by_id(guimp.m, draw_main_canvas_event, "draw_main_canvas_event");
	ui_main_add_function_by_id(guimp.m, ui_win_update_size, "ui_win_update_size");
	ui_main_add_function_by_id(guimp.m, ui_main_close_program, "ui_main_close_program");

	guimp.m->data = (void *)(&guimp);
	ui_main_from_json(guimp.m, "./src/test/main.json");

	guimp.w = ui_main_find_window_by_id(guimp.m, 0);

	t_ui_el *cur_el = ui_win_find_el_by_id(guimp.w, 1);
	cur_el->params |= EL_IS_TEXT;
	cur_el->params |= EL_IS_DEPENDENT;
	ui_el_set_text(guimp.m, cur_el, "CavePaintings",
			(t_text_params){(SDL_Color){255, 0, 0, 0}, (SDL_Color){0, 0, 0, 0},
			10, TEXT_IS_INPUTTING, 0});

	ui_main_loop(guimp.m);
}
