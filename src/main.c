/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:09:10 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/15 10:58:27 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

// static void	test_for_notmain(void *a1, void *a2)
// {
// 	Uint32		windowID;
// 	t_ui_main	*m;

// 	m = (t_ui_main *)a1;
// 	windowID = *((Uint32 *)a2);
// 	ui_main_remove_window_by_id(m, windowID);
// }

// static void	test_for_main(void *a1, void *a2)
// {
// 	(void)a1;
// 	(void)a2;
// 	ui_sdl_deinit(EXIT_SUCCESS);
// }

static void find_new_size(void *a1, void *a2)
{
	t_ui_el	*el = (t_ui_el *)a1;
	(void)a2;

	if (!(el->params & EL_DYNAMIC_SIZE))
		return ;
	ui_el_set_rel_size(el, el->frect.w, el->frect.h);
}

static void find_dynamic_elements(void *a1, void *a2)
{
	t_ui_win	*w;

	w = (t_ui_win *)a2;
	(void)a1;
	if (w != NULL)
	{
		bfs_iter_root(&(w->canvas), &find_new_size, NULL);//w);
	}
}

static void update_window_size(void *a1, void *a2)
{
	t_ui_main	*m;
	t_ui_win	*w;
	Uint32		windowID;

	m = (t_ui_main *)a1;
	windowID = *((Uint32 *)a2);
	w = ui_main_find_window_by_id(m, windowID);
	if (w != NULL)
	{
		SDL_GetWindowSize(w->sdl_window, &(w->size.x), &(w->size.y));
		w->canvas.rect.w = w->size.x;
		w->canvas.rect.h = w->size.y;
		find_dynamic_elements(a1, (void *)w);
	}
}


static void	testOnPtrEnter(void *main, void *el)
{
	main = NULL;

	if (main == NULL)
	{
		ui_el_set_current_texture_by_id(CAST_X_TO_Y(el, t_ui_el *), TID_ONFOCUSED);
	}
}

static void	testOnPtrExit(void *main, void *el)
{
	main = NULL;

	if (main == NULL)
	{
		ui_el_set_current_texture_by_id(CAST_X_TO_Y(el, t_ui_el *), TID_DEFAULT);
	}
}

static void	testOnPtrLBDown(void *main, void *el)
{
	main = NULL;

	if (main == NULL)
	{
		ui_el_set_current_texture_by_id(CAST_X_TO_Y(el, t_ui_el *), TID_ONACTIVE);
	}
}

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

static void	testOnPtrLBHold(void *main, void *el_v)
{
	main = NULL;
	t_ui_el *el = (t_ui_el *)el_v;
	static int dx;
	static int dy;
	static int dur = 1;

	if (main == NULL)
	{
		if (dx > 50 || dx < -50)
			dur *= -1;
		dx += dur;
		dy += dur;
		el->rect.x += dur;
	}
}

int		main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	ui_sdl_init();

	t_ui_main m;
	ui_main_init(&m);

	t_ui_win w;
	ui_win_init(&w);
	w.title = ft_strdup("TEST1");
	w.params = WIN_MAIN | WIN_RESIZABLE;
	w.size = (t_vec2){640, 480};
	w.canvas.id = 0;
	ui_event_add_listener(&(w.events.onResize), &update_window_size);
	ui_win_setup_default(&w);
	ui_win_create(&w);
	w.canvas.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_file(&(w.canvas), "test3.jpg", TID_DEFAULT);
	ui_event_add_listener(&(w.canvas.events.onRender), &ui_el_draw_event);

	t_ui_el el1;
	ui_el_init(&el1);
	ui_el_setup_default(&el1);
	ui_event_add_listener(&(el1.events.onRender), &ui_el_draw_event);
	ui_el_add_child(&(w.canvas), &el1);
	ui_el_set_abs_pos(&el1, 100, 100);
	ui_el_set_abs_size(&el1, 200, 100);
	el1.params |= EL_DYNAMIC_SIZE;
	el1.id = 10;
	el1.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_file(&el1, "test2.jpg", TID_DEFAULT);

	t_ui_el el2;
	ui_el_init(&el2);
	ui_el_setup_default(&el2);
	ui_event_add_listener(&(el2.events.onRender), &ui_el_draw_event);
	ui_el_add_child(&(w.canvas), &el2);
	ui_el_set_abs_pos(&el2, 300, 300);
	ui_el_set_abs_size(&el2, 100, 100);
	el2.id = 20;
	el2.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_file(&el2, "test6.jpeg", TID_DEFAULT);
	ui_el_setup_default(&el2);
	ui_event_add_listener(&(el2.events.onPointerStay), testOnPtrStay);

	t_ui_el el11;
	ui_el_init(&el11);
	ui_el_setup_default(&el1);
	ui_event_add_listener(&(el11.events.onRender), &ui_el_draw_event);
	ui_el_add_child(&el1, &el11);
	ui_el_set_abs_pos(&el11, 100, 100);
	ui_el_set_abs_size(&el11, 100, 200);
	el11.id = 2220;
	el11.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_file(&el11, "test4.jpeg", TID_DEFAULT);
	ui_el_add_texture_from_file(&el11, "test.bmp", TID_ONFOCUSED);
	ui_el_add_texture_from_file(&el11, "test5.png", TID_ONACTIVE);
	ui_el_setup_default(&el11);
	ui_event_add_listener(&(el11.events.onPointerEnter), testOnPtrEnter);
	ui_event_add_listener(&(el11.events.onPointerExit), testOnPtrExit);
	ui_event_add_listener(&(el11.events.onPointerLeftButtonPressed), testOnPtrLBDown);
	ui_event_add_listener(&(el11.events.onPointerLeftButtonReleased), testOnPtrEnter);
	ui_event_add_listener(&(el11.events.onPointerLeftButtonHold), &testOnPtrLBHold);


	t_ui_win w1;
	ui_win_init(&w1);
	w1.title = ft_strdup("TEST2");
	w1.size = (t_vec2){200, 100};
	w1.canvas.id = 0;
	w1.params = 0;
	ui_win_create(&w1);
	ui_win_setup_default(&w1);
	w1.canvas.sdl_renderer = (w1.sdl_renderer);
	ui_el_add_texture_from_file(&(w1.canvas), "test2.jpg", TID_DEFAULT);
	ui_event_add_listener(&(w1.canvas.events.onRender), &ui_el_draw_event);


	t_ui_win w2;
	ui_win_init(&w2);
	w2.canvas.id = 0;
	w2.title = ft_strdup("TEST3");
	w2.size = (t_vec2){200, 100};
	w2.params = WIN_RESIZABLE;
	ui_win_create(&w2);
	ui_win_setup_default(&w2);
	ui_event_add_listener(&(w2.events.onResize), &update_window_size);
	w2.canvas.sdl_renderer = (w2.sdl_renderer);
	ui_el_add_texture_from_file(&(w2.canvas), "test2.jpg", TID_DEFAULT);
	ui_event_add_listener(&(w2.canvas.events.onRender), &ui_el_draw_event);

	ui_main_add_window(&m, &w);
	ui_main_add_window(&m, &w1);
	ui_main_add_window(&m, &w2);

	ui_main_loop(&m);
	return (0);
}
