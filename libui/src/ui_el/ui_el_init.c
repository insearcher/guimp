/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:41:42 by edraugr-          #+#    #+#             */
/*   Updated: 2019/04/04 00:06:53 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

// static inline void	init_events(t_ui_el	*el)
// {
// 	el->events.onPointerEnter.events = NULL;
// 	el->events.onPointerStay.events = NULL;
// 	el->events.onPointerExit.events = NULL;
// 	el->events.onPointerLeftButtonPressed.events = NULL;
// 	el->events.onPointerLeftButtonHold.events = NULL;
// 	el->events.onPointerLeftButtonReleased.events = NULL;
// 	el->events.onPointerRightButtonPressed.events = NULL;
// 	el->events.onPointerRightButtonHold.events = NULL;
// 	el->events.onPointerRightButtonReleased.events = NULL;
// 	el->events.onScrollUp.events = NULL;
// 	el->events.onScrollDown.events = NULL;
// }

// t_ui_el				*ui_el_init(t_ui_el *paren, t_list *children)
// {
// 	t_ui_el	*res;

// 	if (!(res = (t_ui_el *)malloc(sizeof(t_ui_el))))
// 		return (NULL);
// 	res->parent = parent;
// 	res->children = children;
// 	res->size->abs->x = 0;
// 	res->size->abs->y = 0;
// 	res->size->rel->x = 0.0;
// 	res->size->rel->y = 0.0;
// 	res->pos->abs->x = 0;
// 	res->pos->abs->y = 0;
// 	res->pos->rel->x = 0.0;
// 	res->pos->rel->y = 0.0;
// 	init_events(res);
// 	return (res);
// }

void	ui_el_init(t_ui_el *el)
{
	ft_bzero(&el, sizeof(t_ui_el));
	// el->parent = NULL;
	// el->children = NULL;
}
