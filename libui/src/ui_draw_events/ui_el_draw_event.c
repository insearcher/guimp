/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_draw_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:23:17 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/10 14:06:48 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_draw_event(void *el_v, void *arg)
{
	t_ui_el	*el;

	el = (t_ui_el *)el_v;
	arg = NULL;
	if (arg == NULL)
	{
		// SDL_RenderCopy(el->sdl_renderer, el->sdl_texture, NULL, &el->rect);  //legacy
		SDL_RenderCopy(el->sdl_renderer, ui_el_get_current_texture(el), NULL, &el->rect);
	}
}
