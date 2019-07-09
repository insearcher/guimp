/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 19:09:04 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/09 21:58:32 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H

# include <SDL.h>
# include <SDL_ttf.h>
# include <SDL_image.h>
# include <math.h>
# include "libft.h"
# include "libjtoc.h"

/*
** TODO:
** 1) текст
** 2) кнопки
** 3) картинки
** 4) скроллбары
** 5) прочее гавно
** 6) ФЛАГ ДЛЯ ОКНА, ШОБ ЗАКРЫТЬ НЕЛЬЗЯ БЫЛО
** 7)
*/

//# define DEBUG_STATUS

# define KNRM				"\x1B[0m"
# define KRED				"\x1B[31m"
# define KGRN				"\x1B[32m"
# define KYEL				"\x1B[33m"
# define KBLU				"\x1B[34m"
# define KMAG				"\x1B[35m"
# define KCYN				"\x1B[36m"
# define KWHT				"\x1B[37m"

# define KEYS_COUNT			285

# define CAST_X_TO_Y(x, y)	((y)x)
# define QUEUE				t_list

# define FPS				150 // NE TROGAY PLS

# define SCROLL_SPEED		20

//el params
# define EL_IGNOR_RAYCAST	(1 << 0)
# define EL_IS_HIDDEN		(1 << 1)
# define EL_IS_PTR_INSIDE	(1 << 2)
# define EL_IS_SCROLLABLE	(1 << 3)
# define EL_IS_DEPENDENT	(1 << 4)
# define EL_IS_TEXT			(1 << 5)
# define EL_MODAL_OK		(1 << 6)
# define EL_MODAL_OK_CANCEL	(1 << 7)
# define EL_IS_ICON			(1 << 8)

//text params
# define TEXT_IS_CENTERED	(1 << 0)
# define TEXT_IS_INPUTTING	(1 << 1)
# define TEXT_IS_REGULAR	(1 << 2)

//text render_params
# define TEXT_IS_SOLID		(1 << 0)
# define TEXT_IS_SHADED		(1 << 1)
# define TEXT_IS_BLENDED	(1 << 2)

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
# define WIN_RESIZABLE		(1 << 0)

# define IMG_TYPE_PNG		0
# define IMG_TYPE_JPG		1

//texture id`s
// # define TID_DEFAULT		0
// # define TID_ONFOCUSED	1
// # define TID_ONACTIVE	2

//button status
# define BUTTON_OFF			0 // TODO: remove
# define BUTTON_ON			1 // TODO: remove

//for set/chage pos/size
# define ABS			(1 << 0)
# define PIXEL			(1 << 1)

typedef	void			(*func_ptr)(void *, void *);
typedef	int				(*pred_ptr)(void *, void *);
typedef	SDL_Rect		t_rect;
typedef	SDL_Texture		t_texture;
typedef	t_list			t_list_texture;
typedef	SDL_Renderer	t_renderer;
typedef	SDL_Color		t_color;

/*
** Smart things:
** 1) It's possible to replace t_name_init just by ft_bzero in code;
** ...To be continued...
*/

# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunknown-pragmas"

# pragma region		t_frect

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

t_ui_event			*ui_event_init(void);
int					ui_event_add_listener(t_ui_event *e, func_ptr f);
int					ui_event_add_listener_front(t_ui_event *e, func_ptr f);
void				ui_event_invoke(t_ui_event *e, void *a1, void *a2);
void				ui_event_clear(t_ui_event *e);

# pragma endregion
# pragma region		t_ui_el_events


# pragma endregion
# pragma region		t_ui_el

typedef struct		s_ui_text
{
	TTF_Font		*font;
	SDL_Color		text_color;
	SDL_Color		bg_color;
	char			*text;
	size_t			max_text_size;
	size_t			cursor_pos;
	Uint32			render_param;
	Uint32			params;
}					t_ui_text;

typedef struct		s_ui_modal_win
{
	TTF_Font		*font;
	SDL_Color		text_color;
	SDL_Color		bg_color;
	int				w_id;
	t_vec2			w_pos;
	t_vec2			w_size;
	char			*title;
	char			**text;
	Uint32			render_param;
	Uint32			params;
	Uint32			output;
	char			*output_text;
}					t_ui_modal_win;

typedef struct		s_ui_el_events
{
	t_ui_event		*onPointerEnter;
	t_ui_event		*onPointerStay;
	t_ui_event		*onPointerExit;
	t_ui_event		*onPointerLeftButtonPressed;
	t_ui_event		*onPointerLeftButtonHold;
	t_ui_event		*onPointerLeftButtonReleased;
	t_ui_event		*onPointerRightButtonPressed;
	t_ui_event		*onPointerRightButtonHold;
	t_ui_event		*onPointerRightButtonReleased;
	t_ui_event		*onScrollUp;
	t_ui_event		*onScrollDown;
	t_ui_event		*onRender;
	t_ui_event		*onResize;
}					t_ui_el_events;

t_ui_el_events		*ui_el_events_init(void);

typedef struct		s_ui_el
{
	SDL_Surface		*sdl_surface;
	t_list			*sdl_textures;
	SDL_Renderer	*sdl_renderer;
	struct s_ui_el	*parent;
	t_list			*children;
	size_t			current_texture;
	t_rect			rect;
	t_rect			cut_rect;
	t_frect			relative_rect;
	t_vec2			ptr_rel_pos;
	Uint32			id;
	Uint32			params;
	t_ui_text		*text_area;
	t_ui_modal_win	*modal_win;
	t_ui_el_events	*events;
	void			*data;
}					t_ui_el;

typedef struct		s_cursor
{
	SDL_Surface		*s;
	int				hot_x;
	int				hot_y;
}					t_cursor;

t_cursor			*ui_cursor_init(void);

void				ui_cursor_to_default(void *a1, void *a2);
void				ui_cursor_from_el_data(void *a1, void *a2);
void				ui_cursor_from(t_cursor *c);

# pragma endregion
# pragma region		t_ui_win_events

typedef struct		s_ui_win_events
{
	t_ui_event		*onPointerMoved;
	t_ui_event		*onPointerEnter;
	t_ui_event		*onPointerExit;
	t_ui_event		*onPointerLeftButtonPressed;
	t_ui_event		*onPointerLeftButtonReleased;
	t_ui_event		*onPointerRightButtonPressed;
	t_ui_event		*onPointerRightButtonReleased;
	t_ui_event		*onScrollUp;
	t_ui_event		*onScrollDown;
	t_ui_event		*onFocusGained;
	t_ui_event		*onFocusLost;
	t_ui_event		*onResize;
	t_ui_event		*onClose;
	t_ui_event		*onMoved;
	t_ui_event		**onKeyDown;
	t_ui_event		**onKeyUp;
}					t_ui_win_events;

t_ui_win_events		*ui_win_events_init(void);

# pragma endregion
# pragma region		t_ui_win

typedef struct		s_ui_win
{
	SDL_Window		*sdl_window;
	SDL_Renderer	*sdl_renderer;
	Uint32			sdl_windowID;
	char			*title;
	t_vec2			size;
	t_vec2			pos;
	t_ui_el			*canvas;
	t_ui_win_events	*events;
	Uint32			id;
	Uint32			params;
}					t_ui_win;

# pragma endregion
# pragma region		t_ui_raycaster

typedef struct		s_ui_raycaster
{
	t_ui_win		*focused_win;
	t_ui_el			*selected;
}					t_ui_raycaster;

int					ui_el_is_pointer_inside(void *a1, void *a2);

# pragma endregion
# pragma region		t_ui_main

typedef struct		s_ui_main
{
	t_list			*windows;
	SDL_Event		*sdl_event;
	SDL_mutex		*mutex;
	t_ui_raycaster	*raycaster;
	t_list			*sdl_surfaces;
	t_list			*sdl_fonts;
	t_list			*functions;
	t_list			*modal_win_els;
	t_ui_el			*focused_el;
	unsigned int	cur_keycode;
	void			*data;
	Uint32			params;
	t_vec2			ptr_pos;
}					t_ui_main;

typedef struct		s_scroll_m_pref
{
	int				type_pos;
	t_fvec2			begin_pos;
	int				type_size;
	t_fvec2			size;
	int				type_indent;
	t_fvec2			indent;
	int				params;
	int				begin_id;
	SDL_Renderer	*sdl_renderer;
	char			*texture;
}					t_scroll_m_pref;

typedef struct		s_resize_data
{
	t_fvec2			elem_pos;
	t_fvec2			elem_size;
	t_fvec2			indent;
}					t_resize_data;

typedef struct		s_font_params
{
	int				style;
	int				hinting;
	int				kerning;
	int				outline;
}					t_font_params;

typedef struct		s_text_params
{
	SDL_Color		text_color;
	SDL_Color		bg_color;
	int				max_text_size;
	int				params;
	int				render_param;
}					t_text_params;

t_ui_el				*ui_raycast(t_ui_main *m, t_ui_win *w);

t_ui_main			*ui_main_init(void);
void				ui_main_loop(t_ui_main *m);
int					ui_main_add_window(t_ui_main *m, t_ui_win *w);
void				ui_main_close_window(void *a1, void *a2);
void				ui_main_close_program(void *a1, void *a2);

int					ui_main_add_font_by_path(t_ui_main *m, const char *path, const char *font_id);
int					ui_main_add_surface_by_path(t_ui_main *m, const char *path, const char *sur_id);
TTF_Font			*ui_main_get_font_by_id(t_ui_main *m, const char *font_id);
SDL_Surface			*ui_main_get_surface_by_id(t_ui_main *m, const char *sur_id);

void				ui_main_fill_default_surfaces(t_ui_main *m);
void				ui_main_fill_default_fonts(t_ui_main *m);

t_ui_win			*ui_main_find_window_by_sdl_id(t_ui_main *m, Uint32 windowID);
t_ui_win			*ui_main_find_window_by_id(t_ui_main *m, Uint32 windowID);

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
void				ui_log_window_moved(void *a1, void *a2);

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
void				bfs_for_resize(const t_ui_el *root, const void *arg);

# pragma endregion

# pragma region draw

void				ui_draw(t_ui_main *m);
void				ui_draw_window(t_ui_win *w, t_ui_main *m);
void				ui_draw_windows(t_ui_main *m);
void				ui_clear_windows(t_ui_main *m);
void				ui_show_window(t_ui_win *w);
void				ui_show_windows(t_ui_main *m);

void				ui_el_draw_event(void *el_v, void *arg);

# pragma region		t_ui_el_func

t_ui_el				*ui_el_init(void);
int					ui_el_add_child(t_ui_el *el, t_ui_el *child);
void				ui_el_set_pos(t_ui_el *el, int type, t_fvec2 v);
void				ui_el_set_size(t_ui_el *el, int type, t_fvec2 v);
void				ui_el_change_pos(t_ui_el *el, t_ui_el *canvas, int type, t_fvec2 v);
void				ui_el_set_new_pos(t_ui_el *el, t_ui_el *canvas, int type, t_fvec2 v);
void				ui_el_set_new_size(t_ui_el *el, t_ui_el *canvas, int type, t_fvec2 v);
void				ui_el_set_new_pos(t_ui_el *el, t_ui_el *canvas, int type, t_fvec2 v);
void				ui_el_set_new_pos_for_children(void *a1, void *a2);
void				ui_el_set_new_size_for_children(void *a1, void *a2);

void				ui_el_show_child(void *a1, void *a2);

int					ui_el_load_surface_from(t_ui_el *el, const char *path);

SDL_Texture			*ui_el_create_texture(t_ui_el *el);
SDL_Texture			*ui_el_create_texture_from_surface(t_ui_el *el, SDL_Surface *sur);

int					ui_el_add_texture_from_file(t_ui_el *el,
						const char *path, const char *texture_id);
int					ui_el_add_empty_texture(t_ui_el *el, int w, int h,
						const char *texture_id);
int					ui_el_add_white_texture(t_ui_el *el, int w, int h,
						const char *texture_id);
int					ui_el_add_gradient_texture(t_ui_el *el, t_vec2 wh, int color,
						const char *texture_id);
int					ui_el_add_color_texture(t_ui_el *el, t_vec2 wh, int color,
						const char *texture_id);
SDL_Texture			*ui_el_get_current_texture(t_ui_el *el);
SDL_Texture			*ui_el_get_texture_by_id(t_ui_el *el, const char *id);
int					ui_el_set_current_texture_by_id(t_ui_el *el, const char *texture_id);

void				ui_el_default_pointer_enter(void *a1, void *a2);
void				ui_el_default_pointer_exit(void *a1, void *a2);

void				ui_el_scroll_menu_up(void *a1, void *a2);
void				ui_el_scroll_menu_down(void *a1, void *a2);
void				ui_el_scroll_child_menu_up(void *a1, void *a2);
void				ui_el_scroll_child_menu_down(void *a1, void *a2);

void				ui_el_drag(void *a1, void *a2);
void				ui_el_hor_slider_drug(void *a1, void *a2);

void				ui_el_set_default_texture(void *a1, void *a2);
void				ui_el_set_focused_texture(void *a1, void *a2);
void				ui_el_set_active_texture(void *a1, void *a2);

void				ui_el_resize_elems(void *a1, void *a2);
void				ui_el_default_resize(void *a1, void *a2);
void				ui_el_menu_resize(void *a1, void *a2);
void				ui_win_update_size(void *a1, void *a2);
void				ui_el_create_modal_window(void *a1, void *a2);

int					ui_el_add_texture_from_main_by_id(t_ui_main *m, t_ui_el *el,
		const char *id, const char *texture_id);

int					ui_main_set_font_params(t_ui_main *m, const char *font_id, t_font_params params);
int					ui_el_set_text(t_ui_main *m, t_ui_el *el, const char *font_id, t_text_params params);
int					ui_el_set_text_for_modal_window(t_ui_main *m, t_ui_el *el,
		const char *font_id, t_text_params params);
int					ui_el_update_text(t_ui_el *el, const char *text);

# pragma endregion

void				ui_win_create(t_ui_win *w);
void				ui_win_setup_default(t_ui_win *w);
void				ui_win_change_text_in_focused_el(void *a1, void *a2);
t_ui_win			*ui_win_init(void);
void				ui_win_close(t_ui_win *w);
t_ui_el				*ui_win_find_el_by_id(t_ui_win *w, Uint32 id);

int					ui_sdl_init(void);
void				ui_sdl_deinit(int exit_status);

# pragma GCC diagnostic pop

void				ui_prefab_scroll_menu(t_ui_main *m, t_ui_el *canvas,
		t_ui_el *scroll_menu, t_scroll_m_pref *scroll_data);
void				ui_prefab_get_pixel_pos(t_ui_el *p, t_ui_el *canvas,
		int type, t_fvec2 *pos);
void				ui_prefab_get_pixel_size(t_ui_el *p, t_ui_el *canvas,
		int type, t_fvec2 *size);

t_rect				ui_get_rect_from_frect(t_frect frect);

int					ui_parse_path(char **res);
int					ui_find_last_slash(const char *str);
int					ui_open_file_dialog(char **res);
int					ui_save_file_dialog(char **res);

int					ui_el_add_texture_from_file_dialog(t_ui_el *el);
int					ui_el_add_texture_from_file_dialog_with_size(t_ui_el *el, int w, int h);

int					ui_main_from_json(t_ui_main *m, const char *p);
int					ui_win_from_json(t_ui_main *m, t_jnode *n);
int					ui_el_from_json(t_ui_main *m, t_ui_win *w, t_jnode *n);
t_ui_event			*ui_el_from_json_get_event_by_name(t_ui_el *e, const char *n);

void				ui_el_setup_default_draggable(t_ui_el *el);
void				ui_el_setup_default_resizable(t_ui_el *el);
void				ui_el_setup_default_scroll_menu_elem(t_ui_el *el);
void				ui_el_setup_default_scroll_menu(t_ui_el *el);
void				ui_el_setup_default(t_ui_el *el);
void				ui_el_setup_horizontal_draggable(t_ui_el *el);
void				ui_el_setup_menu_resizable(t_ui_el *el);

void				ui_win_focus_lost(void *a1, void *a2);
void				ui_win_focus_gained(void *a1, void *a2);

int					ui_main_add_function_by_id(t_ui_main *m, func_ptr f, const char *func_id);
func_ptr			ui_main_get_function_by_id(t_ui_main *m, const char *func_id);

t_ui_event			*ui_win_from_json_get_event_by_name(t_ui_win *w, const char *n);
int					ui_get_el_param_from_string(const char *str);
int					ui_get_pos_size(const char *str);
int					ui_el_setup_by_type(t_ui_el *e, t_jnode *n);
int					ui_get_win_param_from_string(const char *str);
int					ui_el_pref_text(t_ui_main *m, t_ui_el *e, t_jnode *n);
int					ui_el_pref_modal_win(t_ui_main *m, t_ui_el *e, t_jnode *n);

int					ui_sdl_log_error(const char *p, const int id);

Uint32				ui_get_pixel_color_from_texture(SDL_Renderer *renderer,
		SDL_Texture *texture, t_vec2 coord);
Uint32				ui_get_pixel_color_from_el(SDL_Renderer *renderer,
		t_ui_el *el, t_vec2 coord);
void				ui_set_pixel_color_to_texture_replace(SDL_Renderer *renderer,
		SDL_Texture *texture, t_vec2 coord, SDL_Color color);
void				ui_el_children_set_default(void *a1, void *a2);

SDL_Texture			*ui_main_merge_layers(SDL_Renderer *r, t_list *l);
void				ui_main_save_texture(SDL_Renderer *r, SDL_Texture *t, const char *path, int type);
void				ui_main_open_texture(SDL_Renderer *r, t_ui_el *e, const char *path);

void	ui_el_destroy(t_ui_el *e);
void	ui_el_destroy_children(t_list *c);
void	ui_win_destroy(t_ui_win *w);
void	ui_win_events_destroy(t_ui_win_events *we);
void	ui_event_destroy(t_ui_event *e);
void	ui_el_events_destroy(t_ui_el_events *ee);
void	ui_text_destroy(t_ui_text *t);
void	ui_modal_win_destroy(t_ui_modal_win *mw);

#endif
