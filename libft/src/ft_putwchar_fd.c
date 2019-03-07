/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:11:26 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/29 19:14:04 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print2bytes(int wc, int fd)
{
	int	tmp;

	tmp = (wc >> 6) + 0xC0;
	write(fd, &tmp, 1);
	tmp = (wc & 0x3F) + 0x80;
	write(fd, &tmp, 1);
}

static void	ft_print3bytes(int wc, int fd)
{
	int	tmp;

	tmp = (wc >> 12) + 0xE0;
	write(fd, &tmp, 1);
	tmp = ((wc >> 6) & 0x3F) + 0x80;
	write(fd, &tmp, 1);
	tmp = (wc & 0x3F) + 0x80;
	write(fd, &tmp, 1);
}

static void	ft_print4bytes(int wc, int fd)
{
	int	tmp;

	tmp = (wc >> 18) + 0xF0;
	write(fd, &tmp, 1);
	tmp = ((wc >> 12) & 0x3F) + 0x80;
	write(fd, &tmp, 1);
	tmp = ((wc >> 6) & 0x3F) + 0x80;
	write(fd, &tmp, 1);
	tmp = (wc & 0x3F) + 0x80;
	write(fd, &tmp, 1);
}

void		ft_putwchar_fd(int wc, int fd)
{
	if (wc <= 0x7F)
		write(fd, &wc, 1);
	else if (wc <= 0x7FF)
		ft_print2bytes(wc, fd);
	else if (wc <= 0xFFFF)
		ft_print3bytes(wc, fd);
	else if (wc <= 0x1FFFFF)
		ft_print4bytes(wc, fd);
}
