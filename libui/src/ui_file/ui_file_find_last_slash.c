/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_file_find_last_slash.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 08:57:08 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/12 08:57:15 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_file_find_last_slash(const char *str)
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
