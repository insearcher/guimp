/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_file_parse_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 08:56:32 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/12 08:56:38 by sbecker          ###   ########.fr       */
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

int	ui_file_parse_path(char **res)
{
	int		len;
	int		i;
	int		ti;
	char	*sec;

	if (!*res)
		ui_sdl_deinit(228);
	len = ft_strlen(*res) - 5;
	if (!(sec = ft_strnew(len)))
		ui_sdl_deinit(228);
	i = (ft_strchr(*res, ' ') - *res) / sizeof(char);
	ti = i;
	while (res[0][++i])
		sec[i - ti] = res[0][i] == ':' ? '/' : res[0][i];
	sec[i - ti - 1] = '\0';
	free(*res);
	*res = sec;
	return (ui_parse_path2(res));
}
