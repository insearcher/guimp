/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_from_slider.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:07:36 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/10 16:07:36 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

int	get_value_from_slider(t_ui_el *s, t_ui_el *c)
{
	int	res;
	int	max;

	max = (c->id == GM_TOOL_ID_SL_HEAD_SZ) ? GM_BRUSH_MAX_SIZE : 255;
	res = s->ptr_rel_pos.x - c->rect.w / 2;
	ui_el_set_new_pos(c, 0, PIXEL, (t_fvec2){res, 0});
	res = ((float)(s->ptr_rel_pos.x) / (float)s->rect.w) * (float)max;
	return (res);
}