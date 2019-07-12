/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_event_scroll_menu.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 04:41:24 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/12 10:49:46 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_event_scroll_child_menu_down(t_ui_main *m, void *a)
{
	t_ui_el		*el;

	el = (t_ui_el*)a;
	ui_event_invoke(el->parent->events->onScrollDown, m, el->parent);
}

void	ui_el_event_scroll_child_menu_up(t_ui_main *m, void *a)
{
	t_ui_el		*el;

	el = (t_ui_el*)a;
	ui_event_invoke(el->parent->events->onScrollUp, m, el->parent);
}

void	ui_el_event_scroll_menu_down(t_ui_main *m, void *a)
{
	t_ui_el		*el_menu;
	t_ui_el		*higher_el;
	t_ui_el		*cur_el;
	t_list		*list;
	int			tmp_scroll_speed;

	(void)m;
	el_menu = (t_ui_el *)a;
	if (el_menu->children == 0)
		return ;
	higher_el = (t_ui_el *)el_menu->children->content;
	if (higher_el->rect.y >= el_menu->rect.y)
		return ;
	tmp_scroll_speed = SCROLL_SPEED;
	if (higher_el->rect.y + SCROLL_SPEED > el_menu->rect.y)
		tmp_scroll_speed = el_menu->rect.y - higher_el->rect.y;
	list = el_menu->children;
	while (list)
	{
		cur_el = (t_ui_el*)list->content;
		ui_el_change_pos(cur_el, 0, PIXEL, (t_fvec2){0, tmp_scroll_speed});
		list = list->next;
	}
}

void	ui_el_event_scroll_menu_up(t_ui_main *m, void *a)
{
	t_ui_el		*el_menu;
	t_ui_el		*lower_el;
	t_ui_el		*cur_el;
	t_list		*list;
	int			tmp_scroll_speed;

	(void)m;
	el_menu = (t_ui_el*)a;
	if (el_menu->children == 0)
		return ;
	list = el_menu->children;
	while (list->next)
		list = list->next;
	lower_el = (t_ui_el*)list->content;
	if (lower_el->rect.y + lower_el->rect.h <= el_menu->rect.y + el_menu->rect.h)
		return ;
	tmp_scroll_speed = SCROLL_SPEED;
	if (lower_el->rect.y + lower_el->rect.h - SCROLL_SPEED < el_menu->rect.y + el_menu->rect.h)
		tmp_scroll_speed = lower_el->rect.y + lower_el->rect.h - el_menu->rect.y - el_menu->rect.h;
	list = el_menu->children;
	while (list)
	{
		cur_el = (t_ui_el*)list->content;
		ui_el_change_pos(cur_el, 0, PIXEL, (t_fvec2){0, -tmp_scroll_speed});
		list = list->next;
	}
}
