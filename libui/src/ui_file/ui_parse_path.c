/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_parse_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 22:55:49 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/09 23:05:22 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_parse_path(char **res)
{
	int		len;
	int		i;
	int		ti;
	char	*sec;

	if (!*res)
		return (FUNCTION_FAILURE);
	len = ft_strlen(*res) - 5;
	if (!(sec = ft_strnew(len)))
		return (FUNCTION_FAILURE);
	i = (ft_strchr(*res, ' ') - *res) / sizeof(char);
	sec[0] = '/';
	ti = i;
	while (res[0][++i])
		sec[i - ti] = res[0][i] == ':' ? '/' : res[0][i];
	free(*res);
	*res = sec;
	return (FUNCTION_SUCCESS);
}
