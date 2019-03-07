/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 00:29:54 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/27 21:51:22 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	int		b;
	int		e;
	int		i;

	if (!s)
		return (NULL);
	b = 0;
	while (ft_isstn(s[b]))
		++b;
	e = ft_strlen(s) - 1;
	while (e >= b && ft_isstn(s[e]))
		--e;
	if (!(res = (char *)malloc(e - b + 2)))
		return (NULL);
	i = 0;
	while (b <= e)
		res[i++] = s[b++];
	res[i] = '\0';
	return (res);
}
