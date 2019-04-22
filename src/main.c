/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:09:10 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/22 10:52:30 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

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

static void drag_test2(void *a1, void *a2)
{
	t_ui_el		*el;

	(void)a2;
	el = (t_ui_el *)a1;
	ui_el_set_rel_pos(el, el->frect.x, el->frect.y);
	// SDL_Log("%d %d\n", el->rect.x, el->rect.y);
	// el->frect.x = ((float)(m->sdl_event.motion.x - el->ptr_rel_pos.x);
	// el->frect.y = m->sdl_event.motion.y - el->ptr_rel_pos.y;
}

static void drag_test(void *a1, void *a2)
{
	t_ui_main	*m;
	t_ui_el		*el;
	int			x;
	int			y;

	m = (t_ui_main *)a1;
	el = (t_ui_el *)a2;
	x = m->sdl_event.motion.x - el->ptr_rel_pos.x;
	y = m->sdl_event.motion.y - el->ptr_rel_pos.y;
	if (x < el->parent->rect.x || y < el->parent->rect.y ||
		x + el->rect.w > el->parent->rect.x + el->parent->rect.w ||
		y + el->rect.h > el->parent->rect.y + el->parent->rect.h)
		return ;
	ui_el_set_abs_pos(el, x, y);
	bfs_iter_root(el, &drag_test2, NULL);
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
	ui_event_add_listener(&(w.events.onResize), &ui_win_update_size);
	ui_win_setup_default(&w);
	ui_win_create(&w);
	w.canvas.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_file(&(w.canvas), "test3.jpg", TID_DEFAULT);
	ui_el_add_empty_texture(&(w.canvas), w.canvas.rect.w, w.canvas.rect.h, TID_DRAW_TEXTURE);
	ui_event_add_listener(&(w.canvas.events.onRender), &draw_main_canvas_event);
	ui_event_add_listener(&(w.canvas.events.onPointerLeftButtonHold), &draw_dot);
	w.canvas.params = EL_IS_SCROLLABLE;
	ui_event_add_listener(&(w.canvas.events.onScrollUp), ui_log_el_scroll_up);
	ui_event_add_listener(&(w.canvas.events.onScrollDown), ui_log_el_scroll_down);

	t_ui_el el1;
	ui_el_init(&el1);
	ui_el_setup_default(&el1);
	ui_event_add_listener(&(el1.events.onRender), &ui_el_draw_event);
	ui_el_add_child(&(w.canvas), &el1);
	ui_el_set_abs_pos(&el1, 100, 100);
	ui_el_set_abs_size(&el1, 200, 200);

	// !!!!!!!!!!!!!!!!!!!!!!!!!!!
	el1.params |= EL_IS_DRAGGABLE;
	ui_event_add_listener(&(el1.events.onPointerLeftButtonPressed), &ui_el_begin_drag);
	ui_event_add_listener(&(el1.events.onPointerLeftButtonReleased), &ui_el_end_drag);
	ui_event_add_listener_front(&(el1.events.onPointerLeftButtonHold), &drag_test);
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!

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
	ui_event_add_listener(&(el2.events.onPointerStay), testOnPtrStay);

	el2.params |= EL_IS_DRAGGABLE;
	ui_event_add_listener(&(el2.events.onPointerLeftButtonPressed), &ui_el_begin_drag);
	ui_event_add_listener(&(el2.events.onPointerLeftButtonReleased), &ui_el_end_drag);
	ui_event_add_listener_front(&(el2.events.onPointerLeftButtonHold), &drag_test);

	t_ui_el el11;
	ui_el_init(&el11);
	ui_el_setup_default(&el11);
	ui_event_add_listener(&(el11.events.onRender), &ui_el_draw_event);
	ui_el_add_child(&el1, &el11);
	ui_el_set_abs_pos(&el11, 100, 100);
	ui_el_set_abs_size(&el11, 50, 50);

	// !!!!!!!!!!!!!!!!!!!!!!!!!!!
	el11.params |= EL_IS_DRAGGABLE;
	ui_event_add_listener(&(el11.events.onPointerLeftButtonPressed), &ui_el_begin_drag);
	ui_event_add_listener(&(el11.events.onPointerLeftButtonReleased), &ui_el_end_drag);
	ui_event_add_listener_front(&(el11.events.onPointerLeftButtonHold), &drag_test);
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!

	el11.id = 2220;
	el11.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_file(&el11, "test4.jpeg", TID_DEFAULT);
	ui_el_add_texture_from_file(&el11, "test.bmp", TID_ONFOCUSED);
	ui_el_add_texture_from_file(&el11, "test5.png", TID_ONACTIVE);
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
	ui_event_add_listener(&(w2.events.onResize), &ui_win_update_size);
	w2.canvas.sdl_renderer = (w2.sdl_renderer);
	ui_el_add_texture_from_file(&(w2.canvas), "test2.jpg", TID_DEFAULT);
	ui_event_add_listener(&(w2.canvas.events.onRender), &ui_el_draw_event);

	ui_main_add_window(&m, &w);
	ui_main_add_window(&m, &w1);
	ui_main_add_window(&m, &w2);

	ui_main_loop(&m);
	return (0);
}
