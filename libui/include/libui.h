/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 19:09:04 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/06 18:26:27 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_image.h>
# include "libft.h"
# include <math.h>

# define WIN_W		640
# define WIN_H		480

# define KEYS_COUNT	285

# define CAST_X_TO_Y(x, y)	((y)x)
# define QUEUE				t_list

# define WIN_MAIN			(1 << 0)
# define WIN_RESIZABLE		(1 << 1)

# define FUNCTION_SUCCESS	0
# define FUNCTION_FAILURE	1

typedef void		(*func_ptr)(void *, void *);
typedef int			(*pred_ptr)(void *, void *);
typedef	SDL_Rect	t_rect;

/*
** Smart things:
** 1) It's possible to replace t_name_init just by ft_bzero in code;
** ...To be continued...
*/

# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunknown-pragmas"

# pragma region		t_vec2

typedef struct		s_vec2
{
	int				x;
	int				y;
}					t_vec2;

# pragma endregion
# pragma region		t_fvec2

typedef struct		s_fvec2
{
	float			x;
	float			y;
}					t_fvec2;

# pragma endregion
# pragma region		t_fvec2

typedef struct		s_frect
{
	float			x;
	float			y;
	float			w;
	float			h;
}					t_frect;

# pragma endregion
# pragma region		t_ui_event

typedef struct		s_ui_event
{
	t_list			*events;
}					t_ui_event;

void				ui_event_init(t_ui_event *e);
int					ui_event_add_listener(t_ui_event *e, func_ptr f);
void				ui_event_invoke(t_ui_event *e, void *a1, void *a2);
void				ui_event_clear(t_ui_event *e);

# pragma endregion
# pragma region		t_ui_el_events

typedef struct		s_ui_el_events
{
	t_ui_event		onPointerEnter;
	t_ui_event		onPointerStay;
	t_ui_event		onPointerExit;
	t_ui_event		onPointerLeftButtonPressed;
	t_ui_event		onPointerLeftButtonHold;
	t_ui_event		onPointerLeftButtonReleased;
	t_ui_event		onPointerRightButtonPressed;
	t_ui_event		onPointerRightButtonHold;
	t_ui_event		onPointerRightButtonReleased;
	t_ui_event		onScrollUp;
	t_ui_event		onScrollDown;
}					t_ui_el_events;

# pragma endregion
# pragma region		t_ui_el

typedef struct		s_ui_el
{
	SDL_Surface		*sdl_surface;
	SDL_Texture		*sdl_texture;
	struct s_ui_el	*parent;
	t_list			*children;
	t_rect			rect;
	t_frect			frect;
	t_ui_el_events	events;
	int				id; //for bfs test
	// TODO: t_ui_graphics
}					t_ui_el;

# pragma endregion
# pragma region		t_ui_win_events

typedef struct		s_ui_win_events
{
	t_ui_event		onMouseMoved;
	t_ui_event		onMouseButtonDown;
	t_ui_event		onMouseButtonUp;
	t_ui_event		onFocusGained;
	t_ui_event		onFocusLost;
	t_ui_event		onResize;
	t_ui_event		onClose;
	t_ui_event		onKeyDown[KEYS_COUNT];
	t_ui_event		onKeyUp[KEYS_COUNT];
}					t_ui_win_events;

# pragma endregion
# pragma region		t_ui_win

typedef struct		s_ui_win
{
	SDL_Window		*sdl_window;
	SDL_Renderer	*sdl_renderer;
	Uint32			sdl_windowID;
	char			*title;
	t_ui_el			canvas;
	t_ui_win_events	events;
	Uint32			params;
}					t_ui_win;

# pragma endregion
# pragma region		t_ui_raycaster

typedef struct		s_ui_raycaster
{
	t_ui_el			*selected;
}					t_ui_raycaster;

int					ui_el_is_pointer_inside(void *a1, void *a2);

# pragma endregion
# pragma region		t_ui_main

typedef struct		s_ui_main
{
	t_list			*windows;
	SDL_Event		sdl_event;
	t_ui_raycaster	raycaster;
}					t_ui_main;

t_ui_el				*ui_raycast(t_ui_main *m, Uint32 windowID);

void				ui_main_init(t_ui_main *m);
void				ui_main_loop(t_ui_main *m);
int					ui_main_add_window(t_ui_main *m, t_ui_win *w);

t_ui_win			*ui_main_find_window_by_id(t_ui_main *m, Uint32 windowID);
void				ui_main_remove_window_by_id(t_ui_main *m, Uint32 windowID);

void				ui_main_handle_event(t_ui_main *m);
void				ui_main_handle_window_event(t_ui_main *m);
void				ui_main_handle_mouse_event(t_ui_main *m);
void				ui_main_handle_keyboard_event(t_ui_main *m);
// void				ui_main_handle_key_down(t_ui_main *m);
// void				ui_main_handle_key_up(t_ui_main *m);

// void				ui_main_handle_mouse_motion(t_ui_main *m);
// void				ui_main_handle_mouse_button_down(t_ui_main *m);
// void				ui_main_handle_mouse_button_up(t_ui_main *m);
// void				ui_main_handle_quit(t_ui_main *m);

# pragma endregion
# pragma region		log_functions

void				ui_log_mouse_motion(void *a1, void *a2);
void				ui_log_mouse_button_up(void *a1, void *a2);
void				ui_log_mouse_button_down(void *a1, void *a2);

void				ui_log_window_focus_gained(void *a1, void *a2);
void				ui_log_window_focus_lost(void *a1, void *a2);
void				ui_log_window_closed(void *a1, void *a2);
void				ui_log_window_resized(void *a1, void *a2);

void				ui_log_el_pointer_enter(void *a1, void *a2);
void				ui_log_el_pointer_stay(void *a1, void *a2);
void				ui_log_el_pointer_exit(void *a1, void *a2);

void				ui_log_key_pressed(void *a1, void *a2);
void				ui_log_key_released(void *a1, void *a2);

# pragma endregion

// void				ui_create_env(t_env *e, const int w, const int h);
// void				ui_create_win(t_env *e, const char *name);
// SDL_Surface			*ui_create_sur(const int w, const int h);
// void				ui_create_frame(t_env *e);

// int					ui_get_events(t_env *e);

// void				ui_set_pixel(t_env *e, const int x, const int y,
						// const Uint32 c);

// int					ui_loop(void *ev);

// void				ui_exit_with_msg(t_env *e, const char *msg);
// void				ui_exit(t_env *e);

# pragma region		BFS_func


void				q_push(QUEUE **q, t_list *el);
void				*q_pop(QUEUE **q);
// void				bfs_iter_root(const t_ui_el *root, void(*f)(const void *arg)); //need to be tested
// t_ui_el				*bfs_root(const t_ui_el *root, int(*f)(const void *arg));

t_ui_el				*bfs_root(t_ui_main *m, const t_ui_el *root, pred_ptr p);

# pragma endregion

# pragma region draw
void				ui_draw(t_ui_main *m);
void				ui_draw_window(t_ui_win *w);
void				ui_draw_windows(t_ui_main *m);

void				ui_clear_windows(t_ui_main *m);

void				ui_show_window(t_ui_win *w);
void				ui_show_windows(t_ui_main *m);
# pragma region		t_ui_el_func

void				ui_el_init(t_ui_el *el);
void				ui_el_set_abs_size(t_ui_el *el, int x, int y);//need to be tested
void				ui_el_set_rel_size(t_ui_el *el, float x, float y); //need to be tested
void				ui_el_set_abs_pos(t_ui_el *el, int x, int y);//need to be tested
void				ui_el_set_rel_pos(t_ui_el *el, float x, float y);//need to be tested
int					ui_el_add_child(t_ui_el *el, t_ui_el *child);

int					ui_el_load_surface_from(t_ui_el *el, const char *path);//, const int img_flag)
int					ui_el_create_texture(t_ui_el *el);

# pragma endregion

void	ui_win_create(t_ui_win *w);
void	ui_win_init(t_ui_win *w);
void	ui_win_close(t_ui_win *w);

int		ui_sdl_init(void);
void	ui_sdl_deinit(int exit_status);

# pragma GCC diagnostic pop

#endif
