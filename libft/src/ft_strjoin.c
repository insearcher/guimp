/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 00:18:18 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/27 23:53:28 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1len;
	size_t	s2len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!(res = (char *)malloc(s1len + s2len + 1)))
		return (NULL);
	i = 0;
	while (i < s1len)
	{
		res[i] = s1[i];
		++i;
	}
	while (i < s1len + s2len)
	{
		res[i] = s2[i - s1len];
		++i;
	}
	res[i] = '\0';
	return (res);
}
