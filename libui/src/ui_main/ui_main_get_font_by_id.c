/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_get_font_by_id.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:18:46 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/07 04:41:56 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

TTF_Font	*ui_main_get_font_by_id(t_ui_main *m, int font_id)
{
	TTF_Font	*res;
	t_list		*tmp;

	res = NULL;
	tmp = m->sdl_fonts;
	while (tmp && !res)
	{
		if (tmp->content_size == (size_t)font_id)
			res = (TTF_Font *)tmp->content;
		tmp = tmp->next;
	}
	return (res);
}
