/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:53:21 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/13 07:19:31 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	choose_square(t_ui_main *main, void *el_v)
{
	t_guimp	*g;

	g = (t_guimp *)(main->data);
	(void)el_v;
	g->draw_tool.tool = GM_TOOL_SQUARE;
	g->draw_tool.state = GM_TOOL_STATE_NONE;
}