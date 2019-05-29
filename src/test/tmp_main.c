/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:36:15 by sbecker           #+#    #+#             */
/*   Updated: 2019/05/26 13:01:23 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp_test.h"

int main()
{
	t_ui_main m;
	ui_main_init(&m);
	ui_main_fill_default_surfaces(&m);

	t_ui_win w;
	ui_win_init(&w);
	w.title = ft_strdup("TEST1");
	w.params = WIN_MAIN | WIN_RESIZABLE;
	w.size = (t_vec2){1000, 600};
	ui_event_add_listener(&(w.events.onResize), &ui_win_update_size);
	ui_win_setup_default(&w);
	ui_win_create(&w);
	w.canvas.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_main_by_id(&m, &(w.canvas), "test3", "default");
	ui_el_add_empty_texture(&(w.canvas), w.canvas.rect.w, w.canvas.rect.h, "draw_texture");
	ui_event_add_listener(&(w.canvas.events.onRender), &draw_main_canvas_event);
	ui_event_add_listener(&(w.canvas.events.onPointerLeftButtonHold), &draw_dot);
	w.canvas.id = 0;

	t_ui_el el1;
	ui_el_setup_default(&el1);
	ui_el_add_child(&(w.canvas), &el1);
	el1.id = 1;
	ui_el_set_pos(&el1, &(w.canvas), POS_ABS | POS_PIXEL, (t_fvec2){0, 0});
	ui_el_set_size(&el1, &(w.canvas), SIZE_PIXEL, (t_fvec2){100, 100});
	el1.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_main_by_id(&m, &el1, "test31", "default");
	ui_el_setup_default_draggable(&el1);

	t_ui_el el2;
	ui_el_setup_default(&el2);
	ui_el_add_child(&(w.canvas), &el2);
	el2.id = 2;
	ui_el_set_pos(&el2, &(w.canvas), POS_ABS, (t_fvec2){0.2, 0});
	ui_el_set_size(&el2, &(w.canvas), SIZE_PIXEL, (t_fvec2){100, 100});
	el2.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_main_by_id(&m, &el2, "test4", "default");
	ui_el_setup_default_draggable(&el2);

	t_ui_el el3;
	ui_el_setup_default(&el3);
	ui_el_add_child(&(el2), &el3);
	el3.id = 3;
	ui_el_set_pos(&el3, &(w.canvas), 0, (t_fvec2){0.5, 0.5});
	ui_el_set_size(&el3, &(w.canvas), 0, (t_fvec2){0.5, 0.5});
	el3.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_main_by_id(&m, &el3, "prison", "default");
	ui_el_setup_default_draggable(&el3);

	t_ui_el el4;
	ui_el_setup_default(&el4);
	ui_el_add_child(&(el2), &el4);
	el4.id = 4;
	ui_el_set_pos(&el4, &(w.canvas), POS_PIXEL, (t_fvec2){50, 0});
	ui_el_set_size(&el4, &(w.canvas), 0, (t_fvec2){0.5, 0.5});
	el4.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_main_by_id(&m, &el4, "test2", "default");
	ui_el_setup_default_draggable(&el4);

	ui_main_add_window(&m, &w);
	ui_main_loop(&m);
	return (0);
}
