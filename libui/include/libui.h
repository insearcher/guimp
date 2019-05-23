/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 19:09:04 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/23 06:19:47 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H

# include <SDL.h>
# include <SDL_ttf.h>
# include <SDL_image.h>
# include "libft.h"
# include <math.h>

/*
** TODO:
** 1) текст
** 2) кнопки
** 3) картинки
** 4) скроллбары
** 5) прочее гавно
*/

# define KNRM				"\x1B[0m"
# define KRED				"\x1B[31m"
# define KGRN				"\x1B[32m"
# define KYEL				"\x1B[33m"
# define KBLU				"\x1B[34m"
# define KMAG				"\x1B[35m"
# define KCYN				"\x1B[36m"
# define KWHT				"\x1B[37m"

# define WIN_W				640
# define WIN_H				480

# define KEYS_COUNT			285

# define CAST_X_TO_Y(x, y)	((y)x)
# define QUEUE				t_list

# define FPS				150 // NE TROGAY PLS

# define EL_POS_ABSOLUTE	0
# define EL_POS_FLEXIBLE	1
# define EL_POS_RELATIVE	2

# define SCROLL_SPEED		10

//el params
# define EL_DYNAMIC_SIZE	(1 << 0)
# define EL_IGNOR_RAYCAST	(1 << 1)
# define EL_IS_HIDDEN		(1 << 2)
# define EL_IS_PTR_INSIDE	(1 << 3) // Smart using of params (replace BUTTON_OFF & ON)
// # define EL_IS_LMB_PRESSED	(1 << 4)
// # define EL_IS_RMB_PRESSED	(1 << 5)
# define EL_IS_SCROLLABLE	(1 << 6)
# define EL_IS_DEPENDENT	(1 << 7)

// KOSTIL
// # define EL_NOT_RELEASED	(1 << 31)

# define MAIN_LMB_PRESSED	(1 << 0)
# define MAIN_RMB_PRESSED	(1 << 1)
# define MAIN_SCROLL_UP		(1 << 2)
# define MAIN_SCROLL_DOWN	(1 << 3)
# define MAIN_LMB_RELEASED	(1 << 4)
# define MAIN_LMB_HOLD		(1 << 5)
# define MAIN_RMB_RELEASED	(1 << 6)
# define MAIN_RMB_HOLD		(1 << 7)
# define MAIN_ON_QUIT		(1 << 8)

//win params
# define WIN_MAIN			(1 << 0)
# define WIN_RESIZABLE		(1 << 1)

//func status
# define FUNCTION_SUCCESS	0
# define FUNCTION_FAILURE	1

//texture id`s
# define TID_DEFAULT		0
# define TID_ONFOCUSED		1
# define TID_ONACTIVE		2

//button status
# define BUTTON_OFF			0 // TODO: remove
# define BUTTON_ON			1 // TODO: remove

typedef	void		(*func_ptr)(void *, void *);
typedef	int			(*pred_ptr)(void *, void *);
typedef	SDL_Rect	t_rect;
typedef	t_list		t_list_texture;

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
int					ui_event_add_listener_front(t_ui_event *e, func_ptr f);
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
	t_ui_event		onRender;
}					t_ui_el_events;

# pragma endregion
# pragma region		t_ui_el

typedef struct		s_ui_text
{
	TTF_Font		*font;
	SDL_Color		color;
}					t_ui_text;

typedef struct		s_ui_el
{
	SDL_Surface		*sdl_surface;
	t_list			*sdl_textures;
	size_t			current_texture;
	SDL_Renderer	*sdl_renderer;
	struct s_ui_el	*parent;
	t_list			*children;
	t_rect			rect;
	t_rect			cut_rect;
	t_rect			rrect;	// TODO not used
	t_frect			frect;
	t_ui_el_events	events;
	Uint32			id;
	Uint32			params; // <- put there next parameters
	t_vec2			ptr_rel_pos;
	void			*data;
}					t_ui_el;

# pragma endregion
# pragma region		t_ui_win_events

typedef struct		s_ui_win_events
{
	t_ui_event		onPointerMoved;
	t_ui_event		onPointerLeftButtonPressed;
	t_ui_event		onPointerLeftButtonReleased;
	t_ui_event		onPointerRightButtonPressed;
	t_ui_event		onPointerRightButtonReleased;
	t_ui_event		onScrollUp;
	t_ui_event		onScrollDown;
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
	t_vec2			size;
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
	Uint32			cur_tick;
	Uint32			target_tick;
	Uint32			params;
	t_vec2			ptr_pos;
	t_list			*sdl_surfaces;
	t_list			*sdl_fonts;
}					t_ui_main;

t_ui_el				*ui_raycast(t_ui_main *m, Uint32 windowID);

void				ui_main_init(t_ui_main *m);
void				ui_main_loop(t_ui_main *m);
int					ui_main_add_window(t_ui_main *m, t_ui_win *w);

int					ui_main_add_font_by_path(t_ui_main *m, const char *path, int font_id);
int					ui_main_add_surface_by_path(t_ui_main *m, const char *path, int sur_id);
TTF_Font			*ui_main_get_font_by_id(t_ui_main *m, int font_id);
SDL_Surface			*ui_main_get_surface_by_id(t_ui_main *m, int sur_id);

void				ui_main_fill_default_surfaces(t_ui_main *m);

t_ui_win			*ui_main_find_window_by_id(t_ui_main *m, Uint32 windowID);
void				ui_main_remove_window_by_id(t_ui_main *m, Uint32 windowID);

void				ui_main_handle_event(t_ui_main *m);
void				ui_main_handle_raycast(t_ui_main *m);
void				ui_main_handle_window_event(t_ui_main *m);
void				ui_main_handle_mouse_event(t_ui_main *m);
void				ui_main_handle_keyboard_event(t_ui_main *m);
void				ui_main_handle_continious_event(t_ui_main *m, t_ui_el *el);

void				ui_main_pointer_moved(void *a1, void *a2);
void				ui_main_lmb_pressed(void *a1, void *a2);
void				ui_main_lmb_released(void *a1, void *a2);
void				ui_main_rmb_pressed(void *a1, void *a2);
void				ui_main_rmb_released(void *a1, void *a2);
void				ui_main_scroll_up(void *a1, void *a2);
void				ui_main_scroll_down(void *a1, void *a2);

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

void				ui_log_el_scroll_up(void *a1, void *a2);
void				ui_log_el_scroll_down(void *a1, void *a2);

void				ui_log_el_left_button_hold(void *a1, void *a2);
void				ui_log_el_left_button_pressed(void *a1, void *a2);
void				ui_log_el_left_button_released(void *a1, void *a2);

void				ui_log_el_right_button_pressed(void *a1, void *a2);
void				ui_log_el_right_button_released(void *a1, void *a2);
void				ui_log_el_right_button_hold(void *a1, void *a2);

void				ui_log_key_pressed(void *a1, void *a2);
void				ui_log_key_released(void *a1, void *a2);

# pragma endregion

# pragma region		BFS_func


void				q_push(QUEUE **q, t_list *el);
void				*q_pop(QUEUE **q);

void				bfs_iter(const t_list *root, const func_ptr f,
						const void *arg);
void				bfs_iter_root(const t_ui_el *root, const func_ptr f,
						const void *arg);
void				*bfs(t_ui_main *m, const t_list *root, pred_ptr p);
t_ui_el				*bfs_root(t_ui_main *m, const t_ui_el *root, pred_ptr p);

# pragma endregion

# pragma region draw

void				ui_draw(t_ui_main *m);
void				ui_draw_window(t_ui_win *w);
void				ui_draw_windows(t_ui_main *m);
void				ui_clear_windows(t_ui_main *m);
void				ui_show_window(t_ui_win *w);
void				ui_show_windows(t_ui_main *m);

void				ui_el_draw_event(void *el_v, void *arg);

# pragma region		t_ui_el_func

void				ui_el_init(t_ui_el *el);
void				ui_el_setup_default(t_ui_el *el);
void				ui_el_set_abs_size(t_ui_el *el, int x, int y);//need to be tested
void				ui_el_set_rel_size(t_ui_el *el, float x, float y); //need to be tested
void				ui_el_set_abs_pos(t_ui_el *el, int x, int y);//need to be tested
int					ui_el_add_child(t_ui_el *el, t_ui_el *child);
void				ui_el_change_pos(t_ui_el *el, int x, int y);

int					ui_el_load_surface_from(t_ui_el *el, const char *path);

SDL_Texture			*ui_el_create_texture(t_ui_el *el);
SDL_Texture			*ui_el_create_texture_from_surface(t_ui_el *el, SDL_Surface *sur);

int					ui_el_add_texture_from_file(t_ui_el *el,
						const char *path, int texture_id);
int					ui_el_add_empty_texture(t_ui_el *el, int w, int h,
						int texture_id);
SDL_Texture			*ui_el_get_current_texture(t_ui_el *el);
SDL_Texture			*ui_el_get_texture_by_id(t_ui_el *el, int id);
int					ui_el_set_current_texture_by_id(t_ui_el *el, int texture_id);

void				ui_el_default_pointer_enter(void *a1, void *a2);
void				ui_el_default_pointer_exit(void *a1, void *a2);

void				ui_el_setup_default_scroll_menu(t_ui_el *el);
void				ui_el_setup_default_scroll_menu_elem(t_ui_el *el, t_ui_el *el_parent);
void				ui_el_scroll_menu_up(void *a1, void *a2);
void				ui_el_scroll_menu_down(void *a1, void *a2);
void				ui_el_scroll_child_menu_up(void *a1, void *a2);
void				ui_el_scroll_child_menu_down(void *a1, void *a2);

void 				ui_el_drag(void *a1, void *a2);
void				ui_el_setup_default_draggable(t_ui_el *el);

void				ui_el_set_default_texture(void *a1, void *a2);
void				ui_el_set_focused_texture(void *a1, void *a2);
void				ui_el_set_active_texture(void *a1, void *a2);

void				ui_find_dynamic_elements(void *a1, void *a2);

int					ui_el_add_texture_from_main_by_id(t_ui_main *m, t_ui_el *el,
size_t id, int texture_id);

int					ui_el_setup_text(t_ui_main *m, t_ui_el *el, SDL_Color c, int font_id);
int					ui_el_update_text(t_ui_el *el, const char *text);

# pragma endregion

void				ui_win_create(t_ui_win *w);
void				ui_win_setup_default(t_ui_win *w);
void				ui_win_init(t_ui_win *w);
void				ui_win_close(t_ui_win *w);

void				ui_win_update_size(void *a1, void *a2);

int					ui_sdl_init(void);
void				ui_sdl_deinit(int exit_status);

# pragma GCC diagnostic pop

#endif
