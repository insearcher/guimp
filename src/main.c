/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:09:10 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/25 20:46:40 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void move_windows(void *a1, void *a2)
{
	t_ui_main   *m;
	t_ui_win    *w;
	t_list      *list;
	t_ui_win    *cur_w;
	t_vec2      pos;

	m = (t_ui_main *)a1;
	w = (t_ui_win *)a2;
	if (w != NULL)
	{
		list = m->windows;
		while (list)
		{
			cur_w = (t_ui_win *)list->content;
			if (cur_w->id == w->id)
			{
				list = list->next;
				continue;
			}
			SDL_GetWindowPosition(w->sdl_window, &pos.x, &pos.y);
			if (cur_w->id == 0)
				pos.x = pos.x + GM_TOOL_WIN_W + 5;
			else
				pos.x = pos.x - GM_TOOL_WIN_W - 5;
			// printf("id: %d, (%d, %d)\n", windowID, pos.x, pos.y);
			SDL_SetWindowPosition(cur_w->sdl_window, pos.x, pos.y);
			list = list->next;
		}
	}
}

static void	testOnPtrEnter(void *main, void *el_v)
{
	main = NULL;
	t_ui_el *el = (t_ui_el *)el_v;
	if (el->current_texture != (size_t)ft_strhash("onActive"))
		ui_el_set_current_texture_by_id(el, "onFocus");
}

static void	testOnPtrExit(void *main, void *el_v)
{
	main = NULL;
	t_ui_el *el = (t_ui_el *)el_v;
	if (el->current_texture != (size_t)ft_strhash("onActive"))
		ui_el_set_current_texture_by_id(el, "default");
}

static void	testOnPtrLBD(void *main, void *el_v)
{
	t_list	*layer_elems;
	t_guimp	*g;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	t_ui_el *el = (t_ui_el *)el_v;
	layer_elems = el->parent->children;
	if (el->current_texture != (size_t)ft_strhash("onActive"))
	{
		while (layer_elems)
		{
			if (((t_ui_el *)layer_elems->content)->current_texture == (size_t)ft_strhash("onActive"))
				ui_el_set_current_texture_by_id(((t_ui_el *)layer_elems->content), "default");
			layer_elems = layer_elems->next;
		}
		ui_el_set_current_texture_by_id(el, "onActive");
		g->layers.current_layer = (t_ui_el *)(el->children->content);
	}
}

static void	test_add_layer(void *ui_main, void *el_v)
{
	t_ui_main	*m;
	t_ui_el		*el;
	t_ui_el		*layer_menu;
	t_ui_el		*tmp_el;
	t_guimp		*g;

	el = (t_ui_el *)el_v;
	m = (t_ui_main *)ui_main;
	g = (t_guimp *)m->data;
	layer_menu = ui_win_find_el_by_id(g->main_win, GM_LAYER_ID_MENU);
	if (!(tmp_el = ui_el_init()))
	{
		printf("layer malloc error in scrollable menu in layer_win\n");
		return ;
	}
	ui_el_setup_default(tmp_el);
	ui_el_setup_default_scroll_menu_elem(tmp_el);
	ui_el_add_child(layer_menu, tmp_el);
	tmp_el->id = gm_generate_surf_id(ID_GENERATOR_ADD);
	ui_el_set_pos(tmp_el, 0,
		(t_fvec2){0.1,
			((t_ui_el *)layer_menu->children->content)->relative_rect.y + 0.3 * (float)gm_generator_get_surf_count()});
	ui_el_set_size(tmp_el, 0, (t_fvec2){0.8, 0.25});
	tmp_el->sdl_renderer = g->main_win->sdl_renderer;
	ui_el_add_texture_from_main_by_id(g->ui_main, tmp_el, "layer_place", "default");
	ui_el_add_texture_from_main_by_id(g->ui_main, tmp_el, "layer_onPtr", "onFocus");
	ui_el_add_texture_from_main_by_id(g->ui_main, tmp_el, "layer_active", "onActive");
	ui_event_add_listener(tmp_el->events->onPointerLeftButtonPressed, testOnPtrLBD);
	ui_event_add_listener(tmp_el->events->onPointerEnter, testOnPtrEnter);
	ui_event_add_listener(tmp_el->events->onPointerExit, testOnPtrExit);

	if (!(el = ui_el_init()))
	{
		printf("layer texture malloc error in scrollable menu in layer_win\n");
		return ;
	}
	ui_el_setup_default(el);
	ui_el_add_child(tmp_el, el);
	ui_el_set_pos(el, 0, (t_fvec2){0.1, 0.1});
	ui_el_set_size(el, 0, (t_fvec2){0.8, 0.8});
	el->id = tmp_el->id * 1000;
	el->params |= EL_IGNOR_RAYCAST | EL_IS_DEPENDENT;
	el->sdl_renderer = g->main_win->sdl_renderer;
	ui_el_add_empty_texture(el, GM_IMAGE_SIZE_X, GM_IMAGE_SIZE_Y, "default");

	t_list	*tmp;
	tmp = ft_lstnew(NULL, 0);
	tmp->content = el->sdl_textures->content;
	tmp->content_size = tmp_el->id;
	ft_lstadd_back(&(g->layers.layers), tmp);
}

static void	test_del_layer(void *main, void *el_v)
{
	t_guimp	*g;
	t_ui_el	*el;
	t_ui_el	*next_active;
	t_list	*tmp;
	t_list	*prev;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	el = g->layers.current_layer->parent;
	(void)el_v;
	if (gm_generator_get_surf_count() == 0 || el->id == GM_LAYER_ID_DEF_LAYER)
		return ;
	if (!(next_active = ui_win_find_el_by_id(g->main_win, el->id + 1)))
		next_active = ui_win_find_el_by_id(g->main_win, el->id - 1);
	ui_el_set_current_texture_by_id(next_active, "onActive");
	g->layers.current_layer = (t_ui_el *)(next_active->children->content);
	tmp = el->parent->children;
	prev = tmp;
	while (tmp)
	{
		next_active = (t_ui_el *)(tmp->content);
		if (next_active->id == el->id)
			prev->next = tmp->next;
		if (next_active->id > el->id)
		{
			next_active->id--;
			ui_el_change_pos(next_active, 0, 0, (t_fvec2){0, -(next_active->relative_rect.h + 0.05)});
		}
		prev = tmp;
		tmp = tmp->next;
	}

	tmp = g->layers.layers;
	prev = tmp;
	while (tmp)
	{
		if ((Uint32)(tmp->content_size) == el->id)
			prev->next = tmp->next;
		if ((Uint32)(tmp->content_size) > el->id)
			tmp->content_size--;
		prev = tmp;
		tmp = tmp->next;
	}

	//del el
	//del texture
	gm_generate_surf_id(ID_GENERATOR_DEL);
}

static void	prepare_tmp_layer(t_guimp *g)
{
	//printf("from prepare_tmp_layer in>>>>>>>>> %d\n", g->draw_tool.state);
	SDL_SetRenderTarget(g->main_win->sdl_renderer, g->layers.tmp_texture);
	SDL_SetRenderDrawColor(g->main_win->sdl_renderer, 0, 0, 0, 0);
	SDL_RenderClear(g->main_win->sdl_renderer);
	SDL_SetRenderDrawColor(g->main_win->sdl_renderer, g->draw_tool.r, g->draw_tool.g, g->draw_tool.b, 255);
	if (g->draw_tool.state == GM_TOOL_STATE_DRAW)
	{
		SDL_RenderDrawLine(g->main_win->sdl_renderer, g->draw_tool.cur_point.x, g->draw_tool.cur_point.y,
			g->draw_tool.prew_point.x, g->draw_tool.prew_point.y);
	}
	if (g->draw_tool.state == GM_TOOL_STATE_END)
	{
		SDL_SetRenderTarget(g->main_win->sdl_renderer, (t_texture *)(g->layers.current_layer->sdl_textures->content));
		SDL_RenderDrawLine(g->main_win->sdl_renderer, g->draw_tool.cur_point.x, g->draw_tool.cur_point.y,
			g->draw_tool.prew_point.x, g->draw_tool.prew_point.y);
		g->draw_tool.state = GM_TOOL_STATE_NONE;
	}
	SDL_SetRenderTarget(g->main_win->sdl_renderer, NULL);
	//printf("from prepare_tmp_layer out>>>>>>>>> %d\n", g->draw_tool.state);
//	printf("cur x: %d, cur y: %d\n", g->draw_tool.cur_point.x, g->draw_tool.cur_point.y);
//	printf("pre x: %d, pre y: %d\n", g->draw_tool.prew_point.x, g->draw_tool.prew_point.y);
}

static void	draw_canvas_renderer(void *el_v, void *main)
{
	t_guimp	*g;
	t_ui_el	*el;
	t_list	*layer;
	int		tmp_flag;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	el = (t_ui_el *)el_v;
	layer = g->layers.layers;
	tmp_flag = 1;
	prepare_tmp_layer(g);
	while (layer)
	{
		SDL_RenderCopy(el->sdl_renderer, (t_texture *)(layer->content), &g->zoom_rect, &el->rect);
		if (tmp_flag && layer->content_size == g->layers.current_layer->parent->id)
		{
			tmp_flag = 0;
			SDL_RenderCopy(el->sdl_renderer, g->layers.tmp_texture, &g->zoom_rect, &el->rect);
		}
		layer = layer->next;
	}
}

static void	start_draw_with_selected_tool(void *main, void *el_v)
{
	t_guimp	*g;
	t_ui_el	*el;
	int		x;
	int		y;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	el = (t_ui_el *)el_v;
	x = ((float)el->ptr_rel_pos.x / (float)el->rect.w) * g->zoom_rect.w + g->zoom_rect.x;
	y = ((float)el->ptr_rel_pos.y / (float)el->rect.h) * g->zoom_rect.h + g->zoom_rect.y;
	if (g->draw_tool.tool != GM_TOOL_LINE || (g->draw_tool.state == GM_TOOL_STATE_NONE && g->draw_tool.tool == GM_TOOL_LINE))
		g->draw_tool.prew_point = (t_vec2){x, y};
	if (g->draw_tool.tool == GM_TOOL_ZOOM && g->draw_tool.zoom < GM_ZOOM_MAX_SIZE)
	{
		g->draw_tool.zoom++;
		g->zoom_rect.w = GM_IMAGE_SIZE_X / g->draw_tool.zoom;
		g->zoom_rect.h = GM_IMAGE_SIZE_Y / g->draw_tool.zoom;
		x = x - g->zoom_rect.w / 2;
		y = y - g->zoom_rect.h / 2;
		x = (x + g->zoom_rect.w > GM_IMAGE_SIZE_X) ? GM_IMAGE_SIZE_X - g->zoom_rect.w : x;
		y = (y + g->zoom_rect.h > GM_IMAGE_SIZE_Y) ? GM_IMAGE_SIZE_Y - g->zoom_rect.h : y;
		g->zoom_rect.x = x < 0 ? 0 : x;
		g->zoom_rect.y = y < 0 ? 0 : y;
	}
	if (g->draw_tool.tool == GM_TOOL_LINE)
	{
		if (g->draw_tool.state == GM_TOOL_STATE_DRAW)
			g->draw_tool.state = GM_TOOL_STATE_END;
		else if (g->draw_tool.state == GM_TOOL_STATE_NONE)
			g->draw_tool.state = GM_TOOL_STATE_START;
	}
	if (g->draw_tool.tool == GM_TOOL_PIPETTE)
	{
		int color = ui_get_pixel_color_from_texture(el->sdl_renderer, (t_texture *)(g->layers.layers->content), (t_vec2){x, y});
		g->draw_tool.r = (color & 0xFF0000) >> 16;
		g->draw_tool.g = (color & 0x00FF00) >> 8;
		g->draw_tool.b = color & 0x0000FF;
	}
}

static void	scan_tool_position(void *main, void *el_v)
{
	t_guimp	*g;
	t_ui_el	*el;
	int		x;
	int		y;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	el = (t_ui_el *)el_v;
	x = ((float)el->ptr_rel_pos.x / (float)el->rect.w) * g->zoom_rect.w + g->zoom_rect.x;
	y = ((float)el->ptr_rel_pos.y / (float)el->rect.h) * g->zoom_rect.h + g->zoom_rect.y;
	g->draw_tool.cur_point = (t_vec2){x, y};
}

static void	start_draw_with_selected_tool_pointer_up(void *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	(void)el_v;
	if (g->draw_tool.tool == GM_TOOL_LINE)
		if (g->draw_tool.state == GM_TOOL_STATE_START)
			g->draw_tool.state = GM_TOOL_STATE_DRAW;
}

static void	start_alt_with_selected_tool(void *main, void *el_v)
{
	t_guimp	*g;
	t_ui_el	*el;
	int		x;
	int		y;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	el = (t_ui_el *)el_v;
	x = ((float)el->ptr_rel_pos.x / (float)el->rect.w) * g->zoom_rect.w + g->zoom_rect.x;
	y = ((float)el->ptr_rel_pos.y / (float)el->rect.h) * g->zoom_rect.h + g->zoom_rect.y;
	g->draw_tool.prew_point = (t_vec2){x, y};
	if (g->draw_tool.tool == GM_TOOL_ZOOM && g->draw_tool.zoom > 1)
	{
		g->draw_tool.zoom--;
		g->zoom_rect.w = GM_IMAGE_SIZE_X / g->draw_tool.zoom;
		g->zoom_rect.h = GM_IMAGE_SIZE_Y / g->draw_tool.zoom;
		x = x - g->zoom_rect.w / 2;
		y = y - g->zoom_rect.h / 2;
		x = (x + g->zoom_rect.w > GM_IMAGE_SIZE_X) ? GM_IMAGE_SIZE_X - g->zoom_rect.w : x;
		y = (y + g->zoom_rect.h > GM_IMAGE_SIZE_Y) ? GM_IMAGE_SIZE_Y - g->zoom_rect.h : y;
		g->zoom_rect.x = x < 0 || g->draw_tool.zoom == 1 ? 0 : x;
		g->zoom_rect.y = y < 0 || g->draw_tool.zoom == 1 ? 0 : y;
	}
}

void	start_zoom_in(void *m, void *win)
{
	int			pt;
	t_guimp		*g;
	t_ui_win	*w;

	g = (t_guimp *)(((t_ui_main *)m)->data);
	w = (t_ui_win *)win;
	pt = g->draw_tool.tool;
	g->draw_tool.tool = GM_TOOL_ZOOM;
	start_draw_with_selected_tool(m, ui_win_find_el_by_id(w, GM_MAIN_ID_DRAW));
	g->draw_tool.tool = pt;
}

void	start_zoom_out(void *m, void *win)
{
	int			pt;
	t_guimp		*g;
	t_ui_win	*w;

	g = (t_guimp *)(((t_ui_main *)m)->data);
	w = (t_ui_win *)win;
	pt = g->draw_tool.tool;
	g->draw_tool.tool = GM_TOOL_ZOOM;
	start_alt_with_selected_tool(m, ui_win_find_el_by_id(w, GM_MAIN_ID_DRAW));
	g->draw_tool.tool = pt;
}

static void	draw_with_selected_tool(void *main, void *el_v)
{
	t_guimp	*g;
	t_ui_el	*el;
	int		x;
	int		y;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	el = (t_ui_el *)el_v;
	x = ((float)el->ptr_rel_pos.x / (float)el->rect.w) * g->zoom_rect.w + g->zoom_rect.x;
	y = ((float)el->ptr_rel_pos.y / (float)el->rect.h) * g->zoom_rect.h + g->zoom_rect.y;
	g->draw_tool.cur_point = (t_vec2){x, y};
	if (g->draw_tool.tool == GM_TOOL_BRUSH)
	{
		SDL_SetRenderTarget(el->sdl_renderer, (SDL_Texture *)(g->layers.current_layer->sdl_textures->content));
		SDL_SetTextureColorMod(ui_el_get_texture_by_id(el, "brush"), g->draw_tool.r, g->draw_tool.g, g->draw_tool.b); //вместо ui_el_get_texture_by_id(el, "brush") нужно выбрать текстуру текущей кисти
		SDL_RenderCopy(el->sdl_renderer, ui_el_get_texture_by_id(el, "brush"), NULL, &((t_rect){ //вместо ui_el_get_texture_by_id(el, "brush") нужно выбрать текстуру текущей кисти
			x - g->draw_tool.brush_size / 2,
			y - g->draw_tool.brush_size / 2,
			g->draw_tool.brush_size,
			g->draw_tool.brush_size
		}));
		SDL_SetRenderTarget(el->sdl_renderer, NULL);
	}
	if (g->draw_tool.tool == GM_TOOL_HAND)
	{
		g->zoom_rect.x += (abs(g->draw_tool.prew_point.x - g->draw_tool.cur_point.x) >= GM_HAND_MIN_DIST ? g->draw_tool.prew_point.x - g->draw_tool.cur_point.x : 0) * GM_HAND_MOVE_SPEED;
		g->zoom_rect.y += (abs(g->draw_tool.prew_point.y - g->draw_tool.cur_point.y) >= GM_HAND_MIN_DIST ? g->draw_tool.prew_point.y - g->draw_tool.cur_point.y : 0) * GM_HAND_MOVE_SPEED;
		g->zoom_rect.x = g->zoom_rect.x < 0 ? 0 : g->zoom_rect.x;
		g->zoom_rect.x = g->zoom_rect.x + g->zoom_rect.w > GM_IMAGE_SIZE_X ? GM_IMAGE_SIZE_X - g->zoom_rect.w : g->zoom_rect.x;
		g->zoom_rect.y = g->zoom_rect.y < 0 ? 0 : g->zoom_rect.y;
		g->zoom_rect.y = g->zoom_rect.y + g->zoom_rect.h > GM_IMAGE_SIZE_Y ? GM_IMAGE_SIZE_Y - g->zoom_rect.h : g->zoom_rect.y;
	}
	if (g->draw_tool.tool == GM_TOOL_BRUSH)
		g->draw_tool.prew_point = (t_vec2){x, y};
}

static void choose_brush(void *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	(void)el_v;
	g->draw_tool.tool = GM_TOOL_BRUSH;
}

static void choose_zoom(void *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	(void)el_v;
	g->draw_tool.tool = GM_TOOL_ZOOM;
}

static void choose_hand(void *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	(void)el_v;
	g->draw_tool.tool = GM_TOOL_HAND;
}

static void choose_pipette(void *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	(void)el_v;
	g->draw_tool.tool = GM_TOOL_PIPETTE;
}

static void choose_line(void *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	(void)el_v;
	g->draw_tool.tool = GM_TOOL_LINE;
	g->draw_tool.state = GM_TOOL_STATE_NONE;
}

static void	choose_color(void *main, void *el_v)
{
	t_guimp	*g;
	t_ui_el	*el;
	t_ui_el	*chil;
	int		res;
	int		max;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	el = (t_ui_el *)el_v;
	chil = ((t_ui_el *)el->children->content);
	max = (el->id == GM_TOOL_ID_SL_HEAD_SZ) ? GM_BRUSH_MAX_SIZE : 255;
	res = el->ptr_rel_pos.x - chil->rect.w / 2;
	ui_el_set_new_pos(chil, 0, PIXEL, (t_fvec2){res, 0});
	res = ((float)(el->ptr_rel_pos.x) / (float)el->rect.w) * (float)max;
	if (chil->id == GM_TOOL_ID_SL_HEAD_RED)
		g->draw_tool.r = res;
	else if (chil->id == GM_TOOL_ID_SL_HEAD_GR)
		g->draw_tool.g = res;
	else if (chil->id == GM_TOOL_ID_SL_HEAD_BL)
		g->draw_tool.b = res;
	else if (chil->id == GM_TOOL_ID_SL_HEAD_SZ)
		g->draw_tool.brush_size = res;
}

static void	move_draw_canvas_with_zoom(void *main, void *el_v)
{
	t_guimp	*g;
	t_ui_el	*el;
	float	x;
	float	y;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	el = (t_ui_el *)el_v;
	x = 0;
	y = 0;
	if (g->draw_tool.tool == GM_TOOL_ZOOM)
	{
		if (el->ptr_rel_pos.x > el->rect.w * (1.0 - GM_ZOOM_MOVE_ZONE))
			x = ((float)el->ptr_rel_pos.x / (float)el->rect.w - (1.0 - GM_ZOOM_MOVE_ZONE)) / (GM_ZOOM_MOVE_ZONE);
		if (el->ptr_rel_pos.x < el->rect.w * GM_ZOOM_MOVE_ZONE)
			x = -(GM_ZOOM_MOVE_ZONE - (float)el->ptr_rel_pos.x / (float)el->rect.w) / GM_ZOOM_MOVE_ZONE;
		if (el->ptr_rel_pos.y > el->rect.h * (1.0 - GM_ZOOM_MOVE_ZONE))
			y = ((float)el->ptr_rel_pos.y / (float)el->rect.h - (1.0 - GM_ZOOM_MOVE_ZONE)) / (GM_ZOOM_MOVE_ZONE);
		if (el->ptr_rel_pos.y < el->rect.h * GM_ZOOM_MOVE_ZONE)
			y = -(GM_ZOOM_MOVE_ZONE - (float)el->ptr_rel_pos.y / (float)el->rect.h) / GM_ZOOM_MOVE_ZONE;
		g->zoom_rect.x += x * (GM_ZOOM_MOVE_SPEED / g->draw_tool.zoom);
		g->zoom_rect.y += y * (GM_ZOOM_MOVE_SPEED / g->draw_tool.zoom);
		g->zoom_rect.x = g->zoom_rect.x < 0 ? 0 : g->zoom_rect.x;
		g->zoom_rect.x = g->zoom_rect.x + g->zoom_rect.w > GM_IMAGE_SIZE_X ? GM_IMAGE_SIZE_X - g->zoom_rect.w : g->zoom_rect.x;
		g->zoom_rect.y = g->zoom_rect.y < 0 ? 0 : g->zoom_rect.y;
		g->zoom_rect.y = g->zoom_rect.y + g->zoom_rect.h > GM_IMAGE_SIZE_Y ? GM_IMAGE_SIZE_Y - g->zoom_rect.h : g->zoom_rect.y;
	}
}

static void	draw_color_rect(void *el_v, void *main)
{
	t_guimp	*g;
	t_ui_el	*el;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	el = (t_ui_el *)el_v;
	SDL_SetRenderTarget(el->sdl_renderer, ui_el_get_current_texture(el));
	SDL_SetRenderDrawColor(el->sdl_renderer, g->draw_tool.r, g->draw_tool.g, g->draw_tool.b, 255);
	SDL_RenderFillRect(el->sdl_renderer, NULL);
	SDL_SetRenderTarget(el->sdl_renderer, NULL);
	SDL_RenderCopy(el->sdl_renderer, ui_el_get_current_texture(el), NULL, &el->rect);
}

static void text_test(void *elv, void *arg)
{
	t_ui_el	*el;
	t_ui_el	*dr;

	el = (t_ui_el *)elv;
	dr = (t_ui_el *)el->data;
	(void)arg;
	if (dr->params & EL_IS_PTR_INSIDE)
	{
		char *res = ft_strjoin("(", ft_itoa(dr->ptr_rel_pos.x));
		res = ft_strjoin(res, ";");
		res = ft_strjoin(res, ft_itoa(dr->ptr_rel_pos.y));
		res = ft_strjoin(res, ")");
		ui_el_update_text(el, res);
	}
	else
		ui_el_update_text(el, " ");
}

int		main()
{
	t_guimp	g_main;

	ui_sdl_init();
	gm_init(&g_main);
	if (!(g_main.ui_main = ui_main_init()))
	{
		printf("ui_main malloc error in struct g_main\n");
		return (0);
	}
	ui_main_fill_default_surfaces(g_main.ui_main);
	ui_main_fill_default_functions(g_main.ui_main);
	ui_main_add_function_by_id(g_main.ui_main, ui_el_show_child, "ui_el_show_child");
	ui_main_add_function_by_id(g_main.ui_main, ui_el_draw_event, "ui_el_draw_event");
	ui_main_add_function_by_id(g_main.ui_main, draw_canvas_renderer, "draw_canvas_renderer");
	ui_main_add_function_by_id(g_main.ui_main, draw_with_selected_tool, "draw_with_selected_tool");
	ui_main_add_function_by_id(g_main.ui_main, start_draw_with_selected_tool, "start_draw_with_selected_tool");
	ui_main_add_function_by_id(g_main.ui_main, start_alt_with_selected_tool, "start_alt_with_selected_tool");
	ui_main_add_function_by_id(g_main.ui_main, move_draw_canvas_with_zoom, "move_draw_canvas_with_zoom");
	ui_main_add_function_by_id(g_main.ui_main, testOnPtrLBD, "testOnPtrLBD");
	ui_main_add_function_by_id(g_main.ui_main, testOnPtrEnter, "testOnPtrEnter");
	ui_main_add_function_by_id(g_main.ui_main, testOnPtrExit, "testOnPtrExit");
	ui_main_add_function_by_id(g_main.ui_main, ui_el_set_default_texture, "ui_el_set_default_texture");
	ui_main_add_function_by_id(g_main.ui_main, ui_el_set_focused_texture, "ui_el_set_focused_texture");
	ui_main_add_function_by_id(g_main.ui_main, ui_el_set_active_texture, "ui_el_set_active_texture");
	ui_main_add_function_by_id(g_main.ui_main, ui_el_children_set_default, "ui_el_children_set_default");
	ui_main_add_function_by_id(g_main.ui_main, test_add_layer, "test_add_layer");
	ui_main_add_function_by_id(g_main.ui_main, test_del_layer, "test_del_layer");
	ui_main_add_function_by_id(g_main.ui_main, choose_brush, "choose_brush");
	ui_main_add_function_by_id(g_main.ui_main, choose_zoom, "choose_zoom");
	ui_main_add_function_by_id(g_main.ui_main, choose_hand, "choose_hand");
	ui_main_add_function_by_id(g_main.ui_main, choose_line, "choose_line");
	ui_main_add_function_by_id(g_main.ui_main, choose_pipette, "choose_pipette");
	ui_main_add_function_by_id(g_main.ui_main, choose_color, "choose_color");
	ui_main_add_function_by_id(g_main.ui_main, draw_color_rect, "draw_color_rect");
	ui_main_add_function_by_id(g_main.ui_main, scan_tool_position, "scan_tool_position");
	ui_main_add_function_by_id(g_main.ui_main, start_draw_with_selected_tool_pointer_up, "start_draw_with_selected_tool_pointer_up");
	ui_main_fill_default_fonts(g_main.ui_main);
	ui_main_set_font_params(g_main.ui_main, "neco", (t_font_params){0, 0, 1, 0});
	g_main.ui_main->data = (void *)(&g_main);
	g_main.draw_tool.brush_size = GM_BRUSH_DEF_SIZE;
	g_main.draw_tool.zoom = 1;
	g_main.draw_tool.state = GM_TOOL_STATE_NONE;
	g_main.draw_tool.tool = GM_TOOL_BRUSH;
	g_main.zoom_rect.x = 0;
	g_main.zoom_rect.y = 0;
	g_main.zoom_rect.w = GM_IMAGE_SIZE_X;
	g_main.zoom_rect.h = GM_IMAGE_SIZE_Y;


	if (ui_main_from_json(g_main.ui_main, "./json/main.json"))
		return (0);

	 g_main.main_win = ui_main_find_window_by_id(g_main.ui_main, 0);
	 g_main.tool_win = ui_main_find_window_by_id(g_main.ui_main, 1);


	t_ui_el	*cur_el;
//	cur_el = ui_win_find_el_by_id((t_ui_win *)g_main.ui_main->windows->content, 30);


	cur_el = ui_win_find_el_by_id(g_main.main_win, 1);
	g_main.layers.tmp_texture = ui_el_get_texture_by_id(cur_el, "tmp_layer");

	cur_el = ui_win_find_el_by_id(g_main.main_win, 63000);
	g_main.layers.current_layer = cur_el;
	t_list	*tmp;
	tmp = ft_lstnew(NULL, 0);
	tmp->content = cur_el->sdl_textures->content;
	tmp->content_size = 63;
	ft_lstadd(&(g_main.layers.layers), tmp);

	// cur_el = ui_win_find_el_by_id(g_main.tool_win, 31);
	// cur_el->params |= EL_IS_TEXT;
	// ui_el_set_text(g_main.ui_main, cur_el, "Diablo",
	// 	(t_text_params){(SDL_Color){255, 0, 0, 0}, (SDL_Color){0, 0, 0, 0}, 0, 0, 0});
	// cur_el->data = ui_win_find_el_by_id(g_main.main_win, 1);
	// ui_event_add_listener(cur_el->events->onRender, text_test);

	 cur_el = ui_win_find_el_by_id(g_main.tool_win, 12);
	 cur_el->sdl_renderer = g_main.tool_win->sdl_renderer;
	 cur_el->data = (void *)(&(t_cursor){ui_main_get_surface_by_id(g_main.ui_main, "brush"), 100, 100});
	 ui_event_add_listener(cur_el->events->onPointerLeftButtonPressed, ui_cursor_from_el_data);

	 cur_el = ui_win_find_el_by_id(g_main.tool_win, 14);
	 ui_event_add_listener(cur_el->events->onPointerLeftButtonPressed, ui_cursor_to_default);
//
//	 ui_el_add_texture_from_file(cur_el, "/home_sbednar/21school/guimp_json/images/bl.png", "default");
//	 ui_el_add_texture_from_file_dialog(cur_el);

	ui_main_loop(g_main.ui_main);
	return (0);
}
