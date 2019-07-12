/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_util_set_pixel_color_to_texture.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 08:45:19 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/12 08:47:03 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

/*void	ui_set_pixel_color_to_texture(SDL_Renderer *renderer, // doesn't exist in header, not used.
		SDL_Texture *texture, t_vec2 coord, SDL_Color color)
{
	SDL_SetRenderTarget(renderer, texture);
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawPoint(renderer, coord.x, coord.y);
	SDL_SetRenderTarget(renderer, NULL);
}*/

void	ui_util_set_pixel_color_to_texture_replace(SDL_Renderer *renderer,
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
