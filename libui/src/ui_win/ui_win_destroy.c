/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:07:15 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/13 06:02:46 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_win_destroy(t_ui_win *w)
{
	SDL_DestroyWindow(w->sdl_window);
	SDL_DestroyRenderer(w->sdl_renderer);
	free(w->title);
	ui_el_destroy(w->canvas);
	ui_event_win_events_destroy(w->events);
	w->events = NULL;
	free(w);
}
