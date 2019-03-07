/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:58:54 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/27 23:40:55 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	size_t	slen;
	size_t	i;
	char	*res;

	slen = ft_strlen(s);
	i = -1;
	res = NULL;
	while (++i < slen)
	{
		if (s[i] == (char)c)
			res = (char *)(&s[i]);
	}
	if (i == slen && c == '\0')
		res = (char *)(&s[i]);
	return (res);
}
