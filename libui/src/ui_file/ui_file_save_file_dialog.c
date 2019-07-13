/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_file_save_file_dialog.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 08:58:32 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 06:15:07 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_file_save_file_dialog(char **res)
{
	int		fd;
	int		len;
	char	buf[BUF_SIZE + 1];

	fd = 0;
	if (system("touch buf; osascript -e 'set theNewFilePath to choose file name with prompt \"SAVE IMAGE AS:\"' >> buf") < 0 ||
		(fd = open("buf", O_RDONLY)) < 0)
		ui_sdl_deinit(228);
	if ((len = read(fd, &buf, BUF_SIZE)) <= 0 ||
		!(*res = ft_strnew(len)))
	{
		close(fd);
		ui_sdl_deinit(228);
	}
	if (system("rm buf") < 0)
	{
		free(*res);
		*res = NULL;
		ui_sdl_deinit(228);
	}
	while (--len >= 0)
		res[0][len] = buf[len];
	close(fd);
	return (ui_file_parse_path(res));
}
