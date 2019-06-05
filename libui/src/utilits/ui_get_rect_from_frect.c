/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_get_rect_from_frect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 19:47:56 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/04 23:33:26 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_rect	ui_get_rect_from_frect(t_frect frect)
{
	t_rect	rect;

	rect.x = (int)roundf(frect.x);
	rect.y = (int)roundf(frect.y);
	rect.w = (int)roundf(frect.w);
	rect.h = (int)roundf(frect.h);
	return (rect);
}
