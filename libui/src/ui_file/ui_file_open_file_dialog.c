/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_file_open_file_dialog.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 08:57:57 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/12 08:58:03 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int			ui_file_open_file_dialog(char **res)
{
	int		fd;
	int		len;
	char	buf[BUF_SIZE + 1];

	fd = 0;
	if (system("touch buf; osascript -e 'set theImage to choose file with prompt \"OPEN IMAGE:\" of type {\"public.image\"}' >> buf") < 0 ||
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
	return (ui_parse_path(res));
}
