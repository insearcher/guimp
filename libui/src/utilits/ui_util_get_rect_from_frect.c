/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_util_get_rect_from_frect.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 08:50:35 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/12 08:50:48 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_rect	ui_util_get_rect_from_frect(t_frect frect)
{
	t_rect	rect;

	rect.x = (int)roundf(frect.x);
	rect.y = (int)roundf(frect.y);
	rect.w = (int)roundf(frect.w);
	rect.h = (int)roundf(frect.h);
	return (rect);
}
