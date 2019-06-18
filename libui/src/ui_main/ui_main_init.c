/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:20:31 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/18 21:25:13 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_ui_main	*ui_main_init(void)
{
	t_ui_main	*m;

	if (!(m = (t_ui_main *)malloc(sizeof(t_ui_main))))
		return (NULL);
	ft_bzero(m, sizeof(t_ui_main));
	return (m);
}
