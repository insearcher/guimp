/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_save_file_dialog.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 22:21:06 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/09 23:03:24 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_save_file_dialog(char **res)
{
	int		fd;
	int		len;
	char	buf[BUF_SIZE + 1];

	if (system("touch buf; osascript -e 'set theNewFilePath to choose file name with prompt \"SAVE IMAGE AS:\"' >> buf") < 0 ||
		(fd = open("buf", O_RDONLY)) < 0)
		return (FUNCTION_FAILURE);
	if ((len = read(fd, &buf, BUF_SIZE)) <= 0 ||
		!(*res = ft_strnew(len)))
	{
		close(fd);
		return (FUNCTION_FAILURE);
	}
	if (system("rm buf") < 0)
	{
		free(*res);
		*res = NULL;
		return (FUNCTION_FAILURE);
	}
	while (--len >= 0)
		res[0][len] = buf[len];
	close(fd);
	return (ui_parse_path(res));
}
