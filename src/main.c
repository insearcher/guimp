/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:09:10 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/15 00:53:10 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

static void	test_for_notmain(void *a1, void *a2)
{
	Uint32		windowID;
	t_ui_main	*m;

	m = (t_ui_main *)a1;
	windowID = *((Uint32 *)a2);
	ui_main_remove_window_by_id(m, windowID);
}

static void	test_for_main(void *a1, void *a2)
{
	(void)a1;
	(void)a2;
	ui_sdl_deinit(EXIT_SUCCESS);
}

static void find_new_size(void *a1, void *a2)
{
	t_ui_el	*el = (t_ui_el *)a1;
	t_ui_win *w = (t_ui_win *)a2;

	if (!(el->params & EL_DYNAMIC_SIZE))
		return;
	el->rect.x = w->size.x * el->frect.x;
	el->rect.y = w->size.y * el->frect.y;
	el->rect.w = w->size.x * (el->frect.w - el->frect.x);
	el->rect.h = w->size.y * (el->frect.h - el->frect.y);
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
	}
	//refresh canvas
}

static void find_dynamic_elements(void *a1, void *a2)
{
	Uint32		windowID;
	t_ui_main	*m;
	t_ui_win	*w;

	m = (t_ui_main *)a1;
	windowID = *((Uint32 *)a2);
	w = ui_main_find_window_by_id(m, windowID);
	if (w != NULL)
	{
		bfs_iter_root(&(w->canvas), &find_new_size, w);
	}
}

// static void	draw_placeholder(const void *el)
// {
// 	char	*tmp;

// 	tmp = ft_itoa(CAST_X_TO_Y(el, t_ui_el *)->test);
// 	ft_putendl(tmp);
// 	free(tmp);
// }

static void test()
{
// 	t_ui_el *root = ui_el_init(NULL, NULL);
// 	t_list *lst = ft_lstnew(CAST_X_TO_Y(ui_el_init(root, NULL), const void *), sizeof(t_ui_el));
// 	ft_lstadd_back(&lst, ft_lstnew(CAST_X_TO_Y(ui_el_init(root, NULL), const void *), sizeof(t_ui_el)));
// 	ft_lstadd_back(&lst, ft_lstnew(CAST_X_TO_Y(ui_el_init(root, NULL), const void *), sizeof(t_ui_el)));
// 	ft_lstadd_back(&lst, ft_lstnew(CAST_X_TO_Y(ui_el_init(root, NULL), const void *), sizeof(t_ui_el)));
// 	ft_lstadd_back(&lst, ft_lstnew(CAST_X_TO_Y(ui_el_init(root, NULL), const void *), sizeof(t_ui_el)));
// 	ft_lstadd_back(&lst, ft_lstnew(CAST_X_TO_Y(ui_el_init(root, NULL), const void *), sizeof(t_ui_el)));
// 	int i = 1;
// 	t_list *tmp = lst;
// 	while(tmp)
// 	{
// 		CAST_X_TO_Y(tmp->content, t_ui_el *)->test = i;
// 		tmp = tmp->next;
// 		++i;
// 	}
// 	root->children = lst;

// 	root->test = 0;
// 	lst = ft_lstnew(CAST_X_TO_Y(ui_el_init(root, NULL), const void *), sizeof(t_ui_el));
// 	ft_lstadd_back(&lst, ft_lstnew(CAST_X_TO_Y(ui_el_init(root, NULL), const void *), sizeof(t_ui_el)));
// 	ft_lstadd_back(&lst, ft_lstnew(CAST_X_TO_Y(ui_el_init(root, NULL), const void *), sizeof(t_ui_el)));
// 	ft_lstadd_back(&lst, ft_lstnew(CAST_X_TO_Y(ui_el_init(root, NULL), const void *), sizeof(t_ui_el)));
// 	tmp = lst;
// 	i = 1;
// 	while(tmp)
// 	{
// 		CAST_X_TO_Y(tmp->content, t_ui_el *)->test = i * 10;
// 		tmp = tmp->next;
// 		++i;
// 	}
// 	CAST_X_TO_Y(root->children->next->next->content, t_ui_el *)->children = lst;

// 	lst = ft_lstnew(CAST_X_TO_Y(ui_el_init(root, NULL), const void *), sizeof(t_ui_el));
// 	ft_lstadd_back(&lst, ft_lstnew(CAST_X_TO_Y(ui_el_init(root, NULL), const void *), sizeof(t_ui_el)));
// 	ft_lstadd_back(&lst, ft_lstnew(CAST_X_TO_Y(ui_el_init(root, NULL), const void *), sizeof(t_ui_el)));
// 	ft_lstadd_back(&lst, ft_lstnew(CAST_X_TO_Y(ui_el_init(root, NULL), const void *), sizeof(t_ui_el)));
// 	tmp = lst;
// 	i = 1;
// 	while(tmp)
// 	{
// 		CAST_X_TO_Y(tmp->content, t_ui_el *)->test = i * 100;
// 		tmp = tmp->next;
// 		++i;
// 	}
// 	CAST_X_TO_Y(root->children->next->content, t_ui_el *)->children = lst;

// 	lst = ft_lstnew(CAST_X_TO_Y(ui_el_init(root, NULL), const void *), sizeof(t_ui_el));
// 	ft_lstadd_back(&lst, ft_lstnew(CAST_X_TO_Y(ui_el_init(root, NULL), const void *), sizeof(t_ui_el)));
// 	ft_lstadd_back(&lst, ft_lstnew(CAST_X_TO_Y(ui_el_init(root, NULL), const void *), sizeof(t_ui_el)));
// 	ft_lstadd_back(&lst, ft_lstnew(CAST_X_TO_Y(ui_el_init(root, NULL), const void *), sizeof(t_ui_el)));
// 	tmp = lst;
// 	i = 1;
// 	while(tmp)
// 	{
// 		CAST_X_TO_Y(tmp->content, t_ui_el *)->test = i * 1000;
// 		tmp = tmp->next;
// 		++i;
// 	}
// 	CAST_X_TO_Y((CAST_X_TO_Y(root->children->next->content, t_ui_el *)->children->next->content), t_ui_el *)->children = lst;

// 	// t_list *lst = ft_lstnew(NULL, 0);
// 	// lst->content = CAST_X_TO_Y(root, void *);
// 	bfs_iter_root(root, draw_placeholder);
}

void	log_setup(t_ui_win *w)
{
	ui_event_add_listener(&(w->events.onMouseMoved), &ui_log_mouse_motion);
	ui_event_add_listener(&(w->events.onMouseButtonDown), &ui_log_mouse_button_down);
	ui_event_add_listener(&(w->events.onMouseButtonUp), &ui_log_mouse_button_up);
	ui_event_add_listener(&(w->events.onFocusGained), &ui_log_window_focus_gained);
	ui_event_add_listener(&(w->events.onFocusLost), &ui_log_window_focus_lost);
	ui_event_add_listener(&(w->events.onResize), &ui_log_window_resized);
	ui_event_add_listener(&(w->events.onClose), &ui_log_window_closed);
}

static void ui_el_setup_default_events(t_ui_el *el)
{
	ui_event_add_listener(&(el->events.onPointerEnter), &ui_log_el_pointer_enter);
	ui_event_add_listener(&(el->events.onPointerEnter), &ui_el_default_pointer_enter);
	ui_event_add_listener(&(el->events.onPointerExit), &ui_log_el_pointer_exit);
	ui_event_add_listener(&(el->events.onPointerExit), &ui_el_default_pointer_exit);
	ui_event_add_listener(&(el->events.onPointerStay), &ui_log_el_pointer_stay);
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
		//el->rect.y += dur;
	}
}

int		main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	test();

	ui_sdl_init();

	t_ui_main m;
	ui_main_init(&m);

	t_ui_win w;
	ui_win_init(&w);
	w.title = ft_strdup("TEST1");
	w.params = WIN_MAIN | WIN_RESIZABLE;
	w.size.x = 640;
	w.size.y = 480;
	log_setup(&w);
	w.canvas.frect.x = 0;
	w.canvas.frect.y = 0;
	w.canvas.frect.w = 1;
	w.canvas.frect.h = 1;
	w.canvas.rect.w = w.size.x;
	w.canvas.rect.h = w.size.y;
	w.canvas.params = EL_DYNAMIC_SIZE;
	w.canvas.id = 0;
	ui_event_add_listener(&(w.events.onResize), &update_window_size);
	ui_event_add_listener(&(w.events.onResize), &find_dynamic_elements);
	ui_event_add_listener(&(w.events.onClose), &test_for_main);
	ui_win_create(&w);

	w.canvas.sdl_renderer = w.sdl_renderer;
	// ui_el_load_surface_from(&(w.canvas), "test3.jpg");
	// ui_el_create_texture(&(w.canvas));
	ui_el_add_texture_from_file(&(w.canvas), "test3.jpg", TID_DEFAULT);
	ui_event_add_listener(&(w.canvas.events.onRender), &ui_el_draw_event);

	t_ui_el el1;
	ui_el_init(&el1);
	ui_el_setup_default_events(&el1);
	ui_event_add_listener(&(el1.events.onRender), &ui_el_draw_event);
	el1.rect.x = 100;
	el1.rect.y = 100;
	el1.rect.w = 200;
	el1.rect.h = 100;
	el1.frect.x = 0.3;
	el1.frect.y = 0.3;
	el1.frect.w = 0.1;
	el1.frect.h = 0.1;
	//el1.params = EL_DYNAMIC_SIZE;
	el1.id = 10;
	el1.sdl_renderer = w.sdl_renderer;
	// ui_el_load_surface_from(&el1, "test2.jpg");
	// ui_el_create_texture(&el1);
	ui_el_add_texture_from_file(&el1, "test2.jpg", TID_DEFAULT);
	ui_el_add_child(&(w.canvas), &el1);

	t_ui_el el2;
	ui_el_init(&el2);
	ui_el_setup_default_events(&el2);
	ui_event_add_listener(&(el2.events.onRender), &ui_el_draw_event);
	el2.rect.x = 300;
	el2.rect.y = 300;
	el2.rect.w = 100;
	el2.rect.h = 100;
	el2.id = 20;
	el2.sdl_renderer = w.sdl_renderer;
	// ui_el_load_surface_from(&el2, "test3.jpg");
	// ui_el_create_texture(&el2);
	ui_el_add_texture_from_file(&el2, "test6.jpeg", TID_DEFAULT);
	ui_el_add_child(&(w.canvas), &el2);
	ui_el_setup_default_events(&el2);
	ui_event_add_listener(&(el2.events.onPointerStay), testOnPtrStay);
	//ui_event_add_listener(&(el2.events.onPointerLeftButtonHold), &testOnPtrLBHold);

	t_ui_el el11;
	ui_el_init(&el11);
	ui_el_setup_default_events(&el1);
	ui_event_add_listener(&(el11.events.onRender), &ui_el_draw_event);
	el11.rect.x = 100;
	el11.rect.y = 100;
	el11.rect.w = 100;
	el11.rect.h = 200;
	el11.id = 2220;
	el11.sdl_renderer = w.sdl_renderer;
	// ui_el_load_surface_from(&el11, "test4.jpeg");
	// ui_el_create_texture(&el11);
	ui_el_add_texture_from_file(&el11, "test4.jpeg", TID_DEFAULT);
	ui_el_add_texture_from_file(&el11, "test.bmp", TID_ONFOCUSED);
	ui_el_add_texture_from_file(&el11, "test5.png", TID_ONACTIVE);
	ui_el_setup_default_events(&el11);
	ui_event_add_listener(&(el11.events.onPointerEnter), testOnPtrEnter);
	ui_event_add_listener(&(el11.events.onPointerExit), testOnPtrExit);
	ui_event_add_listener(&(el11.events.onPointerLeftButtonPressed), testOnPtrLBDown);
	ui_event_add_listener(&(el11.events.onPointerLeftButtonReleased), testOnPtrEnter);
	ui_event_add_listener(&(el11.events.onPointerLeftButtonHold), &testOnPtrLBHold);
	//el11.params |= EL_IGNOR_RAYCAST;
	ui_el_add_child(&el1, &el11);


	t_ui_win w1;
	ui_win_init(&w1);
	w1.title = ft_strdup("TEST2");
	w1.size.x = 200;
	w1.size.y = 100;
	w1.canvas.id = 0;
	w1.canvas.rect.w = w1.size.x;
	w1.canvas.rect.h = w1.size.y;
	w1.params = 0;
	ui_win_create(&w1);
	w1.canvas.sdl_renderer = (w1.sdl_renderer);
	// ui_el_load_surface_from(&w1.canvas, "test2.jpg");
	// ui_el_create_texture(&w1.canvas);
	ui_el_add_texture_from_file(&(w1.canvas), "test2.jpg", TID_DEFAULT);
	ui_event_add_listener(&(w1.canvas.events.onRender), &ui_el_draw_event);

	log_setup(&w1);
	ui_event_add_listener(&(w1.events.onClose), &test_for_notmain);


	t_ui_win w2;
	ui_win_init(&w2);
	w2.canvas.id = 0;
	w2.title = ft_strdup("TEST3");
	w2.size.x = 200;
	w2.size.y = 100;
	w2.canvas.rect.w = 200;
	w2.canvas.rect.h = 100;
	w2.params = WIN_RESIZABLE;
	ui_win_create(&w2);
	w2.canvas.sdl_renderer = (w2.sdl_renderer);
	// ui_el_load_surface_from(&w2.canvas, "test2.jpg");
	// ui_el_create_texture(&w2.canvas);
	ui_el_add_texture_from_file(&(w2.canvas), "test2.jpg", TID_DEFAULT);
	ui_event_add_listener(&(w2.canvas.events.onRender), &ui_el_draw_event);

	log_setup(&w2);
	ui_event_add_listener(&(w2.events.onClose), &test_for_notmain);


	ui_main_add_window(&m, &w);
	ui_main_add_window(&m, &w1);
	ui_main_add_window(&m, &w2);

	// SDL_SetRenderDrawColor(w.sdl_renderer, 255, 0, 0, 255);
	// SDL_RenderClear(w.sdl_renderer);
	// SDL_RenderPresent(w.sdl_renderer);

	// SDL_SetRenderDrawColor(w1.sdl_renderer, 0, 255, 0, 255);
	// SDL_RenderClear(w1.sdl_renderer);
	// SDL_RenderPresent(w1.sdl_renderer);

	// SDL_SetRenderDrawColor(w2.sdl_renderer, 0, 0, 255, 255);
	// SDL_RenderClear(w2.sdl_renderer);
	// SDL_RenderPresent(w2.sdl_renderer);

	ui_main_loop(&m);
	return (0);
}
