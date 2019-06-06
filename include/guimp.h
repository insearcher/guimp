/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 19:04:10 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/06 04:09:28 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIMP_H
# define GUIMP_H

# include "libft.h"
# include "libui.h"

# define TID_DRAW_TEXTURE		"draw_texture"

# define GM_MAIN_WIN_X			800
# define GM_MAIN_WIN_Y			SDL_WINDOWPOS_CENTERED
# define GM_MAIN_WIN_W			1200
# define GM_MAIN_WIN_H			800
# define GM_MAIN_ID_DRAW		1

# define GM_TOOL_WIN_W			300
# define GM_TOOL_WIN_H			800
# define GM_TOOL_WIN_X			GM_MAIN_WIN_X - GM_TOOL_WIN_W - 5
# define GM_TOOL_WIN_Y			SDL_WINDOWPOS_CENTERED
# define GM_TOOL_ID_BUT_MENU	11
# define GM_TOOL_ID_BRUSH		12
# define GM_TOOL_ID_ERASER		13
# define GM_TOOL_ID_SET_MENU	40
# define GM_TOOL_ID_SL_ROOT_RED	41
# define GM_TOOL_ID_SL_HEAD_RED	42
# define GM_TOOL_ID_SL_ROOT_GR	43
# define GM_TOOL_ID_SL_HEAD_GR	44
# define GM_TOOL_ID_SL_ROOT_BL	45
# define GM_TOOL_ID_SL_HEAD_BL	46
# define GM_TOOL_ID_SL_ROOT_SZ	47
# define GM_TOOL_ID_SL_HEAD_SZ	48


# define GM_LAYER_WIN_W			300
# define GM_LAYER_WIN_H			800
# define GM_LAYER_ID_MENU		2
# define GM_LAYER_ID_ADD		3
# define GM_LAYER_ID_DEL		4
# define GM_LAYER_ID_DEF_LAYER	ID_GENERATOR_START
# define GM_LAYER_MAX_COUNT		100

# define GM_IMAGE_SIZE_X		1920
# define GM_IMAGE_SIZE_Y		1080

# define GM_BRUSH_MAX_SIZE		100
# define GM_BRUSH_DEF_SIZE		10

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
}								t_draw_tool;


typedef struct					s_guimp
{
	t_ui_main					*ui_main;
	t_ui_win					*main_win;
	t_ui_win					*tool_win;
	t_layers					layers;
	t_draw_tool					draw_tool;
}								t_guimp;

void							draw_dot(void *ui_main, void *ui_el);
void							draw_main_canvas_event(void *el_v, void *arg);

void							gm_init(t_guimp *g_main);
int								gm_generate_surf_id(int generate_flag);
int								gm_generator_get_surf_count(void);
int								gm_generator_get_surf_id_by_num(int surf_serial_num);

#endif
