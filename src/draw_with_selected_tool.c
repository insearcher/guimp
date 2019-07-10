/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_with_selected_tool.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 00:41:52 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/10 16:20:28 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

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

//static void	ui_draw_circle(SDL_Renderer *ren, t_rect c, SDL_BlendMode b, SDL_Color color)
//{
//	SDL_BlendMode	bm;
//
//	SDL_GetRenderDrawBlendMode(ren, &bm);
//	SDL_SetRenderDrawBlendMode(ren, b);
//	SDL_SetRenderDrawColor(ren, color.r, color.g, color.b, color.a);
//
////	int x = 0, y = r;
////	int d = 3 - 2 * r;
////	drawCircle(xc, yc, x, y);
////	while (y >= x)
////	{
////		// for each pixel we will
////		// draw all eight pixels
////
////		x++;
////
////		// check for decision parameter
////		// and correspondingly
////		// update d, x, y
////		if (d > 0)
////		{
////			y--;
////			d = d + 4 * (x - y) + 10;
////		}
////		else
////			d = d + 4 * x + 6;
////		drawCircle(xc, yc, x, y);
////		delay(50);
////	}
//
//	int	x = c.x - c.h - 1;
//
//	while (x <= c.x + c.h + 1)
//	{
//		int	y = c.y - c.h - 1;
//		while (y <= c.y + c.h + 1)
//		{
//			if ((x - c.x) * (x - c.x) + (y - c.y) * (y - c.y) <= c.h * c.h)
//			{
//				SDL_RenderDrawPoint(ren, x, y);
//			}
//			++y;
//		}
//		++x;
//	}
//	SDL_SetRenderDrawBlendMode(ren, bm);
//}

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
        tool_brush(el, g, x, y);
    else if (g->draw_tool.tool == GM_TOOL_HAND)
        tool_hand(g);
    else if (g->draw_tool.tool == GM_TOOL_PIPETTE)
        tool_pipette(g, el);
    else if (g->draw_tool.tool == GM_TOOL_ERASER)
		tool_eraser(el, g, x, y);
}
