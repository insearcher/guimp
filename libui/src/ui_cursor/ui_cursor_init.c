/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_cursor_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 19:56:50 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/22 19:58:41 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_cursor	*ui_cursor_init(void)
{
	t_cursor	*cur;

	if (!(cur = (t_cursor *)malloc(sizeof(t_cursor))))
		return (NULL);
	ft_bzero(cur, sizeof(t_cursor));
	return (cur);
}
