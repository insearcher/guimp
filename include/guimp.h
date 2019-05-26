/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 19:04:10 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/26 06:55:29 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIMP_H
# define GUIMP_H

# include "libft.h"
# include "libui.h"

# define TID_DRAW_TEXTURE		3

typedef struct	s_scroll_prefab
{
	t_rect			rect;
	int				indent;
	int				params;
	int				id;
	SDL_Renderer	*sdl_renderer;
	char			*texture_path;
}				t_scroll_prefab;

typedef struct  s_guimp
{
	t_ui_main   m;
	t_ui_win    w1;
	t_ui_win    w2;
	t_ui_win    w3;
	t_ui_el     scroll_menu1;
	t_ui_el     scroll_menu1_el1;
	t_ui_el     scroll_menu1_el2;
	t_ui_el     scroll_menu1_el3;
	t_ui_el     scroll_menu1_el4;
	t_ui_el     scroll_menu1_el5;
	t_ui_el     scroll_menu1_el6;
	t_ui_el     scroll_menu1_el7;
	t_ui_el     scroll_menu1_el8;
	t_ui_el     flex_menu1;
	t_ui_el     flex_menu1_el1;
	t_ui_el     flex_menu1_el2;
	t_ui_el     flex_menu1_el3;
	t_ui_el     flex_menu1_el4;
	t_ui_el     flex_menu1_el5;
	t_ui_el     popap_menu1;
	t_ui_el     popap_menu1_el_main;
	t_ui_el     popap_menu1_el1;
	t_ui_el     popap_menu1_el2;
	t_ui_el     popap_menu1_el3;
	t_ui_el     popap_menu1_el4;
	t_ui_el     popap_menu1_el5;
	t_ui_el     popap_menu1_el6;
	t_ui_el     popap_menu1_el7;
}               t_guimp;

void							draw_dot(void *ui_main, void *ui_el);
void							draw_main_canvas_event(void *el_v, void *arg);

#endif
