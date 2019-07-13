/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:54:04 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/13 07:09:44 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	choose_fill_mode(t_ui_main *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(main->data);
	(void)el_v;
	g->draw_tool.tool_mode = GM_TOOL_MODE_FILL;
}

void	choose_empty_mode(t_ui_main *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(main->data);
	(void)el_v;
	g->draw_tool.tool_mode = GM_TOOL_MODE_EMPTY;
}

void	switch_fill_mode(t_ui_main *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(main->data);
	g->draw_tool.tool_mode = (g->draw_tool.tool_mode + 1) % 2;
}