/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:09:10 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/04 06:31:18 by sbednar          ###   ########.fr       */
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
	w.canvas.rect.w = 640;
	w.canvas.rect.h = 480;
	w.params = WIN_MAIN | WIN_RESIZABLE;
	log_setup(&w);
	ui_event_add_listener(&(w.events.onClose), &test_for_main);
	w.canvas.id = 0;
	t_ui_el el1;
	ui_el_init(&el1);
	ui_event_add_listener(&(el1.events.onPointerEnter), &ui_log_el_pointer_enter);
	ui_event_add_listener(&(el1.events.onPointerExit), &ui_log_el_pointer_exit);
	ui_event_add_listener(&(el1.events.onPointerStay), &ui_log_el_pointer_stay);
	el1.rect.x = 100;
	el1.rect.y = 100;
	el1.rect.w = 200;
	el1.rect.h = 100;
	el1.id = 10;
	ui_el_add_child(&(w.canvas), &el1);
	t_ui_el el2;
	ui_el_init(&el2);
	ui_event_add_listener(&(el2.events.onPointerEnter), &ui_log_el_pointer_enter);
	ui_event_add_listener(&(el2.events.onPointerExit), &ui_log_el_pointer_exit);
	ui_event_add_listener(&(el2.events.onPointerStay), &ui_log_el_pointer_stay);
	el2.rect.x = 400;
	el2.rect.y = 400;
	el2.rect.w = 100;
	el2.rect.h = 100;
	el2.id = 20;
	ui_el_add_child(&(w.canvas), &el2);
	t_ui_el el11;
	ui_el_init(&el11);
	ui_event_add_listener(&(el11.events.onPointerEnter), &ui_log_el_pointer_enter);
	ui_event_add_listener(&(el11.events.onPointerExit), &ui_log_el_pointer_exit);
	ui_event_add_listener(&(el11.events.onPointerStay), &ui_log_el_pointer_stay);
	el11.rect.x = 100;
	el11.rect.y = 100;
	el11.rect.w = 100;
	el11.rect.h = 100;
	el11.id = 2220;
	ui_el_add_child(&el1, &el11);
	ui_win_create(&w);

	t_ui_win w1;
	ui_win_init(&w1);
	w1.title = ft_strdup("TEST2");
	w1.canvas.id = 0;
	w1.canvas.rect.w = 200;
	w1.canvas.rect.h = 100;
	w1.params = 0;
	log_setup(&w1);
	ui_event_add_listener(&(w1.events.onClose), &test_for_notmain);
	ui_win_create(&w1);

	t_ui_win w2;
	ui_win_init(&w2);
	w2.canvas.id = 0;
	w2.title = ft_strdup("TEST3");
	w2.canvas.rect.w = 200;
	w2.canvas.rect.h = 100;
	w2.params = WIN_RESIZABLE;
	log_setup(&w2);
	ui_event_add_listener(&(w2.events.onClose), &test_for_notmain);
	ui_win_create(&w2);

	ui_main_add_window(&m, &w);
	ui_main_add_window(&m, &w1);
	ui_main_add_window(&m, &w2);

	SDL_SetRenderDrawColor(w.sdl_renderer, 255, 0, 0, 255);
	SDL_RenderClear(w.sdl_renderer);
	SDL_RenderPresent(w.sdl_renderer);

	SDL_SetRenderDrawColor(w1.sdl_renderer, 0, 255, 0, 255);
	SDL_RenderClear(w1.sdl_renderer);
	SDL_RenderPresent(w1.sdl_renderer);

	SDL_SetRenderDrawColor(w2.sdl_renderer, 0, 0, 255, 255);
	SDL_RenderClear(w2.sdl_renderer);
	SDL_RenderPresent(w2.sdl_renderer);

	ui_main_loop(&m);
	return (0);
}
