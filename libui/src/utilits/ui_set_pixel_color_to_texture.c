/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_set_pixel_color_to_texture.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:42:19 by edraugr-          #+#    #+#             */
/*   Updated: 2019/06/27 18:12:09 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_set_pixel_color_to_texture(SDL_Renderer *renderer,
		SDL_Texture *texture, t_vec2 coord, SDL_Color color)
{
	SDL_SetRenderTarget(renderer, texture);
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawPoint(renderer, coord.x, coord.y);
	SDL_SetRenderTarget(renderer, NULL);
}

void	ui_set_pixel_color_to_texture_replace(SDL_Renderer *renderer,
		SDL_Texture *texture, t_vec2 coord, SDL_Color color)
{
	SDL_BlendMode	pb;

	SDL_GetRenderDrawBlendMode(renderer, &pb);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
	SDL_SetRenderTarget(renderer, texture);
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawPoint(renderer, coord.x, coord.y);
	SDL_SetRenderTarget(renderer, NULL);
	SDL_SetRenderDrawBlendMode(renderer, pb);
}