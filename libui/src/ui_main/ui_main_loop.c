/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:26:26 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/12 11:13:37 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int	ui_main_loop_draw(void *d)
{
	t_ui_main	*m;

	m = (t_ui_main *)d;
//	SDL_Delay((Uint32)(2000.0f));
	while (1)
	{
		if (m->params & MAIN_ON_QUIT)
			return (1);
		SDL_LockMutex(m->mutex);
		ui_draw(m);
		SDL_UnlockMutex(m->mutex);
	}
	return (0);
}

static int	ui_main_loop_raycast(void *d)
{
	t_ui_main	*m;

	m = (t_ui_main *)d;
	while (1)
	{
		if (m->params & MAIN_ON_QUIT)
			return (1);
		SDL_LockMutex(m->mutex);
		ui_main_handle_raycast(m);
		SDL_UnlockMutex(m->mutex);
//		SDL_Delay((Uint32)(100.0f / FPS));
	}
	return (0);
}

void	create_modal_ok(t_ui_main *m, t_ui_modal_win *modal_win, t_ui_el *p)
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
}

void		ui_main_loop(t_ui_main *m)
{
	SDL_Thread	*thread;

	m->mutex = SDL_CreateMutex();
	thread = SDL_CreateThread(ui_main_loop_raycast, "ui_main_loop_raycast", (void *)m);
	SDL_DetachThread(thread);
	thread = SDL_CreateThread(ui_main_loop_draw, "ui_main_loop_draw", (void *)m);
	SDL_DetachThread(thread);
	while (1)
	{
		SDL_LockMutex(m->mutex);
 		if (m->modal_el)
		{
			t_ui_win *w = ui_win_create_modal_win(m->modal_el->modal_win);
//			ui_event_add_listener(w->events->onClose, ui_main_event_close_window);
			ui_event_add_listener(w->events->onKeyDown[SDL_SCANCODE_ESCAPE], ui_main_event_close_window);
			create_modal_ok(m, m->modal_el->modal_win, ui_win_find_el_by_id(w, 1));
			ui_main_add_window(m, w);
			m->modal_el = NULL;
		}
		else if (SDL_PollEvent(m->sdl_event))
			ui_main_handle_event(m);
		SDL_UnlockMutex(m->mutex);
	}
}
