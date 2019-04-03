/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 23:38:46 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/29 20:57:00 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_loop(void *ev)
{
	t_env	*e;

	e = (t_env *)ev;
	ui_create_frame(e);
	while (1)
	{
		if (ui_get_events(e))
			ui_create_frame(e);
	}
	return (FUNCTION_SUCCESS);
}
