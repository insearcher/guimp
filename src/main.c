/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:09:10 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/29 18:33:03 by edraugr-         ###   ########.fr       */
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

int		main()
{
	t_guimp	g_main;
	t_ui_el	*tmp_el;
	t_ui_el	*tmp_el_p1;
	t_ui_el	*tmp_el_p2;



	/********/
	/* INIT */
	/********/
	ui_sdl_init();
	gm_init(&g_main);
	if (!(g_main.ui_main = (t_ui_main *)malloc(sizeof(t_ui_main))))
	{
		printf("ui_main malloc error in struct g_main\n");
		return (0);
	}
	ui_main_init(g_main.ui_main);
	ui_main_fill_default_surfaces(g_main.ui_main);
	g_main.ui_main->data = (void *)g_main;



	/************/
	/* MAIN_WIN */
	/************/
	if (!(g_main.main_win = (t_ui_win *)malloc(sizeof(t_ui_win))))
	{
		printf("main_win malloc error in struct g_main\n");
		return (0);
	}
	ui_win_init(g_main.main_win);
	g_main.main_win->title = ft_strdup("GUIMP");
	g_main.main_win->params = WIN_MAIN | WIN_RESIZABLE;
	g_main.main_win->size = (t_vec2){GM_MAIN_WIN_W, GM_MAIN_WIN_H};
	ui_win_setup_default(g_main.main_win);
	ui_win_create(g_main.main_win);
	ui_event_add_listener(&(g_main.main_win->events.onResize), &ui_win_update_size);
	ui_main_add_window(g_main.ui_main, g_main.main_win);
	g_main.main_win->canvas.id = 0;
	g_main.main_win->canvas.sdl_renderer = g_main.main_win->sdl_renderer;
	ui_el_add_texture_from_main_by_id(g_main.ui_main, &(g_main.main_win->canvas), 2, TID_DEFAULT);
	ui_el_add_empty_texture(
		&(g_main.main_win->canvas),
		g_main.main_win->canvas.rect.w,
		g_main.main_win->canvas.rect.h,
		TID_DRAW_TEXTURE);
	ui_event_add_listener(&(g_main.main_win->canvas.events.onRender), &draw_main_canvas_event);
	ui_event_add_listener(&(g_main.main_win->canvas.events.onPointerLeftButtonHold), &draw_dot);

	/*MAIN ELEM*/
		if (!(tmp_el = (t_ui_el *)malloc(sizeof(t_ui_el))))
		{
			printf("main_elem malloc error in canvas in main_win\n");
			return (0);
		}
		ui_el_init(tmp_el);
		ui_el_setup_default(tmp_el);
		ui_event_add_listener(&(tmp_el->events.onRender), &ui_el_draw_event);
		ui_el_add_child(&(g_main.main_win->canvas), tmp_el);
		ui_el_set_rel_pos(tmp_el, 0.05, 0.05);
		ui_el_set_rel_size(tmp_el, 0.9, 0.9);
		tmp_el->id = MAIN_WIN_DRAW_EL_ID;
		tmp_el->sdl_renderer = g_main.main_win->sdl_renderer;
		tmp_el->params |= EL_DYNAMIC_SIZE;
		ui_el_add_texture_from_main_by_id(g_main.ui_main, tmp_el, 1, TID_DEFAULT);



	/************/
	/* TOOL_WIN */
	/************/
	if (!(g_main.tool_win = (t_ui_win *)malloc(sizeof(t_ui_win))))
	{
		printf("tool_win malloc error in struct g_main\n");
		return (0);
	}
	ui_win_init(g_main.tool_win);
	g_main.tool_win->title = ft_strdup("TOOLS");
	g_main.tool_win->params = 0;
	g_main.tool_win->size = (t_vec2){GM_TOOL_WIN_W, GM_TOOL_WIN_H};
	ui_win_setup_default(g_main.tool_win);
	ui_win_create(g_main.tool_win);
	ui_main_add_window(g_main.ui_main, g_main.tool_win);
	g_main.tool_win->canvas.id = 0;
	g_main.tool_win->canvas.sdl_renderer = g_main.tool_win->sdl_renderer;
	ui_el_add_texture_from_main_by_id(g_main.ui_main, &(g_main.tool_win->canvas), 2, TID_DEFAULT);
	ui_event_add_listener(&(g_main.tool_win->canvas.events.onRender), &draw_main_canvas_event);

	/*DRAW BUTTONS SCROLLABLE MENU*/
		if (!(tmp_el_p1 = (t_ui_el *)malloc(sizeof(t_ui_el))))
		{
			printf("scrollable menu malloc error in canvas in tool_win\n");
			return (0);
		}
		ui_el_init(tmp_el_p1);
		ui_el_setup_default(tmp_el_p1);
		ui_event_add_listener(&(tmp_el_p1->events.onRender), &ui_el_draw_event);
		ui_el_add_child(&(g_main.tool_win->canvas), tmp_el_p1);
		ui_el_set_rel_pos(tmp_el_p1, 0.01, 0.01);
		ui_el_set_rel_size(tmp_el_p1, 0.98, 0.59);
		ui_el_setup_default_scroll_menu(tmp_el_p1);
		//tmp_el_p1->id = MAIN_WIN_DRAW_EL_ID;
		tmp_el_p1->sdl_renderer = g_main.tool_win->sdl_renderer;
		ui_el_add_texture_from_main_by_id(g_main.ui_main, tmp_el_p1, 3, TID_DEFAULT);

	/*SELECT BRUSH BUTTON*/
			if (!(tmp_el = (t_ui_el *)malloc(sizeof(t_ui_el))))
			{
				printf("draw_brush malloc error in scrollable menu in tool_win\n");
				return (0);
			}
			ui_el_init(tmp_el);
			ui_el_setup_default(tmp_el);
			ui_el_setup_default_scroll_menu_elem(tmp_el, tmp_el_p1);
			ui_event_add_listener(&(tmp_el->events.onRender), &ui_el_draw_event);
			ui_el_add_child(tmp_el_p1, tmp_el);
			ui_el_set_rel_pos(tmp_el, 0.1, 0.05);
			//TODO nizhe kostil nuzhno fixit`
			ui_el_set_abs_pos(tmp_el, tmp_el->parent->rect.x + tmp_el->rect.x, tmp_el->parent->rect.y + tmp_el->rect.y);
			ui_el_set_abs_size(tmp_el, GM_TOOL_WIN_W * 0.35, GM_TOOL_WIN_W * 0.35);
			//tmp_el->id = MAIN_WIN_DRAW_EL_ID;
			tmp_el->sdl_renderer = g_main.tool_win->sdl_renderer;
			ui_el_add_texture_from_main_by_id(g_main.ui_main, tmp_el, 1, TID_DEFAULT);

	/*ERASER BUTTON*/
			if (!(tmp_el = (t_ui_el *)malloc(sizeof(t_ui_el))))
			{
				printf("eraser_brush malloc error in scrollable menu in tool_win\n");
				return (0);
			}
			ui_el_init(tmp_el);
			ui_el_setup_default(tmp_el);
			ui_el_setup_default_scroll_menu_elem(tmp_el, tmp_el_p1);
			ui_event_add_listener(&(tmp_el->events.onRender), &ui_el_draw_event);
			ui_el_add_child(tmp_el_p1, tmp_el);
			ui_el_set_rel_pos(tmp_el, 0.55, 0.05);
			//TODO nizhe kostil nuzhno fixit`
			ui_el_set_abs_pos(tmp_el, tmp_el->parent->rect.x + tmp_el->rect.x, tmp_el->parent->rect.y + tmp_el->rect.y);
			ui_el_set_abs_size(tmp_el, GM_TOOL_WIN_W * 0.35, GM_TOOL_WIN_W * 0.35);
			//tmp_el->id = MAIN_WIN_DRAW_EL_ID;
			tmp_el->sdl_renderer = g_main.tool_win->sdl_renderer;
			ui_el_add_texture_from_main_by_id(g_main.ui_main, tmp_el, 1, TID_DEFAULT);

	/*SETTINGS MENU*/
		if (!(tmp_el_p1 = (t_ui_el *)malloc(sizeof(t_ui_el))))
		{
			printf("settings menu malloc error in canvas in tool_win\n");
			return (0);
		}
		ui_el_init(tmp_el_p1);
		ui_el_setup_default(tmp_el_p1);
		ui_event_add_listener(&(tmp_el_p1->events.onRender), &ui_el_draw_event);
		ui_el_add_child(&(g_main.tool_win->canvas), tmp_el_p1);
		ui_el_set_rel_pos(tmp_el_p1, 0.01, 0.61);
		ui_el_set_rel_size(tmp_el_p1, 0.98, 0.38);
		//tmp_el_p1->id = MAIN_WIN_DRAW_EL_ID;
		tmp_el_p1->sdl_renderer = g_main.tool_win->sdl_renderer;
		ui_el_add_texture_from_main_by_id(g_main.ui_main, tmp_el_p1, 4, TID_DEFAULT);

	/*SLIDER ROOT*/
			if (!(tmp_el = (t_ui_el *)malloc(sizeof(t_ui_el))))
			{
				printf("eraser_brush malloc error in scrollable menu in tool_win\n");
				return (0);
			}
			ui_el_init(tmp_el);
			ui_el_setup_default(tmp_el);
			ui_event_add_listener(&(tmp_el->events.onRender), &ui_el_draw_event);
			ui_el_add_child(tmp_el_p1, tmp_el);
			ui_el_set_rel_pos(tmp_el, 0.1, 0.49);
			//TODO nizhe kostil nuzhno fixit`
			ui_el_set_abs_pos(tmp_el, tmp_el->parent->rect.x + tmp_el->rect.x, tmp_el->parent->rect.y + tmp_el->rect.y);
			ui_el_set_rel_size(tmp_el, 0.8, 0.02);
			//tmp_el->id = MAIN_WIN_DRAW_EL_ID;
			tmp_el->sdl_renderer = g_main.tool_win->sdl_renderer;
			ui_el_add_texture_from_main_by_id(g_main.ui_main, tmp_el, 1, TID_DEFAULT);

	/*SLIDER HEAD*/
				if (!(tmp_el_p2 = (t_ui_el *)malloc(sizeof(t_ui_el))))
				{
					printf("eraser_brush malloc error in scrollable menu in tool_win\n");
					return (0);
				}
				ui_el_init(tmp_el_p2);
				ui_el_setup_default(tmp_el_p2);
				ui_event_add_listener(&(tmp_el_p2->events.onRender), &ui_el_draw_event);
				ui_el_add_child(tmp_el, tmp_el_p2);
				ui_el_set_rel_pos(tmp_el_p2, 0.5, -4.5);
				//TODO nizhe kostil nuzhno fixit`
				ui_el_set_abs_pos(tmp_el_p2, tmp_el_p2->parent->rect.x + tmp_el_p2->rect.x, tmp_el_p2->parent->rect.y + tmp_el_p2->rect.y);
				ui_el_set_rel_size(tmp_el_p2, 0.04, 10);
				//tmp_el_p2->id = MAIN_WIN_DRAW_EL_ID;
				tmp_el_p2->sdl_renderer = g_main.tool_win->sdl_renderer;
				ui_el_add_texture_from_main_by_id(g_main.ui_main, tmp_el_p2, 7, TID_DEFAULT);
				ui_el_setup_hor_draggable(tmp_el_p2);



	/*************/
	/* LAYER_WIN */
	/*************/
	if (!(g_main.layer_win = (t_ui_win *)malloc(sizeof(t_ui_win))))
	{
		printf("layer_win malloc error in struct g_main\n");
		return (0);
	}
	ui_win_init(g_main.layer_win);
	g_main.layer_win->title = ft_strdup("LAYERS");
	g_main.layer_win->params = 0;
	g_main.layer_win->size = (t_vec2){GM_LAYER_WIN_W, GM_LAYER_WIN_H};
	ui_win_setup_default(g_main.layer_win);
	ui_win_create(g_main.layer_win);
	ui_main_add_window(g_main.ui_main, g_main.layer_win);
	g_main.layer_win->canvas.id = 0;
	g_main.layer_win->canvas.sdl_renderer = g_main.layer_win->sdl_renderer;
	ui_el_add_texture_from_main_by_id(g_main.ui_main, &(g_main.layer_win->canvas), 2, TID_DEFAULT);
	ui_event_add_listener(&(g_main.layer_win->canvas.events.onRender), &draw_main_canvas_event);

	/*************/
	/* MAIN_LOOP */
	/*************/
	ui_main_loop(g_main.ui_main);
	return (0);
}
