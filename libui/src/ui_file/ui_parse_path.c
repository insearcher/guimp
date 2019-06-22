/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_parse_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 22:55:49 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/22 22:54:33 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void	helper(char **res, char *to)
{
	int	i;

	i = -1;
	while (to[++i])
		res[0][i] = to[i];
}

static int	ui_parse_path2(char **res)
{
	char	*tmp;

	helper(res, "Users/");
	tmp = ft_strjoin("/", *res);
	free(*res);
	*res = tmp;
	return (FUNCTION_SUCCESS);
}

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
	ti = i;
	while (res[0][++i])
		sec[i - ti] = res[0][i] == ':' ? '/' : res[0][i];
	sec[i - ti - 1] = '\0';
	free(*res);
	*res = sec;
	return (ui_parse_path2(res));
}
