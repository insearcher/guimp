/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_w1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 07:27:34 by sbecker           #+#    #+#             */
/*   Updated: 2019/05/26 17:06:03 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp_test.h"

void	initialization_w1(t_guimp *guimp)
{
	t_ui_win w;

	ui_win_init(&w);
	w.title = ft_strdup("TEST1");
	w.params = WIN_MAIN | WIN_RESIZABLE;
	w.size = (t_vec2){800, 600};
	ui_event_add_listener(&(w.events.onResize), &ui_win_update_size);
	ui_win_setup_default(&w);
	ui_win_create(&w);
	w.canvas.sdl_renderer = w.sdl_renderer;
	ui_el_add_texture_from_main_by_id(&(guimp->m), &(w.canvas), "test3", "default");
	ui_el_add_empty_texture(&(w.canvas), w.canvas.rect.w, w.canvas.rect.h, "draw_texture");
	ui_event_add_listener(&(w.canvas.events.onRender), &draw_main_canvas_event);
	ui_event_add_listener(&(w.canvas.events.onPointerLeftButtonHold), &draw_dot);
	w.canvas.id = 100;
	guimp->w1 = w;
}
