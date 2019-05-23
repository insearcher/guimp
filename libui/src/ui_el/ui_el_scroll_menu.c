/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_scroll_menu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 01:38:28 by sbecker           #+#    #+#             */
/*   Updated: 2019/05/23 03:01:02 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_scroll_child_menu_down(void *a1, void *a2)
{
	t_ui_el		*el;

	el = (t_ui_el*)a2;
	ui_event_invoke(&(el->parent->events.onScrollDown), a1, el->parent);
}

void	ui_el_scroll_child_menu_up(void *a1, void *a2)
{
	t_ui_el		*el;

	el = (t_ui_el*)a2;
	ui_event_invoke(&(el->parent->events.onScrollUp), a1, el->parent);
}

void	ui_el_scroll_menu_down(void *a1, void *a2)
{
	t_ui_main	*main;
	t_ui_el		*el_menu;
	t_ui_el		*higher_el;
	t_ui_el		*cur_el;
	t_list		*list;

	main = (t_ui_main *)a1;
	el_menu = (t_ui_el *)a2;
	higher_el = (t_ui_el *)el_menu->children->content;
	if (higher_el->rect.y >= el_menu->rect.y)
		return ;
	list = el_menu->children;
	while (list)
	{
		cur_el = (t_ui_el*)list->content;
		ui_el_set_abs_pos(cur_el, cur_el->rect.x, cur_el->rect.y + SCROLL_SPEED);
		list = list->next;
	}
}

void	ui_el_scroll_menu_up(void *a1, void *a2)
{
	t_ui_main	*main;
	t_ui_el		*el_menu;
	t_ui_el		*lower_el;
	t_ui_el		*cur_el;
	t_list		*list;

	main = (t_ui_main*)a1;
	el_menu = (t_ui_el*)a2;
	list = el_menu->children;
	while (list->next)
		list = list->next;
	lower_el = (t_ui_el*)list->content;
	if (lower_el->rect.y + lower_el->rect.h <= el_menu->rect.y + el_menu->rect.h)
		return ;
	list = el_menu->children;
	while (list)
	{
		cur_el = (t_ui_el*)list->content;
		ui_el_set_abs_pos(cur_el, cur_el->rect.x, cur_el->rect.y - SCROLL_SPEED);
		list = list->next;
	}
}
