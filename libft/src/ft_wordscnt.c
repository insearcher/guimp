/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordscnt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:12:42 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/27 23:10:58 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordscnt(const char *str, char c)
{
	size_t	res;
	size_t	i;

	i = 0;
	res = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && str[i] == c)
			++i;
		if (str[i] && str[i] != c)
		{
			++res;
			++i;
		}
		while (str[i] && str[i] != c)
			++i;
	}
	return (res);
}
