/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_with_selected_tool.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 00:41:52 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/03 15:23:16 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

static void tool_hand(t_guimp *g)
{
    g->zoom_rect.x += (abs(g->draw_tool.prew_point.x - g->draw_tool.cur_point.x) >= GM_HAND_MIN_DIST ? g->draw_tool.prew_point.x - g->draw_tool.cur_point.x : 0) * GM_HAND_MOVE_SPEED;
    g->zoom_rect.y += (abs(g->draw_tool.prew_point.y - g->draw_tool.cur_point.y) >= GM_HAND_MIN_DIST ? g->draw_tool.prew_point.y - g->draw_tool.cur_point.y : 0) * GM_HAND_MOVE_SPEED;
    g->zoom_rect.x = g->zoom_rect.x < 0 ? 0 : g->zoom_rect.x;
    g->zoom_rect.x = g->zoom_rect.x + g->zoom_rect.w > GM_IMAGE_SIZE_X ? GM_IMAGE_SIZE_X - g->zoom_rect.w : g->zoom_rect.x;
    g->zoom_rect.y = g->zoom_rect.y < 0 ? 0 : g->zoom_rect.y;
    g->zoom_rect.y = g->zoom_rect.y + g->zoom_rect.h > GM_IMAGE_SIZE_Y ? GM_IMAGE_SIZE_Y - g->zoom_rect.h : g->zoom_rect.y;
}

static void tool_brush(t_ui_el *el, t_guimp *g, int x, int y)
{
    SDL_SetRenderTarget(el->sdl_renderer, (SDL_Texture *)(g->layers.current_layer->sdl_textures->content));
    SDL_SetTextureColorMod(ui_el_get_texture_by_id(el, "brush"), g->draw_tool.r, g->draw_tool.g, g->draw_tool.b); //вместо ui_el_get_texture_by_id(el, "brush") нужно выбрать текстуру текущей кисти
    SDL_SetTextureAlphaMod(ui_el_get_texture_by_id(el, "brush"), g->draw_tool.a);
    SDL_RenderCopy(el->sdl_renderer, ui_el_get_texture_by_id(el, "brush"), NULL,
                   &((t_rect){x - g->draw_tool.brush_size / 2, y - g->draw_tool.brush_size / 2,
                              g->draw_tool.brush_size, g->draw_tool.brush_size})); //вместо ui_el_get_texture_by_id(el, "brush") нужно выбрать текстуру текущей кисти
    SDL_SetRenderTarget(el->sdl_renderer, NULL);
}

//static void	ui_draw_circle_2(int xc, int yc, int x, int y)
//{
//	putpixel(xc+x, yc+y, RED);
//	putpixel(xc-x, yc+y, RED);
//	putpixel(xc+x, yc-y, RED);
//	putpixel(xc-x, yc-y, RED);
//	putpixel(xc+y, yc+x, RED);
//	putpixel(xc-y, yc+x, RED);
//	putpixel(xc+y, yc-x, RED);
//	putpixel(xc-y, yc-x, RED);
//}

static void	ui_draw_circle(SDL_Renderer *ren, t_rect c, SDL_BlendMode b, SDL_Color color)
{
	SDL_BlendMode	bm;

	SDL_GetRenderDrawBlendMode(ren, &bm);
	SDL_SetRenderDrawBlendMode(ren, b);
	SDL_SetRenderDrawColor(ren, color.r, color.g, color.b, color.a);

//	int x = 0, y = r;
//	int d = 3 - 2 * r;
//	drawCircle(xc, yc, x, y);
//	while (y >= x)
//	{
//		// for each pixel we will
//		// draw all eight pixels
//
//		x++;
//
//		// check for decision parameter
//		// and correspondingly
//		// update d, x, y
//		if (d > 0)
//		{
//			y--;
//			d = d + 4 * (x - y) + 10;
//		}
//		else
//			d = d + 4 * x + 6;
//		drawCircle(xc, yc, x, y);
//		delay(50);
//	}

	int	x = c.x - c.h - 1;

	while (x <= c.x + c.h + 1)
	{
		int	y = c.y - c.h - 1;
		while (y <= c.y + c.h + 1)
		{
			if ((x - c.x) * (x - c.x) + (y - c.y) * (y - c.y) <= c.h * c.h)
			{
				SDL_RenderDrawPoint(ren, x, y);
			}
			++y;
		}
		++x;
	}
	SDL_SetRenderDrawBlendMode(ren, bm);
}

static void	tool_eraser(t_ui_el *el, t_guimp *g, int x, int y)
{
	SDL_BlendMode	bm;
	int				s;

//	ui_draw_circle(el->sdl_renderer, (t_rect){x, y, 0, 200}, SDL_BLENDMODE_NONE, (SDL_Color){255,255,0,255});
	s = g->draw_tool.brush_size;
	SDL_SetRenderTarget(el->sdl_renderer, (SDL_Texture *)(g->layers.current_layer->sdl_textures->content));
	SDL_GetRenderDrawBlendMode(el->sdl_renderer, &bm);
	SDL_SetRenderDrawBlendMode(el->sdl_renderer, SDL_BLENDMODE_NONE);
	SDL_SetRenderDrawColor(el->sdl_renderer, 255, 255, 255, 0);
	SDL_RenderFillRect(el->sdl_renderer, &(t_rect){x - s, y - s, 2 * s, 2 * s});
	SDL_SetRenderTarget(el->sdl_renderer, NULL);
	SDL_SetRenderDrawBlendMode(el->sdl_renderer, bm);
}

void draw_with_selected_tool(void *main, void *el_v)
{
    t_guimp *g;
    t_ui_el *el;
    int x;
    int y;

    g = (t_guimp *)(((t_ui_main *)main)->data);
    el = (t_ui_el *)el_v;
    x = ((float)el->ptr_rel_pos.x / (float)el->rect.w) * g->zoom_rect.w + g->zoom_rect.x;
    y = ((float)el->ptr_rel_pos.y / (float)el->rect.h) * g->zoom_rect.h + g->zoom_rect.y;
    g->draw_tool.cur_point = (t_vec2){x, y};
    if (g->draw_tool.tool == GM_TOOL_BRUSH)
    {
//        g->draw_tool.prew_point = (t_vec2){x, y};
        tool_brush(el, g, x, y);
    }
    else if (g->draw_tool.tool == GM_TOOL_HAND)
        tool_hand(g);
    else if (g->draw_tool.tool == GM_TOOL_PIPETTE)
    {
        // int color = ui_get_pixel_color_from_texture(el->sdl_renderer, (t_texture *)(g->layers.layers->content), (t_vec2){x, y});
        int color = ui_get_pixel_color_from_el(el->sdl_renderer, el, (t_vec2){el->ptr_rel_pos.x, el->ptr_rel_pos.y});
        g->draw_tool.r = (color & 0xFF0000) >> 16;
        g->draw_tool.g = (color & 0x00FF00) >> 8;
        g->draw_tool.b = color & 0x0000FF;
        el = ui_win_find_el_by_id(g->tool_win, GM_TOOL_ID_SL_HEAD_RED);
        ui_el_set_new_pos(el, 0, PIXEL, (t_fvec2){-el->rect.w / 2 + g->draw_tool.r / 255.0f * el->parent->rect.w, 0});
        el = ui_win_find_el_by_id(g->tool_win, GM_TOOL_ID_SL_HEAD_GR);
        ui_el_set_new_pos(el, 0, PIXEL, (t_fvec2){-el->rect.w / 2 + g->draw_tool.g / 255.0f * el->parent->rect.w, 0});
        el = ui_win_find_el_by_id(g->tool_win, GM_TOOL_ID_SL_HEAD_BL);
        ui_el_set_new_pos(el, 0, PIXEL, (t_fvec2){-el->rect.w / 2 + g->draw_tool.b / 255.0f * el->parent->rect.w, 0});
        update_color_rect(g, g->draw_tool.r, g->draw_tool.g, g->draw_tool.b);
    }
    else if (g->draw_tool.tool == GM_TOOL_ERASER)
		tool_eraser(el, g, x, y);
}
