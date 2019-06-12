/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_get_font_by_id.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:18:46 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/11 04:55:55 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

TTF_Font	*ui_main_get_font_by_id(t_ui_main *m, const char *font_id)
{
	TTF_Font	*res;
	t_list		*tmp;
	int			hash;

	res = NULL;
	tmp = m->sdl_fonts;
	hash = ft_strhash(font_id);
	while (tmp && !res)
	{
		if (tmp->content_size == (size_t)hash)
			res = (TTF_Font *)tmp->content;
		tmp = tmp->next;
	}
	return (res);
}
