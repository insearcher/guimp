/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 04:01:11 by edraugr-          #+#    #+#             */
/*   Updated: 2019/04/22 04:22:25 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	draw_dot(void *ui_main, void *ui_el)
{
	t_ui_main	*m;
	t_ui_el		*el;

	m = (t_ui_main *)ui_main;
	el = (t_ui_el *)ui_el;
	SDL_SetRenderDrawColor(el->sdl_renderer, 255, 0, 0, 255);
	SDL_RenderDrawPoint(el->sdl_renderer, m->sdl_event.motion.x, m->sdl_event.motion.y);

}
