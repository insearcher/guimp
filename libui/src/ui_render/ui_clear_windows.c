/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_clear_windows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 06:42:16 by edraugr-          #+#    #+#             */
/*   Updated: 2019/04/25 19:58:39 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_clear_windows(t_ui_main *m)
{
	t_list	*tmp;

	tmp = m->windows;
	while (tmp)
	{
		SDL_RenderClear(CAST_X_TO_Y(tmp->content, t_ui_win *)->sdl_renderer);
		tmp = tmp->next;
	}
}
