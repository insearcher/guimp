/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_find_last_slash.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 23:06:42 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/09 23:08:38 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_find_last_slash(const char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = ft_strlen(str);
	while (--i >= 0)
		if (str[i] == '/')
			return (i);
	return (i);
}
