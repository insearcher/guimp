/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_event_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:13:44 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/29 19:37:19 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_event_init(t_ui_event *e)
{
	ft_bzero(e, sizeof(t_ui_event));
	e->events = NULL;
	e->last = NULL;
}
