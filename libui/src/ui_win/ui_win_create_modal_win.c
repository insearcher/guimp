/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_create_modal_win.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:45:53 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 13:54:23 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_ui_win	*ui_win_create_modal_win(t_ui_modal_win *modal_win)
{
	t_ui_win	*w;
	t_ui_el		*win_el;

	w = ui_win_init();
	w->id = modal_win->w_id;
	w->pos = modal_win->pos;
	w->size = modal_win->size;
	w->title = ft_strdup(modal_win->title);
	ui_win_create(w);
	ui_win_setup_default(w);
	win_el = ui_el_init();
	win_el->id = 1;
	ui_el_setup_default(win_el);
	ui_el_add_child(w->canvas, win_el);
	ui_el_set_pos(win_el, 0, (t_fvec2){0, 0});
	ui_el_set_size(win_el, 0, (t_fvec2){1, 1});
	ui_el_add_color_texture(win_el, (t_vec2){win_el->rect.w, win_el->rect.h},
			ft_atoi_base("757575", 16), "default");
	return (w);
}
