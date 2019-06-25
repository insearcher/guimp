/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:09:46 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/22 16:42:50 by sbecker          ###   ########.fr       */
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
}               t_guimp;

void                            draw_dot(void *ui_main, void *ui_el);
void                            draw_main_canvas_event(void *el_v, void *arg);

#endif
