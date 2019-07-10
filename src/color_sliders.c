/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_sliders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:05:33 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/10 16:05:33 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	choose_red_color(void *main, void *el_v)
{
	t_guimp	*g;
	t_ui_el	*el;
	t_ui_el	*chil;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	el = (t_ui_el *)el_v;
	chil = ((t_ui_el *)el->children->content);
	g->draw_tool.r = get_value_from_slider(el, chil);
	update_color_rect(g, g->draw_tool.r, g->draw_tool.g, g->draw_tool.b);
}

void	choose_green_color(void *main, void *el_v)
{
	t_guimp	*g;
	t_ui_el	*el;
	t_ui_el	*chil;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	el = (t_ui_el *)el_v;
	chil = ((t_ui_el *)el->children->content);
	g->draw_tool.g = get_value_from_slider(el, chil);
	update_color_rect(g, g->draw_tool.r, g->draw_tool.g, g->draw_tool.b);
}

void	choose_blue_color(void *main, void *el_v)
{
	t_guimp	*g;
	t_ui_el	*el;
	t_ui_el	*chil;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	el = (t_ui_el *)el_v;
	chil = ((t_ui_el *)el->children->content);
	g->draw_tool.b = get_value_from_slider(el, chil);
	update_color_rect(g, g->draw_tool.r, g->draw_tool.g, g->draw_tool.b);
}

void	choose_size(void *main, void *el_v)
{
	t_guimp	*g;
	t_ui_el	*el;
	t_ui_el	*chil;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	el = (t_ui_el *)el_v;
	chil = ((t_ui_el *)el->children->content);
	g->draw_tool.brush_size = get_value_from_slider(el, chil);
}

void	choose_alpha(void *main, void *el_v)
{
	t_guimp	*g;
	t_ui_el	*el;
	t_ui_el	*chil;
	int		res;
	int		max;

	g = (t_guimp *)(((t_ui_main *)main)->data);
	el = (t_ui_el *)el_v;
	chil = ((t_ui_el *)el->children->content);
	g->draw_tool.a = get_value_from_slider(el, chil);
}