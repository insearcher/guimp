/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 19:04:10 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/23 14:58:26 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIMP_H
# define GUIMP_H

# include "libft.h"
# include "libui.h"

# define TID_DRAW_TEXTURE		3

# define GM_MAIN_WIN_W			1200
# define GM_MAIN_WIN_H			800
# define MAIN_WIN_DRAW_EL_ID	1

# define GM_TOOL_WIN_W			300
# define GM_TOOL_WIN_H			800

# define GM_LAYER_WIN_W			300
# define GM_LAYER_WIN_H			800

//id_generator flags
# define ID_GENERATOR_GET		0
# define ID_GENERATOR_ADD		1
# define ID_GENERATOR_DEL		1
# define ID_GENERATOR_START		63

typedef struct					s_guimp
{
	t_ui_main					*ui_main;
	t_ui_win					*main_win;
	t_ui_win					*tool_win;
	t_ui_win					*layer_win;
}								t_guimp;

/* t_layers - struct for elems in layer win */
typedef struct					s_layers
{
	t_ui_el						*current_layer; //el with current layer
	t_list						*layers; //

}								t_layers;


void							draw_dot(void *ui_main, void *ui_el);
void							draw_main_canvas_event(void *el_v, void *arg);

void							gm_init(t_guimp *g_main);
int								gm_generate_surf_id(int generate_flag);
int								gm_generator_get_surf_count(void);
int								gm_generator_get_surf_id_by_num(int surf_serial_num);

#endif
