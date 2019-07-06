/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_merge_layers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:00:21 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/06 20:19:39 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

SDL_Texture	*ui_main_merge_layers(SDL_Renderer *r, t_list *l)
{
	SDL_Texture	*res;

	res = SDL_CreateTexture(r, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, 1400, 800);
	SDL_SetRenderTarget(r, res);
	SDL_SetRenderDrawBlendMode(r, SDL_BLENDMODE_NONE);
	SDL_SetRenderDrawColor(r, 255, 255, 255, 0);
	SDL_SetTextureBlendMode(res, SDL_BLENDMODE_BLEND);
	SDL_RenderFillRect(r, NULL);
	SDL_SetRenderDrawBlendMode(r, SDL_BLENDMODE_BLEND);
	while (l)
	{
		SDL_RenderCopy(r, (SDL_Texture *)l->content, NULL, NULL);
		l = l->next;
	}
	return (res);
}
