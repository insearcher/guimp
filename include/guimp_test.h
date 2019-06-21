/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:09:46 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/21 17:41:33 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIMP_TEST_H
# define GUIMP_TEST_H

# include "libft.h"
# include "libui.h"

# define TID_DRAW_TEXTURE	3

typedef struct  s_guimp
{
	t_ui_main   *m;
	t_ui_win    *w;
	t_ui_el     *scroll_menu1;
	t_ui_el     *scroll_menu1_el1;
	t_ui_el     *scroll_menu1_el2;
	t_ui_el     *scroll_menu1_el3;
	t_ui_el     *scroll_menu1_el4;
	t_ui_el     *scroll_menu1_el5;
	t_ui_el     *scroll_menu1_el6;
	t_ui_el     *scroll_menu1_el7;
	t_ui_el     *scroll_menu1_el8;
	t_ui_el     *scroll_menu1_el9;
	t_ui_el     *flex_menu1;
	t_ui_el     *flex_menu1_el1;
	t_ui_el     *flex_menu1_el2;
	t_ui_el     *flex_menu1_el3;
	t_ui_el     *flex_menu1_el4;
	t_ui_el     *flex_menu1_el5;
	t_ui_el     *popap_menu1;
	t_ui_el     *popap_menu1_el_main;
	t_ui_el     *popap_menu1_el1;
	t_ui_el     *popap_menu1_el2;
	t_ui_el     *popap_menu1_el3;
	t_ui_el     *popap_menu1_el4;
	t_ui_el     *popap_menu1_el5;
	t_ui_el     *popap_menu1_el6;
	t_ui_el     *popap_menu1_el7;
	t_ui_el		*el1;
	t_ui_el		*el_text;
}               t_guimp;

void							el_text(t_guimp *guimp);
void                            draw_dot(void *ui_main, void *ui_el);
void                            draw_main_canvas_event(void *el_v, void *arg);
void							initialization_w1(t_guimp *guimp);
void							scroll_menu1(t_guimp *guimp);
void							el1(t_guimp *guimp);

#endif
