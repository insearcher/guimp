/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:09:10 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/10 03:23:12 by sbecker          ###   ########.fr       */
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
			if (cur_w->id >= 2 || cur_w->id == w->id)
			{
				list = list->next;
				continue;
			}
			SDL_GetWindowPosition(w->sdl_window, &pos.x, &pos.y);
			if (cur_w->id == 0)
				pos.x = pos.x + GM_TOOL_WIN_W + 5;
			else if (cur_w->id == 1)
				pos.x = pos.x - GM_TOOL_WIN_W - 5;
			// printf("id: %d, (%d, %d)\n", windowID, pos.x, pos.y);
			SDL_SetWindowPosition(cur_w->sdl_window, pos.x, pos.y);
			cur_w->pos.x = pos.x;
			cur_w->pos.y = pos.y;
			list = list->next;
		}
	}
}

static int	get_value_from_slider(t_ui_el *s, t_ui_el *c)
{
	int	res;
	int	max;

	max = (c->id == GM_TOOL_ID_SL_HEAD_SZ) ? GM_BRUSH_MAX_SIZE : 255;
	res = s->ptr_rel_pos.x - c->rect.w / 2;
	ui_el_set_new_pos(c, 0, PIXEL, (t_fvec2){res, 0});
	res = ((float)(s->ptr_rel_pos.x) / (float)s->rect.w) * (float)max;
	return (res);
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

static void	PressedLBD(void *main, void *el_v)
{
	main = NULL;
	t_ui_el *el = (t_ui_el *)el_v;
	if (el->current_texture != (size_t)ft_strhash("onActive"))
		ui_el_set_current_texture_by_id(el, "onPressedLBM");
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

/* static void	open_image(void *main, void *el_v)
{

}*/

static void	clear_layer(void *ui_main, void *el_v)
{
	SDL_Texture	*t;
	t_guimp		*g;

	g = (t_guimp *)(((t_ui_main *)ui_main)->data);
	t = (t_texture *)((t_ui_el *)el_v)->data;
	SDL_SetRenderTarget(g->main_win->sdl_renderer, t);
	SDL_SetRenderDrawBlendMode(g->main_win->sdl_renderer, SDL_BLENDMODE_NONE);
	SDL_SetRenderDrawColor(g->main_win->sdl_renderer, 255, 255, 255, 0);
	SDL_RenderFillRect(g->main_win->sdl_renderer, NULL);
	SDL_SetRenderTarget(g->main_win->sdl_renderer, NULL);
}

static void	clear_all_layers(void *ui_main, void *el_v)
{
	SDL_Texture	*t;
	t_list		*l;
	t_guimp		*g;

	g = (t_guimp *)(((t_ui_main *)ui_main)->data);
	(void)el_v;
	l = g->layers.layers;
	while (l)
	{
		t = (t_texture *)l->content;
		SDL_SetRenderTarget(g->main_win->sdl_renderer, t);
		SDL_SetRenderDrawBlendMode(g->main_win->sdl_renderer, SDL_BLENDMODE_NONE);
		SDL_SetRenderDrawColor(g->main_win->sdl_renderer, 255, 255, 255, 0);
		SDL_RenderFillRect(g->main_win->sdl_renderer, NULL);
		l = l->next;
	}
	SDL_SetRenderTarget(g->main_win->sdl_renderer, NULL);
}

static void	test_add_layer(void *ui_main, void *el_v)
{
	t_ui_main	*m;
	t_ui_el		*el;
	t_ui_el		*tmp2;
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
		(t_fvec2){0.05,
			((t_ui_el *)layer_menu->children->content)->relative_rect.y + 0.27 * (float)gm_generator_get_surf_count()});
	ui_el_set_size(tmp_el, 0, (t_fvec2){0.9, 0.25});
	tmp_el->sdl_renderer = g->main_win->sdl_renderer;
	ui_el_add_color_texture(tmp_el, (t_vec2){1704, 800}, 0x888888, "default");
	ui_el_add_color_texture(tmp_el, (t_vec2){1704, 800}, 0xFF5050, "onActive");
	ui_el_add_color_texture(tmp_el, (t_vec2){1704, 800}, 0x5050FF, "onFocus");
//	ui_el_add_texture_from_main_by_id(g->ui_main, tmp_el, "layer_place", "default");
//	ui_el_add_texture_from_main_by_id(g->ui_main, tmp_el, "layer_onPtr", "onFocus");
//	ui_el_add_texture_from_main_by_id(g->ui_main, tmp_el, "layer_active", "onActive");
	ui_event_add_listener(tmp_el->events->onPointerLeftButtonPressed, testOnPtrLBD);
	ui_event_add_listener(tmp_el->events->onPointerEnter, testOnPtrEnter);
	ui_event_add_listener(tmp_el->events->onPointerLeftButtonPressed, PressedLBD);
	ui_event_add_listener(tmp_el->events->onPointerExit, testOnPtrExit);

	if (!(el = ui_el_init()))
	{
		printf("layer texture malloc error in scrollable menu in layer_win\n");
		return ;
	}
	ui_el_setup_default(el);
	ui_el_add_child(tmp_el, el);
	ui_el_set_pos(el, 0, (t_fvec2){0.04, 0.05});
	ui_el_set_size(el, 0, (t_fvec2){0.92, 0.782});
	el->id = tmp_el->id * 1000;
	el->params |= EL_IGNOR_RAYCAST | EL_IS_DEPENDENT;
	el->sdl_renderer = g->main_win->sdl_renderer;
	ui_el_add_empty_texture(el, GM_IMAGE_SIZE_X, GM_IMAGE_SIZE_Y, "default");

	t_list	*tmp;
	tmp = ft_lstnew(NULL, 0);
	tmp->content = el->sdl_textures->content;
	tmp->content_size = tmp_el->id;
	ft_lstadd_back(&(g->layers.layers), tmp);

	tmp2 = el;

	if (!(el = ui_el_init()))
	{
		printf("layer texture malloc error in scrollable menu in layer_win\n");
		return ;
	}

	ui_el_setup_default(el);
	el->params |= EL_IS_DEPENDENT;
	ui_el_add_child(tmp_el, el);
	ui_el_set_pos(el, 0, (t_fvec2){0.04, 0.85});
	ui_el_set_size(el, 0, (t_fvec2){0.45, 0.1});
	el->id = tmp_el->id * 1000 + 1;
	ui_el_add_color_texture(el, (t_vec2){GM_IMAGE_SIZE_X, GM_IMAGE_SIZE_Y}, 0x00FF00, "default");
	ui_event_add_listener(el->events->onPointerLeftButtonPressed, clear_layer);
	el->data = ui_el_get_texture_by_id(tmp2, "default");

	if (!(el = ui_el_init()))
	{
		printf("layer texture malloc error in scrollable menu in layer_win\n");
		return ;
	}

	ui_el_setup_default(el);
	el->params |= EL_IS_DEPENDENT;
	ui_el_add_child(tmp_el, el);
	ui_el_set_pos(el, 0, (t_fvec2){0.51, 0.85});
	ui_el_set_size(el, 0, (t_fvec2){0.45, 0.1});
	el->id = tmp_el->id * 1000 + 2;
	ui_el_add_white_texture(el, GM_IMAGE_SIZE_X, GM_IMAGE_SIZE_Y, "default");
	el->data = ui_el_get_texture_by_id(tmp2, "default");
	ui_event_add_listener(el->events->onPointerLeftButtonPressed, clear_layer);
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

static void	ui_save_test(void *main, void *el_v)
{
	t_guimp		*g;
	t_texture	*t;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	(void)el_v;
	t = ui_main_merge_layers(g->main_win->sdl_renderer, g->layers.layers);
	ui_main_save_texture(g->main_win->sdl_renderer, t, "/Users/sbednar/Desktop/test.jpg", IMG_TYPE_JPG);
}

static void	ui_open_test(void *main, void *el_v)
{
	t_guimp		*g;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	(void)el_v;
	ui_main_open_texture(g->main_win->sdl_renderer, g->layers.current_layer, "/Users/sbednar/Desktop/test.png");
}

static void	prepare_tmp_layer(t_guimp *g)
{
	//printf("from prepare_tmp_layer in>>>>>>>>> %d\n", g->draw_tool.state);
	SDL_SetRenderTarget(g->main_win->sdl_renderer, g->layers.tmp_texture);
	SDL_SetRenderDrawColor(g->main_win->sdl_renderer, 0, 0, 0, 0);
	SDL_RenderClear(g->main_win->sdl_renderer);
	SDL_SetRenderDrawColor(g->main_win->sdl_renderer, g->draw_tool.r, g->draw_tool.g, g->draw_tool.b, 255);
	int px = g->draw_tool.prew_point.x > g->draw_tool.cur_point.x ? g->draw_tool.cur_point.x : g->draw_tool.prew_point.x;
	int py = g->draw_tool.prew_point.y > g->draw_tool.cur_point.y ? g->draw_tool.cur_point.y : g->draw_tool.prew_point.y;
	int cx = g->draw_tool.prew_point.x + g->draw_tool.cur_point.x - px;
	int cy = g->draw_tool.prew_point.y + g->draw_tool.cur_point.y - py;
	if (g->draw_tool.state == GM_TOOL_STATE_DRAW)
	{
		// draw_fat_line(g, (t_vec2){g->draw_tool.cur_point.x, g->draw_tool.cur_point.y},
		// 	(t_vec2){g->draw_tool.prew_point.x, g->draw_tool.prew_point.y});
		// draw_elipse(g, (t_vec2){g->draw_tool.prew_point.x, g->draw_tool.prew_point.y},
		// 	(t_vec2){g->draw_tool.cur_point.x, g->draw_tool.cur_point.y});
		draw_empty_elipse(g, (t_vec2){g->draw_tool.prew_point.x, g->draw_tool.prew_point.y},
			(t_vec2){g->draw_tool.cur_point.x, g->draw_tool.cur_point.y});
		// SDL_RenderDrawLine(g->main_win->sdl_renderer, g->draw_tool.cur_point.x, g->draw_tool.cur_point.y,
		// 	g->draw_tool.prew_point.x, g->draw_tool.prew_point.y);
		if (g->draw_tool.tool == GM_TOOL_RECT)
		{
			if (g->draw_tool.tool_mode & GM_TOOL_MODE_EMPTY)
			{
				SDL_RenderFillRect(g->main_win->sdl_renderer, &(t_rect){
						px,
						py,
						g->draw_tool.brush_size,
						cy - py});
				SDL_RenderFillRect(g->main_win->sdl_renderer, &(t_rect){
						px,
						py,
						cx - px,
						g->draw_tool.brush_size});
				SDL_RenderFillRect(g->main_win->sdl_renderer, &(t_rect){
						px,
						cy - g->draw_tool.brush_size,
						cx - px,
						g->draw_tool.brush_size});
				SDL_RenderFillRect(g->main_win->sdl_renderer, &(t_rect){
						cx - g->draw_tool.brush_size,
						py,
						g->draw_tool.brush_size,
						cy - py});
			}
			else if (g->draw_tool.tool_mode & GM_TOOL_MODE_FILL)
			{
				SDL_RenderFillRect(g->main_win->sdl_renderer, &(t_rect){
						g->draw_tool.prew_point.x,
						g->draw_tool.prew_point.y,
						g->draw_tool.cur_point.x - g->draw_tool.prew_point.x,
						g->draw_tool.cur_point.y - g->draw_tool.prew_point.y});
			}
		}
		else if (g->draw_tool.tool == GM_TOOL_LINE)
			draw_fat_line(g, (t_vec2){g->draw_tool.cur_point.x, g->draw_tool.cur_point.y},
			(t_vec2){g->draw_tool.prew_point.x, g->draw_tool.prew_point.y});
	}
	if (g->draw_tool.state == GM_TOOL_STATE_END)
	{
		SDL_SetRenderTarget(g->main_win->sdl_renderer, (t_texture *)(g->layers.current_layer->sdl_textures->content));
		// SDL_RenderDrawLine(g->main_win->sdl_renderer, g->draw_tool.cur_point.x, g->draw_tool.cur_point.y,
		// 	g->draw_tool.prew_point.x, g->draw_tool.prew_point.y);
		if (g->draw_tool.tool == GM_TOOL_RECT)
		{
			if (g->draw_tool.tool_mode & GM_TOOL_MODE_EMPTY)
			{
				SDL_RenderFillRect(g->main_win->sdl_renderer, &(t_rect){
						px,
						py,
						g->draw_tool.brush_size,
						cy - py});
				SDL_RenderFillRect(g->main_win->sdl_renderer, &(t_rect){
						px,
						py,
						cx - px,
						g->draw_tool.brush_size});
				SDL_RenderFillRect(g->main_win->sdl_renderer, &(t_rect){
						px,
						cy - g->draw_tool.brush_size,
						cx - px,
						g->draw_tool.brush_size});
				SDL_RenderFillRect(g->main_win->sdl_renderer, &(t_rect){
						cx - g->draw_tool.brush_size,
						py,
						g->draw_tool.brush_size,
						cy - py});
			}
			else if (g->draw_tool.tool_mode & GM_TOOL_MODE_FILL)
			{
				SDL_RenderFillRect(g->main_win->sdl_renderer, &(t_rect){
						g->draw_tool.prew_point.x,
						g->draw_tool.prew_point.y,
						g->draw_tool.cur_point.x - g->draw_tool.prew_point.x,
						g->draw_tool.cur_point.y - g->draw_tool.prew_point.y});
			}
		}
		else if (g->draw_tool.tool == GM_TOOL_LINE)
			draw_fat_line(g, (t_vec2){g->draw_tool.cur_point.x, g->draw_tool.cur_point.y},
			(t_vec2){g->draw_tool.prew_point.x, g->draw_tool.prew_point.y});
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

Uint32	ui_get_pixel_color_from_texture_abs(SDL_Renderer *renderer,
										  SDL_Texture *texture, int x, int y)
{
	Uint32		res;
	SDL_Surface	*surf;
	Uint8		*p;

	surf = SDL_CreateRGBSurfaceWithFormat(0, 1, 1, 24, SDL_PIXELFORMAT_RGBA8888);
	res = 0;
	SDL_SetRenderTarget(renderer, texture);
	SDL_RenderReadPixels(renderer, &((t_rect){x, y, 1, 1}), 0, surf->pixels, surf->pitch);
	SDL_SetRenderTarget(renderer, NULL);
	p = (Uint8 *)surf->pixels;
	//printf("r: %d, g: %d, b: %d\n", p[2], p[1], p[0]);
	res = (p[2] << 16 & 0xFF0000) + (p[1] << 8 & 0x00FF00) + (p[0] & 0x0000FF);
	SDL_FreeSurface(surf);
	return (res);
}

static void	ui_set_pixel_color_to_texture_replace_abs(SDL_Renderer *renderer,
													 SDL_Texture *texture, int x, int y, SDL_Color color)
{
	SDL_BlendMode	pb;

	SDL_GetRenderDrawBlendMode(renderer, &pb);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
	SDL_SetRenderTarget(renderer, texture);
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawPoint(renderer, x, y);
	SDL_SetRenderTarget(renderer, NULL);
	SDL_SetRenderDrawBlendMode(renderer, pb);
}

Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
//	int bpp = surface->format->BytesPerPixel;
//	/* Here p is the address to the pixel we want to retrieve */
//	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
//
//	switch(bpp) {
//		case 1:
//			return *p;
//			break;
//
//		case 2:
//			return *(Uint16 *)p;
//			break;
//
//		case 3:
//			if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
//				return p[0] << 16 | p[1] << 8 | p[2];
//			else
//				return p[0] | p[1] << 8 | p[2] << 16;
//			break;
//
//		case 4:
//			return *(Uint32 *)p;
//			break;
//
//		default:
//			return 0;       /* shouldn't happen, but avoids warnings */
//	}
	int bpp;
	Uint8 *p;

	/*
	* Get destination format
	*/
	bpp = surface->format->BytesPerPixel;
	p = (Uint8 *) surface->pixels + y * surface->pitch + x * bpp;
	return
			*(Uint32 *) p;
}

void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
//	int bpp = surface->format->BytesPerPixel;
//	/* Here p is the address to the pixel we want to set */
//	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp * 8;
//
//	switch(bpp) {
//		case 1:
//			*p = pixel;
//			break;
//
//		case 2:
//			*(Uint16 *)p = pixel;
//			break;
//
//		case 3:
//			if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
//				p[0] = (pixel >> 16) & 0xff;
//				p[1] = (pixel >> 8) & 0xff;
//				p[2] = pixel & 0xff;
//			} else {
//				p[0] = pixel & 0xff;
//				p[1] = (pixel >> 8) & 0xff;
//				p[2] = (pixel >> 16) & 0xff;
//			}
//			break;
//
//		case 4:
//			*(Uint32 *)p = pixel;
//			break;
//	}
	int bpp;
	Uint8 *p;

	/*
	* Get destination format
	*/
	bpp = surface->format->BytesPerPixel;
	p = (Uint8 *) surface->pixels + y * surface->pitch + x * bpp;
	switch (bpp) {
		case 1:
			*p = pixel;
			break;
		case 2:
			*(Uint16 *) p = pixel;
			break;
		case 3:
			if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
				p[0] = (pixel >> 16) & 0xff;
				p[1] = (pixel >> 8) & 0xff;
				p[2] = pixel & 0xff;
			} else {
				p[0] = pixel & 0xff;
				p[1] = (pixel >> 8) & 0xff;
				p[2] = (pixel >> 16) & 0xff;
			}
			break;
		case 4:
			*(Uint32 *) p = pixel;
			break;
	}				/* switch */
}

static void	fill_tool(t_renderer *rend, t_texture *texture, t_cvec2 color, t_vec2 coord)
{
	char 	*field;
	int f = 0;
	int l = 0;
	int *queue;
	int x, y;

	field = (char *)malloc(1704 * 800);
	for (int i = 0; i < 1704 * 800; i++)
		field[i] = 0;
	queue = (int *)malloc(1704 * 800 * sizeof(int));
	SDL_Texture *t = SDL_CreateTexture(rend, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, 1704, 800);
	SDL_SetRenderTarget(rend, t);
	SDL_RenderCopy(rend, texture, NULL, NULL);
	SDL_Surface *s = SDL_CreateRGBSurface(0, 1704, 800, 32, 0, 0, 0, 0);
	SDL_RenderReadPixels(rend, NULL, s->format->format, s->pixels, s->pitch);
	for (int i = 0; i < 1704 * 800; i++)
		queue[i] = 0;
	queue[l++] = coord.x * 10000 + coord.y;
	while (f < l)
	{
//		SDL_Log("%d %d", color.color2, getpixel(s, x, y));
		x = queue[f] / 10000;
		y = queue[f++] % 10000;
		if (field[y * 1704 + x] <= '2' && getpixel(s, x, y) == color.color2)
		{
			putpixel(s, x, y, color.color1);
//			ui_set_pixel_color_to_texture_replace_abs(rend, texture, x, y, (t_color) {
//					(color.color1 & 0xFF0000) >> 16, (color.color1 & 0x00FF00) >> 8, color.color1 & 0x0000FF, 255
//			});
			field[y * 1704 + x] = '2';
		}
//		SDL_Log("%d %d %d %d %d", x + 1, GM_IMAGE_SIZE_X, field[y * 1704 + x + 1], ui_get_pixel_color_from_texture_abs(rend, texture, x, y), color.color2);
//		SDL_Delay(5000);
		if (x + 1 < 1704 && !field[y * 1704 + x + 1] && getpixel(s, x + 1, y) == color.color2)
		{
			queue[l++] = (x + 1) * 10000 + y;
			field[y * 1704 + x + 1] = '1';
		}
		if (x - 1 >= 0 && !field[y * 1704 + x - 1] && getpixel(s, x - 1, y) == color.color2)
		{
			queue[l++] = (x - 1) * 10000 + y;
			field[y * 1704 + x - 1] = '1';
		}
		if (y - 1 >= 0 && !field[(y - 1) * 1704 + x] && getpixel(s, x, y - 1) == color.color2)
		{
			queue[l++] = x * 10000 + y - 1;
			field[(y - 1) * 1704 + x] = '1';
		}
		if (y + 1 < 800 && !field[(y + 1) * 1704 + x] && getpixel(s, x, y + 1) == color.color2)
		{
			queue[l++] = x * 10000 + y + 1;
			field[(y + 1) * 1704 + x] = '1';
		}
	}
	SDL_Texture *tmp = SDL_CreateTextureFromSurface(rend, s);
	SDL_SetRenderTarget(rend, texture);
	SDL_RenderCopy(rend, tmp, NULL, NULL);
	SDL_SetRenderTarget(rend, NULL);
	free(field);
	free(queue);
//	ui_sdl_deinit(0);
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
	if (g->draw_tool.tool & (GM_TOOL_LINE | GM_TOOL_RECT) == 0 || (g->draw_tool.state == GM_TOOL_STATE_NONE && g->draw_tool.tool & (GM_TOOL_LINE | GM_TOOL_RECT)))
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
	if (g->draw_tool.tool & (GM_TOOL_LINE | GM_TOOL_RECT))
	{
		// printf("from start_draw_with_selected_tool in>>>>>>>>> %d\n", g->draw_tool.state);
		if (g->draw_tool.state == GM_TOOL_STATE_DRAW)
			g->draw_tool.state = GM_TOOL_STATE_END;
		else if (g->draw_tool.state == GM_TOOL_STATE_NONE)
			g->draw_tool.state = GM_TOOL_STATE_START;
	}
	if (g->draw_tool.tool == GM_TOOL_FILL)
	{
		Uint32 color1 = (g->draw_tool.r << 16) + (g->draw_tool.g << 8) + g->draw_tool.b;
		Uint32 color2 = ui_get_pixel_color_from_texture(el->sdl_renderer,
			(t_texture *)g->layers.current_layer->sdl_textures->content,
			(t_vec2){x, y});
		if (color1 != color2)
			fill_tool(el->sdl_renderer,
				(t_texture *)g->layers.current_layer->sdl_textures->content,
				(t_cvec2){color1, color2},
				(t_vec2){(int)(x / 1920.0f * 1704), (int)(y / 1080.0f * 800)});
	}
}

void	update_color_rect(t_guimp *gm, int r, int g, int b)
{
	t_ui_el	*el;

	el = ui_win_find_el_by_id(gm->tool_win, GM_TOOL_ID_COLOR_RECT);
	SDL_Texture *t = (SDL_Texture *)el->sdl_textures->content;
	SDL_DestroyTexture(t);
	free(el->sdl_textures);
	el->sdl_textures = NULL;
	ui_el_add_color_texture(el, (t_vec2){100, 20}, (r << 16) | (g << 8) | b, "default");
//	el = ui_win_find_el_by_id(gm->tool_win, GM_TOOL_ID_COLOR_TEXT);
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
	// printf(">>>>>>>>>>>>>>%d>>>>>>>>>>>>>>%d\n", g->draw_tool.cur_point.x, g->draw_tool.cur_point.y);
}

static void	start_draw_with_selected_tool_pointer_up(void *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	(void)el_v;
	// printf("from start_draw_with_selected_tool_pointer_up in>>>>>>>>> %d\n", g->draw_tool.state);
	if (g->draw_tool.tool & (GM_TOOL_LINE | GM_TOOL_RECT))
		if (g->draw_tool.state == GM_TOOL_STATE_START)
			g->draw_tool.state = GM_TOOL_STATE_DRAW;
	// printf("from start_draw_with_selected_tool_pointer_up out>>>>>>>>> %d\n", g->draw_tool.state);
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

static void choose_fill(void *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	(void)el_v;
	g->draw_tool.tool = GM_TOOL_FILL;
}

static void choose_eraser(void *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	(void)el_v;
	g->draw_tool.tool = GM_TOOL_ERASER;
}

static void choose_line(void *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	(void)el_v;
	g->draw_tool.tool = GM_TOOL_LINE;
	g->draw_tool.state = GM_TOOL_STATE_NONE;
}

static void choose_rect(void *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	(void)el_v;
	g->draw_tool.tool = GM_TOOL_RECT;
	g->draw_tool.tool_mode = GM_TOOL_MODE_EMPTY;
	g->draw_tool.state = GM_TOOL_STATE_NONE;
}

static void choose_fill_mode(void *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	(void)el_v;
	g->draw_tool.tool_mode = GM_TOOL_MODE_FILL;
}

static void choose_empty_mode(void *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	(void)el_v;
	g->draw_tool.tool_mode = GM_TOOL_MODE_EMPTY;
}

static void	choose_red_color(void *main, void *el_v)
{
	t_guimp	*g;
	t_ui_el	*el;
	t_ui_el	*chil;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	el = (t_ui_el *)el_v;
	chil = ((t_ui_el *)el->children->content);
	g->draw_tool.r = get_value_from_slider(el, chil);
	update_color_rect(g, g->draw_tool.r, g->draw_tool.g, g->draw_tool.b);
}

static void	choose_green_color(void *main, void *el_v)
{
	t_guimp	*g;
	t_ui_el	*el;
	t_ui_el	*chil;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	el = (t_ui_el *)el_v;
	chil = ((t_ui_el *)el->children->content);
	g->draw_tool.g = get_value_from_slider(el, chil);
	update_color_rect(g, g->draw_tool.r, g->draw_tool.g, g->draw_tool.b);
}

static void	choose_blue_color(void *main, void *el_v)
{
	t_guimp	*g;
	t_ui_el	*el;
	t_ui_el	*chil;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	el = (t_ui_el *)el_v;
	chil = ((t_ui_el *)el->children->content);
	g->draw_tool.b = get_value_from_slider(el, chil);
	update_color_rect(g, g->draw_tool.r, g->draw_tool.g, g->draw_tool.b);
}

static void	choose_size(void *main, void *el_v)
{
	t_guimp	*g;
	t_ui_el	*el;
	t_ui_el	*chil;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	el = (t_ui_el *)el_v;
	chil = ((t_ui_el *)el->children->content);
	g->draw_tool.brush_size = get_value_from_slider(el, chil);
}

static void	choose_alpha(void *main, void *el_v)
{
	t_guimp	*g;
	t_ui_el	*el;
	t_ui_el	*chil;
	int		res;
	int		max;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	el = (t_ui_el *)el_v;
	chil = ((t_ui_el *)el->children->content);
	g->draw_tool.a = get_value_from_slider(el, chil);
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
	ui_main_add_function_by_id(g_main.ui_main, PressedLBD, "PressedLBD");
	ui_main_add_function_by_id(g_main.ui_main, testOnPtrEnter, "testOnPtrEnter");
	ui_main_add_function_by_id(g_main.ui_main, testOnPtrExit, "testOnPtrExit");
	ui_main_add_function_by_id(g_main.ui_main, ui_el_set_default_texture, "ui_el_set_default_texture");
	ui_main_add_function_by_id(g_main.ui_main, ui_el_set_focused_texture, "ui_el_set_focused_texture");
	ui_main_add_function_by_id(g_main.ui_main, ui_el_set_active_texture, "ui_el_set_active_texture");
	ui_main_add_function_by_id(g_main.ui_main, ui_el_children_set_default, "ui_el_children_set_default");
	ui_main_add_function_by_id(g_main.ui_main, test_add_layer, "test_add_layer");
	ui_main_add_function_by_id(g_main.ui_main, test_del_layer, "test_del_layer");
	ui_main_add_function_by_id(g_main.ui_main, choose_brush, "choose_brush");
	ui_main_add_function_by_id(g_main.ui_main, choose_eraser, "choose_eraser");
	ui_main_add_function_by_id(g_main.ui_main, choose_zoom, "choose_zoom");
	ui_main_add_function_by_id(g_main.ui_main, choose_hand, "choose_hand");
	ui_main_add_function_by_id(g_main.ui_main, choose_line, "choose_line");
	ui_main_add_function_by_id(g_main.ui_main, choose_red_color, "choose_red_color");
	ui_main_add_function_by_id(g_main.ui_main, choose_green_color, "choose_green_color");
	ui_main_add_function_by_id(g_main.ui_main, choose_blue_color, "choose_blue_color");
	ui_main_add_function_by_id(g_main.ui_main, choose_size, "choose_size");
	ui_main_add_function_by_id(g_main.ui_main, choose_alpha, "choose_alpha");
	ui_main_add_function_by_id(g_main.ui_main, choose_pipette, "choose_pipette");
	ui_main_add_function_by_id(g_main.ui_main, choose_fill, "choose_fill");
	ui_main_add_function_by_id(g_main.ui_main, choose_color, "choose_color");
	ui_main_add_function_by_id(g_main.ui_main, choose_rect, "choose_rect");
	ui_main_add_function_by_id(g_main.ui_main, choose_fill_mode, "choose_fill_mode");
	ui_main_add_function_by_id(g_main.ui_main, choose_empty_mode, "choose_empty_mode");
	ui_main_add_function_by_id(g_main.ui_main, draw_color_rect, "draw_color_rect");
	ui_main_add_function_by_id(g_main.ui_main, scan_tool_position, "scan_tool_position");

	ui_main_add_function_by_id(g_main.ui_main, ui_save_test, "ui_save_test");
	ui_main_add_function_by_id(g_main.ui_main, ui_open_test, "ui_open_test");
	ui_main_add_function_by_id(g_main.ui_main, start_draw_with_selected_tool_pointer_up, "start_draw_with_selected_tool_pointer_up");
	ui_main_fill_default_fonts(g_main.ui_main);
	ui_main_set_font_params(g_main.ui_main, "neco", (t_font_params){0, 0, 1, 0});
	g_main.ui_main->data = (void *)(&g_main);
	g_main.draw_tool.brush_size = GM_BRUSH_DEF_SIZE;
	g_main.draw_tool.a = 255;
	g_main.draw_tool.zoom = 1;
	g_main.draw_tool.state = GM_TOOL_STATE_NONE;
	g_main.draw_tool.tool = GM_TOOL_BRUSH;
	g_main.zoom_rect.x = 0;
	g_main.zoom_rect.y = 0;
	g_main.zoom_rect.w = GM_IMAGE_SIZE_X;
	g_main.zoom_rect.h = GM_IMAGE_SIZE_Y;

	if (ui_main_from_json(g_main.ui_main, "./json/main_new.json"))
		return (0);

	 g_main.main_win = ui_main_find_window_by_id(g_main.ui_main, 0);
	 g_main.tool_win = ui_main_find_window_by_id(g_main.ui_main, 1);
	SDL_RaiseWindow(g_main.main_win->sdl_window);   //TODO SDL FUNCTIONS FORBIDDEN


	t_ui_el	*cur_el;
//	cur_el = ui_win_find_el_by_id((t_ui_win *)g_main.ui_main->windows->content, 30);


	cur_el = ui_win_find_el_by_id(g_main.main_win, 3);

	g_main.layers.tmp_texture = ui_el_get_texture_by_id(cur_el, "tmp_layer");

	cur_el = ui_win_find_el_by_id(g_main.main_win, 63000);
	g_main.layers.current_layer = cur_el;
	t_list	*tmp;
	tmp = ft_lstnew(NULL, 0);
	tmp->content = cur_el->sdl_textures->content;
	tmp->content_size = 63;
	ft_lstadd(&(g_main.layers.layers), tmp);

 	cur_el = ui_win_find_el_by_id(g_main.tool_win, 31);
	cur_el->data = ui_win_find_el_by_id(g_main.main_win, GM_MAIN_ID_DRAW);
	ui_event_add_listener(cur_el->events->onRender, text_test);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	cur_el = ui_win_find_el_by_id(g_main.tool_win, 10);
//	cur_el->data = (void *)(&(t_cursor){ui_main_get_surface_by_id(g_main.ui_main, "brush_icon"), 26, 39});
//	ui_event_add_listener(cur_el->events->onPointerLeftButtonPressed, ui_cursor_from_el_data);
//	ui_cursor_from_el_data(NULL, cur_el);

	cur_el->data = (void *)(&(t_cursor){ui_main_get_surface_by_id(g_main.ui_main, "brush_icon"), 26, 40});
	ui_event_add_listener(cur_el->events->onPointerLeftButtonPressed, ui_cursor_from_el_data);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cur_el = ui_win_find_el_by_id(g_main.tool_win, 12);
	cur_el->data = (void *)(&(t_cursor){ui_main_get_surface_by_id(g_main.ui_main, "text_icon"), 23, 27});
	ui_event_add_listener(cur_el->events->onPointerLeftButtonPressed, ui_cursor_from_el_data);

	cur_el = ui_win_find_el_by_id(g_main.tool_win, 13);
	cur_el->data = (void *)(&(t_cursor){ui_main_get_surface_by_id(g_main.ui_main, "eraser_icon"), 21, 36});
	ui_event_add_listener(cur_el->events->onPointerLeftButtonPressed, ui_cursor_from_el_data);

	cur_el = ui_win_find_el_by_id(g_main.tool_win, 14);
	cur_el->data = (void *)(&(t_cursor){ui_main_get_surface_by_id(g_main.ui_main, "zoom_icon"), 23, 23});
	ui_event_add_listener(cur_el->events->onPointerLeftButtonPressed, ui_cursor_from_el_data);

	cur_el = ui_win_find_el_by_id(g_main.tool_win, 16);
	cur_el->data = (void *)(&(t_cursor){ui_main_get_surface_by_id(g_main.ui_main, "fill_icon"), 14, 39});
	ui_event_add_listener(cur_el->events->onPointerLeftButtonPressed, ui_cursor_from_el_data);

	cur_el = ui_win_find_el_by_id(g_main.tool_win, 17);
	cur_el->data = (void *)(&(t_cursor){ui_main_get_surface_by_id(g_main.ui_main, "pipette_icon"), 13, 38});
	ui_event_add_listener(cur_el->events->onPointerLeftButtonPressed, ui_cursor_from_el_data);

	cur_el = ui_win_find_el_by_id(g_main.tool_win, 15);
	cur_el->data = (void *)(&(t_cursor){ui_main_get_surface_by_id(g_main.ui_main, "hand_icon"), 26, 27});
	ui_event_add_listener(cur_el->events->onPointerLeftButtonPressed, ui_cursor_from_el_data);

	cur_el = ui_win_find_el_by_id(g_main.tool_win, 16);
	cur_el->data = (void *)(&(t_cursor){ui_main_get_surface_by_id(g_main.ui_main, "fill_icon"), 14, 39});
	ui_event_add_listener(cur_el->events->onPointerLeftButtonPressed, ui_cursor_from_el_data);

	cur_el = ui_win_find_el_by_id(g_main.tool_win, 17);
	cur_el->data = (void *)(&(t_cursor){ui_main_get_surface_by_id(g_main.ui_main, "pipette_icon"), 14, 37});
	ui_event_add_listener(cur_el->events->onPointerLeftButtonPressed, ui_cursor_from_el_data);

	cur_el = ui_win_find_el_by_id(g_main.tool_win, 32);
	ui_event_add_listener(cur_el->events->onPointerLeftButtonPressed, clear_all_layers);

	cur_el = ui_win_find_el_by_id(g_main.main_win, 63001);
	ui_event_add_listener(cur_el->events->onPointerLeftButtonPressed, clear_layer);
	cur_el->data = ui_el_get_texture_by_id(ui_win_find_el_by_id(g_main.main_win, 63000), "default");

	// ui_set_pixel_color_to_texture(
	// 		g_main.main_win->sdl_renderer,
	// 		(t_texture *)g_main.layers.current_layer->sdl_textures->content,
	// 		(t_vec2){10, 10}, (SDL_Color){0, 0, 255, 155});

//	 cur_el = ui_win_find_el_by_id(g_main.tool_win, 12);
//	 cur_el->sdl_renderer = g_main.tool_win->sdl_renderer;
//	 cur_el->data = (void *)(&(t_cursor){ui_main_get_surface_by_id(g_main.ui_main, "brush"), 100, 100});
//	 ui_event_add_listener(cur_el->events->onPointerLeftButtonPressed, ui_cursor_from_el_data);
//
//	 cur_el = ui_win_find_el_by_id(g_main.tool_win, 14);
//	 ui_event_add_listener(cur_el->events->onPointerLeftButtonPressed, ui_cursor_to_default);
//
//	 ui_el_add_texture_from_file(cur_el, "/home_sbednar/21school/guimp_json/images/bl.png", "default");
//	 ui_el_add_texture_from_file_dialog(cur_el);

	ui_main_loop(g_main.ui_main);
	return (0);
}
