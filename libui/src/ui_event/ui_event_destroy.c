/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_event_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:27:39 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/12 07:32:06 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_event_destroy(t_ui_event *e)
{
	t_list	*p;
	t_list	*l;

	l = e->events;
	p = l;
	while (l)
	{
		free(l->content);
		l = l->next;
		p->next = NULL;
		free(p);
		p = l;
	}
	free(e);
}

void	ui_event_win_events_destroy(t_ui_win_events *we)
{
	int i;

	ui_event_destroy(we->onPointerMoved);
	ui_event_destroy(we->onPointerEnter);
	ui_event_destroy(we->onPointerExit);
	ui_event_destroy(we->onPointerLeftButtonPressed);
	ui_event_destroy(we->onPointerLeftButtonReleased);
	ui_event_destroy(we->onPointerRightButtonPressed);
	ui_event_destroy(we->onPointerRightButtonReleased);
	ui_event_destroy(we->onScrollUp);
	ui_event_destroy(we->onScrollDown);
	ui_event_destroy(we->onFocusGained);
	ui_event_destroy(we->onFocusLost);
	ui_event_destroy(we->onResize);
	ui_event_destroy(we->onClose);
	ui_event_destroy(we->onMoved);
	i = KEYS_COUNT;
	while (--i >= 0)
	{
		ui_event_destroy(we->onKeyDown[i]);
		ui_event_destroy(we->onKeyUp[i]);
	}
	free(we->onKeyDown);
	free(we->onKeyUp);
	free(we);
}

void	ui_event_el_events_destroy(t_ui_el_events *ee)
{
	ui_event_destroy(ee->onPointerEnter);
	ui_event_destroy(ee->onPointerStay);
	ui_event_destroy(ee->onPointerExit);
	ui_event_destroy(ee->onPointerLeftButtonPressed);
	ui_event_destroy(ee->onPointerLeftButtonHold);
	ui_event_destroy(ee->onPointerLeftButtonReleased);
	ui_event_destroy(ee->onPointerRightButtonPressed);
	ui_event_destroy(ee->onPointerRightButtonHold);
	ui_event_destroy(ee->onPointerRightButtonReleased);
	ui_event_destroy(ee->onScrollUp);
	ui_event_destroy(ee->onScrollDown);
	ui_event_destroy(ee->onRender);
	ui_event_destroy(ee->onResize);
	free(ee);
}
