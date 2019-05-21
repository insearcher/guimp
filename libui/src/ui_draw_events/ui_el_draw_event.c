/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_draw_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:23:17 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/21 07:21:09 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void	get_texture_params(SDL_Texture *texture, t_rect *srect,
		int *width, int *height)
{
	SDL_QueryTexture(texture, NULL, NULL, width, height);
	srect->x = 0;
	srect->y = 0;
	srect->w = *width;
	srect->h = *height;
}


static void	cutting_texture_and_draw(t_ui_el *el, SDL_Texture *texture)
{
	t_rect		tmp_rect;
	t_rect		srect;
	int			width;
	int			height;
	int			x;
//	int			y;

	tmp_rect = el->rect;
	get_texture_params(texture, &srect, &width, &height);
	if (el->rect.x < el->parent->rect.x)
	{
		x = el->parent->rect.x - el->rect.x;
		srect.x = x * (width / el->rect.w);
		srect.w = width - srect.x; 
		tmp_rect.x = el->parent->rect.x;
		tmp_rect.w = el->rect.w - x;
	}
	if (el->rect.x + el->rect.w > el->parent->rect.x + el->parent->rect.w)
	{
		srect.x = 0;
		tmp_rect.w = el->parent->rect.x + el->parent->rect.w - el->rect.x;
		srect.w = (tmp_rect.w) * (width / el->rect.w);
		tmp_rect.x = el->rect.x;
	}
	SDL_RenderCopy(el->sdl_renderer, texture, &srect, &tmp_rect);
	return ;

}

void	ui_el_draw_event(void *el_v, void *arg)
{
	t_ui_el		*el;
	SDL_Texture	*texture;

	arg = NULL;
	el = (t_ui_el *)el_v;
	texture = ui_el_get_current_texture(el);
	if (el->params & EL_IS_DEPENDENT)
	{
		if (el->rect.x > el->parent->rect.x + el->parent->rect.w ||
				el->rect.x + el->rect.w < el->parent->rect.x ||
				el->rect.y > el->parent->rect.y + el->parent->rect.h ||
				el->rect.y + el->rect.h < el->parent->rect.y)
			return ;
		cutting_texture_and_draw(el, texture);
		return ;
	}
	SDL_RenderCopy(el->sdl_renderer, texture, NULL, &el->rect);
}

//		printf("w: %d, h: %d, id: %d\n", width, height, el->id);
//		printf("frect.w %f\n", el->frect.w);
