/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_create_modal_ok.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 06:17:29 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/11 22:42:08 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

/* static void	create_modal_ok(t_ui_main *m, t_ui_modal_win *modal_win, t_ui_el *p)
{
	int     i;
	t_ui_el *el;
	t_ui_el *el_text;
	float   h;
	float   y;

	i = 0;
	el = ui_el_init();
	el->id = 2;
	ui_el_add_child(p, el);
	ui_el_set_pos(el, PIXEL, (t_fvec2){0.5 * modal_win->size.x - 100, modal_win->size.y - 90});
	ui_el_set_size(el, PIXEL, (t_fvec2){200, 65});
	ui_el_add_color_texture(el, (t_vec2){el->rect.w, el->rect.h},
			ft_atoi_base("AAAAAA", 16), "default");
	ui_el_setup_default(el);
	el_text = ui_el_init();
	el_text->id = 3;
	ui_el_add_child(el, el_text);
	ui_el_set_pos(el_text, 0, (t_fvec2){0.3, 0});
	ui_el_set_size(el_text, 0, (t_fvec2){0.4, 1});
	ui_el_set_text(m, el_text, "SansSerif",
			(t_text_params){(SDL_Color){0, 0, 0, 0}, (SDL_Color){170, 170, 170, 0}, 0, 0, TEXT_IS_BLENDED});
	ui_el_update_text(el_text, "OK");
	ui_el_setup_default(el_text);
	el_text->params |= EL_IGNOR_RAYCAST;
	h = 40;
	y = 10;
	while (modal_win->text[i])
	{
		el = ui_el_init();
		el->id = i + 5;
		el->params |= EL_IS_DEPENDENT;
		el->text_area = (t_ui_text *)ft_memalloc(sizeof(t_ui_text));
		ui_el_add_child(p, el);
		ui_el_set_pos(el, PIXEL, (t_fvec2){150, y});
		ui_el_set_size(el, PIXEL, (t_fvec2){modal_win->size.x - 150, h});
		y += h + 5;
		ui_el_set_text(m, el, "SansSerif", (t_text_params){(SDL_Color){0, 0, 0, 0},
				(SDL_Color){170, 170, 170, 0}, 0, 0, TEXT_IS_SOLID});
		el->text_area->params |= modal_win->params;
		el->text_area->params |= TEXT_IS_REGULAR;
		ui_el_update_text(el, modal_win->text[i]);
		ui_el_setup_default(el);
		i++;
	}
}*/

void    ui_el_create_modal_ok(void *a1, void *a2)
{
	t_ui_main   *m;
	t_ui_el     *el;
	// t_ui_win    *w;
	int			status;

	m = (t_ui_main *)a1;
	el = (t_ui_el *)a2;
	status = 1;
//	while (status != 0)
//		status = SDL_TryLockMutex(m->mutex);
//	if (status == 0)
//	SDL_LockMutex(m->mutex);
	if (ui_main_find_window_by_id(m, el->modal_win->w_id))
		return ;
	m->modal_el = el;
//	SDL_UnlockMutex(m->mutex);
}
