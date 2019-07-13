/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_event_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:13:44 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/12 07:35:22 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_ui_event	*ui_event_init(void)
{
	t_ui_event	*e;

	if (!(e = (t_ui_event *)malloc(sizeof(t_ui_event))))
		ui_sdl_deinit(228);
	ft_bzero(e, sizeof(t_ui_event));
	return (e);
}

t_ui_el_events	*ui_event_el_events_init(void)
{
	t_ui_el_events *e;

	if (!(e = (t_ui_el_events *)malloc(sizeof(t_ui_el_events))))
		ui_sdl_deinit(228);
	ft_bzero(e, sizeof(t_ui_el_events));
	if (!(e->onPointerEnter = ui_event_init()) ||
		!(e->onPointerStay = ui_event_init()) ||
		!(e->onPointerExit = ui_event_init()) ||
		!(e->onPointerLeftButtonPressed = ui_event_init()) ||
		!(e->onPointerLeftButtonHold = ui_event_init()) ||
		!(e->onPointerLeftButtonReleased = ui_event_init()) ||
		!(e->onPointerRightButtonPressed = ui_event_init()) ||
		!(e->onPointerRightButtonHold = ui_event_init()) ||
		!(e->onPointerRightButtonReleased = ui_event_init()) ||
		!(e->onScrollUp = ui_event_init()) ||
		!(e->onScrollDown = ui_event_init()) ||
		!(e->onRender = ui_event_init()) ||
		!(e->onResize = ui_event_init()))
		ui_sdl_deinit(228);
	return (e);
}

t_ui_win_events	*ui_event_win_events_init(void)
{
	t_ui_win_events	*w;
	int				i;

	if (!(w = (t_ui_win_events *)malloc(sizeof(t_ui_win_events))))
		ui_sdl_deinit(228);
	ft_bzero(w, sizeof(t_ui_win_events));
	if (!(w->onPointerMoved = ui_event_init()) ||
		!(w->onPointerEnter = ui_event_init()) ||
		!(w->onPointerExit = ui_event_init()) ||
		!(w->onPointerLeftButtonPressed = ui_event_init()) ||
		!(w->onPointerLeftButtonReleased = ui_event_init()) ||
		!(w->onPointerRightButtonPressed = ui_event_init()) ||
		!(w->onPointerRightButtonReleased = ui_event_init()) ||
		!(w->onScrollUp = ui_event_init()) ||
		!(w->onScrollDown = ui_event_init()) ||
		!(w->onFocusGained = ui_event_init()) ||
		!(w->onFocusLost = ui_event_init()) ||
		!(w->onResize = ui_event_init()) ||
		!(w->onClose = ui_event_init()) ||
		!(w->onMoved = ui_event_init()))
		ui_sdl_deinit(228);
	i = KEYS_COUNT;
	if (!(w->onKeyUp = (t_ui_event **)malloc(KEYS_COUNT * sizeof(t_ui_event *))) ||
		!(w->onKeyDown = (t_ui_event **)malloc(KEYS_COUNT * sizeof(t_ui_event *))))
		ui_sdl_deinit(228);
	while (--i >= 0)
	{
		if (!(w->onKeyDown[i] = ui_event_init()) ||
			!(w->onKeyUp[i] = ui_event_init()))
			ui_sdl_deinit(228);
	}
	return (w);
}
