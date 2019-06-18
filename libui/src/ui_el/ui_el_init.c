/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:41:42 by edraugr-          #+#    #+#             */
/*   Updated: 2019/06/19 01:55:37 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_ui_el	*ui_el_init(void)
{
	t_ui_el	*el;

	if (!(el = (t_ui_el *)malloc(sizeof(t_ui_el))))
		return (NULL);
	ft_bzero(el, sizeof(t_ui_el));
	if (!(el->events = ui_el_events_init()))
		return (NULL);
	return (el);
}
