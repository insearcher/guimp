/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:09:10 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/24 19:25:13 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

static void	testOnPtrStay(void *main, void *el_v)
{
	main = NULL;
	t_ui_el *el = (t_ui_el *)el_v;
	static int dist = 1;
	static int dsize;

	if (main == NULL)
	{
		dsize += dist;
		if (dsize > 200 || dsize == 0)
			dist *= -1;
		el->rect.w += 2 * dist;
		el->rect.h += 2 * dist;
		el->rect.x -= dist;
		el->rect.y -= dist;
	}
}

static void	test(void *main, void *el_v)
{
	main = NULL;
	t_ui_el *el = (t_ui_el *)el_v;
	t_ui_el *text = (t_ui_el *)el->data;
	ui_el_update_text(text, "FROM 7 ZALOOP");
}

// static void	testOnPtrLBHold(void *main, void *el_v)
// {
// 	main = NULL;
// 	t_ui_el *el = (t_ui_el *)el_v;
// 	static int dx;
// 	static int dy;
// 	static int dur = 1;

// 	if (main == NULL)
// 	{
// 		if (dx > 50 || dx < -50)
// 			dur *= -1;
// 		dx += dur;
// 		dy += dur;
// 		el->rect.x += dur;
// 	}
// }

int		main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	ui_sdl_init();

	t_ui_main m;
	ui_main_init(&m);
	ui_main_fill_default_surfaces(&m);

	t_ui_win w;
	ui_win_init(&w);
	w.title = ft_strdup("TEST1");
	w.params = WIN_MAIN | WIN_RESIZABLE;
	w.size = (t_vec2){800, 600};
	w.canvas.id = 0;
	ui_event_add_listener(&(w.events.onResize), &ui_win_update_size);
	ui_win_setup_default(&w);
	ui_win_create(&w);
	w.canvas.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_main_by_id(&m, &(w.canvas), "test3", "default");
	// ui_el_add_texture_from_file(&(w.canvas), "images/test3.jpg", TID_DEFAULT);
	ui_el_add_empty_texture(&(w.canvas), w.canvas.rect.w, w.canvas.rect.h, "draw_texture");
	ui_event_add_listener(&(w.canvas.events.onRender), &draw_main_canvas_event);
	ui_event_add_listener(&(w.canvas.events.onPointerLeftButtonHold), &draw_dot);

	t_ui_el el1;
	ui_el_init(&el1);
	ui_el_setup_default(&el1);
	ui_event_add_listener(&(el1.events.onRender), &ui_el_draw_event);
	ui_el_add_child(&(w.canvas), &el1);
	ui_el_set_abs_pos(&el1, 50, 400);
	ui_el_set_abs_size(&el1, 150, 150);
	el1.id = 10;
	el1.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_main_by_id(&m, &el1, "test2", "default");
	// ui_el_add_texture_from_file(&el1, "images/test2.jpg", TID_DEFAULT);
	ui_el_setup_default_draggable(&el1);
	ui_el_set_relative_pos_and_size(&el1);

	t_ui_el el2;
	ui_el_init(&el2);
	ui_el_setup_default(&el2);
	ui_event_add_listener(&(el2.events.onRender), &ui_el_draw_event);
	ui_el_add_child(&(w.canvas), &el2);
	ui_el_set_abs_pos(&el2, 300, 300);
	ui_el_set_abs_size(&el2, 100, 100);
	el2.id = 20;
	el2.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_main_by_id(&m, &el2, "test7", "default");
	ui_event_add_listener(&(el2.events.onPointerStay), testOnPtrStay);
	ui_el_setup_default_draggable(&el2);
	ui_el_set_relative_pos_and_size(&el2);


	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	t_ui_el el_scroll_menu;
	ui_el_init(&el_scroll_menu);
	ui_el_setup_default(&el_scroll_menu);
	ui_event_add_listener(&(el_scroll_menu.events.onRender), &ui_el_draw_event);
	ui_el_add_child(&(w.canvas), &el_scroll_menu);
	ui_el_set_abs_pos(&el_scroll_menu, 500, 100);
	ui_el_set_abs_size(&el_scroll_menu, 300, 400);
//	el_scroll_menu.params |= EL_IS_HIDDEN;
	ui_el_setup_default_scroll_menu(&el_scroll_menu);
	el_scroll_menu.id = 3;
	el_scroll_menu.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_main_by_id(&m, &el_scroll_menu, "flower", "default");
	ui_el_add_texture_from_file(&el_scroll_menu, "images/flower.png", "default");
	ui_el_set_relative_pos_and_size(&el_scroll_menu);


	t_ui_el el_scroll_elem1;
	ui_el_init(&el_scroll_elem1);
	ui_el_setup_default(&el_scroll_elem1);
	ui_el_setup_default_scroll_menu_elem(&el_scroll_elem1, &el_scroll_menu);
	ui_event_add_listener(&(el_scroll_elem1.events.onRender), &ui_el_draw_event);
	ui_el_set_abs_pos(&el_scroll_elem1, 550, 100);
	ui_el_set_abs_size(&el_scroll_elem1, 200, 100);
	el_scroll_elem1.id = 31;
	el_scroll_elem1.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_file(&el_scroll_elem1, "images/fractal_dick.png", "default");
	ui_el_set_relative_pos_and_size(&el_scroll_elem1);

	t_ui_el el_scroll_elem2;
	ui_el_init(&el_scroll_elem2);
	ui_el_setup_default(&el_scroll_elem2);
	ui_el_setup_default_scroll_menu_elem(&el_scroll_elem2, &el_scroll_menu);
	ui_event_add_listener(&(el_scroll_elem2.events.onRender), &ui_el_draw_event);
	ui_el_set_abs_pos(&el_scroll_elem2, 550, 210);
	ui_el_set_abs_size(&el_scroll_elem2, 200, 100);
	el_scroll_elem2.id = 32;
	el_scroll_elem2.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_main_by_id(&m, &el_scroll_elem2, "fractal_dick", "default");
	ui_el_set_relative_pos_and_size(&el_scroll_elem2);

	t_ui_el el_button_for_scroll_elem2;
	ui_el_init(&el_button_for_scroll_elem2);
	ui_el_setup_default(&el_button_for_scroll_elem2);
	ui_el_setup_default_scroll_menu_elem(&el_button_for_scroll_elem2, &el_scroll_elem2);
	ui_event_add_listener(&(el_button_for_scroll_elem2.events.onRender), &ui_el_draw_event);
	ui_el_set_abs_pos(&el_button_for_scroll_elem2, 550, 210);
	ui_el_set_abs_size(&el_button_for_scroll_elem2, 100, 100);
	el_button_for_scroll_elem2.id = 302;
	el_button_for_scroll_elem2.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_main_by_id(&m, &el_button_for_scroll_elem2, "bl", "default");
	ui_el_set_relative_pos_and_size(&el_button_for_scroll_elem2);

	t_ui_el el_scroll_elem3;
	ui_el_init(&el_scroll_elem3);
	ui_el_setup_default(&el_scroll_elem3);
	ui_el_setup_default_scroll_menu_elem(&el_scroll_elem3, &el_scroll_menu);
	ui_event_add_listener(&(el_scroll_elem3.events.onRender), &ui_el_draw_event);
	ui_el_set_abs_pos(&el_scroll_elem3, 550, 320);
	ui_el_set_abs_size(&el_scroll_elem3, 200, 100);
	el_scroll_elem3.id = 33;
	el_scroll_elem3.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_main_by_id(&m, &el_scroll_elem3, "fractal_dick", "default");
	ui_el_set_relative_pos_and_size(&el_scroll_elem3);

	t_ui_el el_scroll_elem4;
	ui_el_init(&el_scroll_elem4);
	ui_el_setup_default(&el_scroll_elem4);
	ui_el_setup_default_scroll_menu_elem(&el_scroll_elem4, &el_scroll_menu);
	ui_event_add_listener(&(el_scroll_elem4.events.onRender), &ui_el_draw_event);
	ui_el_set_abs_pos(&el_scroll_elem4, 550, 430);
	ui_el_set_abs_size(&el_scroll_elem4, 200, 100);
	el_scroll_elem4.id = 34;
	el_scroll_elem4.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_main_by_id(&m, &el_scroll_elem4, "fractal_dick", "default");
	ui_el_set_relative_pos_and_size(&el_scroll_elem4);

	t_ui_el el_scroll_elem5;
	ui_el_init(&el_scroll_elem5);
	ui_el_setup_default(&el_scroll_elem5);
	ui_el_setup_default_scroll_menu_elem(&el_scroll_elem5, &el_scroll_menu);
	ui_event_add_listener(&(el_scroll_elem5.events.onRender), &ui_el_draw_event);
	ui_el_set_abs_pos(&el_scroll_elem5, 550, 540);
	ui_el_set_abs_size(&el_scroll_elem5, 200, 100);
	el_scroll_elem5.id = 35;
	el_scroll_elem5.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_main_by_id(&m, &el_scroll_elem5, "fractal_dick", "default");
	ui_el_set_relative_pos_and_size(&el_scroll_elem5);

	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	t_ui_el el11;
	ui_el_init(&el11);
	ui_el_setup_default(&el11);
	ui_event_add_listener(&(el11.events.onRender), &ui_el_draw_event);
	ui_el_add_child(&el1, &el11);
	ui_el_set_abs_pos(&el11, 0, 0);
	ui_el_set_abs_size(&el11, 100, 100);
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!
	// ui_el_setup_default_draggable(&el11);
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!
	el11.id = 2220;
	el11.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_main_by_id(&m, &el11, "test4", "default");
	ui_el_add_texture_from_main_by_id(&m, &el11, "test", "focused");
	ui_el_add_texture_from_main_by_id(&m, &el11, "test5", "active");
	ui_event_add_listener(&(el11.events.onPointerEnter), &ui_el_set_focused_texture);
	ui_event_add_listener(&(el11.events.onPointerExit), &ui_el_set_default_texture);
	ui_event_add_listener(&(el11.events.onPointerLeftButtonPressed), &ui_el_set_active_texture);
	ui_event_add_listener(&(el11.events.onPointerLeftButtonReleased), &ui_el_set_focused_texture);
	// ui_event_add_listener(&(el11.events.onPointerLeftButtonHold), &testOnPtrLBHold);
	ui_el_set_relative_pos_and_size(&el11);


	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// ui_el_text_change_text
	// ui_el_text_update_texture
	t_ui_el el222;
	ui_el_init(&el222);
	ui_el_setup_default(&el222);
	ui_event_add_listener(&(el222.events.onRender), &ui_el_draw_event);
	ui_el_add_child(&w.canvas, &el222);
	ui_el_set_abs_pos(&el222, 300, 100);
	ui_el_set_abs_size(&el222, 200, 100);
	ui_main_add_font_by_path(&m, "libui/content/Aller_Rg.ttf", 1);
	el222.sdl_renderer = w.sdl_renderer;
	ui_el_setup_text(&m, &el222, (SDL_Color){255, 255, 255, 255}, 1);
	ui_el_update_text(&el222, "LOOP");
	el11.data = &el222;
	ui_event_add_listener(&(el11.events.onPointerRightButtonPressed), &test);
	ui_el_set_relative_pos_and_size(&el222);

	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	t_ui_win w1;
	ui_win_init(&w1);
	w1.title = ft_strdup("TEST2");
	w1.size = (t_vec2){200, 100};
	w1.canvas.id = 0;
	w1.params = 0;
	ui_win_create(&w1);
	ui_win_setup_default(&w1);
	w1.canvas.sdl_renderer = (w1.sdl_renderer);
	ui_el_add_texture_from_main_by_id(&m, &(w1.canvas), "test2", "default");
	ui_event_add_listener(&(w1.canvas.events.onRender), &ui_el_draw_event);


	t_ui_win w2;
	ui_win_init(&w2);
	w2.canvas.id = 0;
	w2.title = ft_strdup("TEST3");
	w2.size = (t_vec2){200, 100};
	w2.params = WIN_RESIZABLE;
	ui_win_create(&w2);
	ui_win_setup_default(&w2);
	ui_event_add_listener(&(w2.events.onResize), &ui_win_update_size);
	w2.canvas.sdl_renderer = (w2.sdl_renderer);
	ui_el_add_texture_from_main_by_id(&m, &(w2.canvas), "test2", "default");
	ui_event_add_listener(&(w2.canvas.events.onRender), &ui_el_draw_event);

	ui_main_add_window(&m, &w);
	ui_main_add_window(&m, &w1);
	ui_main_add_window(&m, &w2);

	ui_main_loop(&m);
	return (0);
}
