/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_try_to_create_modal_window.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*       5                                        +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 06:37:48 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/28 10:30:17 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void	modal_ok(t_ui_main *m, t_ui_modal_win *modal_win, t_ui_el *p)
{
	int		i;
	int		j;
	t_ui_el	*el;
	float	h;
	float	y;

	i = 0;
	j = -1;
	while (modal_win->text[i])
		i++;
	SDL_Log("TEXT_SIZE: %d\n", i);
	h = 1 / (float)i - 0.3;
	y = 0.05;
	while (++j < i)
	{
		el = ui_el_init();
		el->id = j + 2;
		el->params |= EL_IS_DEPENDENT;
		ui_el_setup_default(el);
		ui_el_add_child(p, el);
		ui_el_set_pos(el, 0, (t_fvec2){0.05, y});
		ui_el_set_size(el, 0, (t_fvec2){0.9, h});
		y += h + 0.1;
		ui_el_set_text(m, el, "SansSerif", (t_text_params){(SDL_Color){0, 0, 0, 0},
				(SDL_Color){170, 170, 170, 0}, 0, TEXT_IS_CENTERED, 0});
		ui_el_update_text(el, modal_win->text[j]);
	}

}

static void	create_modal_window(t_ui_main *m, t_ui_el *el)
{
	t_ui_el     *win_el;
	t_ui_win    *w;

	w = ui_win_init();
	w->id = el->modal_win.w_id;
	w->pos = el->modal_win.w_pos;
	w->size = el->modal_win.w_size;
	w->title = ft_strdup(el->modal_win.title);
	ui_win_setup_default(w);
	ui_win_create(w);
	ui_main_add_window(m, w);

	win_el = ui_el_init();
	win_el->id = 1;
	ui_el_setup_default(win_el);
	ui_el_add_child(w->canvas, win_el);
	ui_el_set_pos(win_el, 0, (t_fvec2){0, 0});
	ui_el_set_size(win_el, 0, (t_fvec2){1, 1});
	ui_el_add_color_texture(win_el, (t_vec2){win_el->rect.w, win_el->rect.h},
			ft_atoi_base("757575", 16), "default");
	ui_event_add_listener(w->events->onClose, ui_main_close_window);

	if (el->params & EL_MODAL_OK)
		modal_ok(m, &el->modal_win, win_el);
}

void	ui_win_try_to_create_modal_window(t_ui_main *m)
{
	t_list	*node;
	t_ui_el	*cur_el;

	node = m->modal_win_els;
	while (node)
	{
		cur_el = (t_ui_el *)node->content;
		if (cur_el->params & EL_IS_INVOKE_WIN)
		{
			cur_el->params &= ~EL_IS_INVOKE_WIN;
			if (ui_main_find_window_by_id(m, cur_el->modal_win.w_id) == NULL)
				create_modal_window(m, cur_el);
			return ;
		}
		node = node->next;
	}
}
