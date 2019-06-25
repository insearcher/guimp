/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 19:04:10 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/22 20:50:19 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIMP_H
# define GUIMP_H

# include "libft.h"
# include "libui.h"

# define TID_DRAW_TEXTURE		"draw_texture"

# define GM_MAIN_WIN_X			800
# define GM_MAIN_WIN_Y			SDL_WINDOWPOS_CENTERED //SDL!!!
# define GM_MAIN_WIN_W			1200
# define GM_MAIN_WIN_H			800
# define GM_MAIN_ID_DRAW		1

# define GM_TOOL_WIN_W			300
# define GM_TOOL_WIN_H			800
# define GM_TOOL_WIN_X			GM_MAIN_WIN_X - GM_TOOL_WIN_W - 5
# define GM_TOOL_WIN_Y			SDL_WINDOWPOS_CENTERED //SDL!!!
# define GM_TOOL_ID_BUT_MENU	11
# define GM_TOOL_ID_BRUSH		12
# define GM_TOOL_ID_ERASER		13
# define GM_TOOL_ID_ZOOM		14
# define GM_TOOL_ID_HAND		15
# define GM_TOOL_ID_LINE		16
# define GM_TOOL_ID_PIPETTE		17
# define GM_TOOL_ID_SET_MENU	20
# define GM_TOOL_ID_SL_ROOT_RED	21
# define GM_TOOL_ID_SL_HEAD_RED	22
# define GM_TOOL_ID_SL_ROOT_GR	23
# define GM_TOOL_ID_SL_HEAD_GR	24
# define GM_TOOL_ID_SL_ROOT_BL	25
# define GM_TOOL_ID_SL_HEAD_BL	26
# define GM_TOOL_ID_SL_ROOT_SZ	27
# define GM_TOOL_ID_SL_HEAD_SZ	28
# define GM_TOOL_ID_CL_RECT		29


# define GM_LAYER_WIN_W			300
# define GM_LAYER_WIN_H			800
# define GM_LAYER_ID_MENU		2
# define GM_LAYER_ID_ADD		3
# define GM_LAYER_ID_DEL		4
# define GM_LAYER_ID_DEF_LAYER	ID_GENERATOR_START
# define GM_LAYER_MAX_COUNT		100

# define GM_IMAGE_SIZE_X		1920
# define GM_IMAGE_SIZE_Y		1080

# define GM_BRUSH_MAX_SIZE		300
# define GM_BRUSH_DEF_SIZE		10
# define GM_ZOOM_MAX_SIZE		32
# define GM_ZOOM_MOVE_ZONE		0.3
# define GM_ZOOM_MOVE_SPEED		64
# define GM_HAND_MOVE_SPEED		1
# define GM_HAND_MIN_DIST		3

# define GM_TOOL_BRUSH			0
# define GM_TOOL_ZOOM			1
# define GM_TOOL_ERASER			2
# define GM_TOOL_HAND			3
# define GM_TOOL_LINE			4
# define GM_TOOL_PIPETTE		5

# define GM_TOOL_STATE_NONE		0
# define GM_TOOL_STATE_START	1
# define GM_TOOL_STATE_DRAW		2
# define GM_TOOL_STATE_END		3

//id_generator flags
# define ID_GENERATOR_GET		0
# define ID_GENERATOR_ADD		1
# define ID_GENERATOR_DEL		2
# define ID_GENERATOR_START		63

/* t_layers - struct for elems in layer win */
typedef struct					s_layers
{
	t_ui_el						*current_layer;
	t_list						*layers;
	t_texture					*tmp_texture;
}								t_layers;

typedef struct					s_draw_tool
{
	t_vec2						prew_point;
	t_vec2						cur_point;
	int							tool;
	int							brush_size;
	Uint8						r;
	Uint8						g;
	Uint8						b;
	int							zoom;
	int							state;
}								t_draw_tool;


typedef struct					s_guimp
{
	t_ui_main					*ui_main;
	t_ui_win					*main_win;
	t_ui_win					*tool_win;
	t_layers					layers;
	t_draw_tool					draw_tool;
	t_rect						zoom_rect;
}								t_guimp;

void							draw_dot(void *ui_main, void *ui_el);
void							draw_main_canvas_event(void *el_v, void *arg);

void							gm_init(t_guimp *g_main);
int								gm_generate_surf_id(int generate_flag);
int								gm_generator_get_surf_count(void);
int								gm_generator_get_surf_id_by_num(int surf_serial_num);

void							ui_main_fill_default_functions(t_ui_main *m);

void move_windows(void *a1, void *a2);
void	start_zoom_in(void *m, void *wid);
void	start_zoom_out(void *m, void *wid);

#endif
