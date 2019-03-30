/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 19:09:04 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/31 02:29:52 by sbednar          ###   ########.fr       */
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

# define WIN_RESIZABLE		(1 << 0)
# define WIN_MAIN			(1 << 1)
# define CAST_X_TO_Y(x, y)	((y)x)
# define QUEUE				t_list

# define FUNCTION_SUCCESS	0
# define FUNCTION_FAILURE	1

typedef void		(*func_ptr)(void *, void *);
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
	t_list			*last;
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
	struct s_ui_el	*parent;
	t_list			*children;
	t_rect			rect;
	t_frect			frect;
	t_ui_el_events	events;
	int				test; //for bfs test
	// TODO: t_ui_graphics
}					t_ui_el;

# pragma endregion
# pragma region		t_ui_win_events

typedef struct		s_ui_win_events
{
	t_ui_event		onFocusGained;
	t_ui_event		onFocusLost;
	t_ui_event		onResize;
	t_ui_event		onClose;
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
	int				properties;
}					t_ui_win;

# pragma endregion
# pragma region		t_ui_raycaster

typedef struct		s_ui_raycaster
{
	t_ui_el			*selected;
}					t_ui_raycaster;

# pragma endregion
# pragma region		t_ui_main

typedef struct		s_ui_main
{
	t_list			*windows;
	SDL_Event		sdl_event;
	t_ui_raycaster	raycaster;
}					t_ui_main;

void				ui_main_init(t_ui_main *m);
void				ui_main_loop(t_ui_main *m);
int					ui_main_add_window(t_ui_main *m, t_ui_win *w);

t_ui_win			*ui_main_find_window_by_id(t_ui_main *m, Uint32 windowID);
void				ui_main_remove_window_by_id(t_ui_main *m, Uint32 windowID);

void				ui_main_handle_event(t_ui_main *m);
void				ui_main_handle_window_event(t_ui_main *m);
void				ui_main_handle_key_down(t_ui_main *m);
void				ui_main_handle_key_up(t_ui_main *m);
void				ui_main_handle_mouse_motion(t_ui_main *m);
void				ui_main_handle_mouse_button_down(t_ui_main *m);
void				ui_main_handle_mouse_button_up(t_ui_main *m);
void				ui_main_handle_quit(t_ui_main *m);

# pragma endregion

typedef struct		s_sdl
{
	SDL_Event		evt;
	SDL_Window		*win;
	SDL_Renderer	*ren;
}					t_sdl;

typedef struct		s_env
{
	int				w;
	int				h;
	int				m_pos[2];
	t_sdl			sdl;
	SDL_Surface		*sur;
	SDL_Texture		*tex;
	void 			(*frame)(struct s_env *e);
	int 			(*event)(struct s_env *e);
	const Uint8		*state;
	int				events;
}					t_env;

void				ui_create_env(t_env *e, const int w, const int h);
void				ui_create_win(t_env *e, const char *name);
SDL_Surface			*ui_create_sur(const int w, const int h);
void				ui_create_frame(t_env *e);

int					ui_get_events(t_env *e);

void				ui_set_pixel(t_env *e, const int x, const int y,
						const Uint32 c);

int					ui_loop(void *ev);

void				ui_exit_with_msg(t_env *e, const char *msg);
void				ui_exit(t_env *e);

# pragma region		BFS_func

void				q_push(QUEUE **q, t_list *el);
void				*q_pull(QUEUE **q);
void				bfs_iter(const t_list *root, void(*f)(const void *arg)); //need to be tested

# pragma endregion
# pragma region		t_ui_el_func

t_ui_el				*ui_el_init(t_ui_el *paren, t_list *children);
void				ui_el_set_abs_size(t_ui_el *el, int x, int y);//need to be tested
void				ui_el_set_rel_size(t_ui_el *el, float x, float y); //need to be tested
void				ui_el_set_abs_pos(t_ui_el *el, int x, int y);//need to be tested
void				ui_el_set_rel_pos(t_ui_el *el, float x, float y);//need to be tested
void				ui_el_add_child(t_ui_el *el, t_ui_el *child);

# pragma endregion

void	ui_win_create(t_ui_win *w);
void	ui_win_init(t_ui_win *w);
void	ui_win_close(t_ui_win *w);

int		ui_sdl_init(void);
void	ui_sdl_deinit(void);

# pragma GCC diagnostic pop

#endif
