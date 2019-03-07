/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:39:15 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/27 23:41:48 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *h, char const *n, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!n[0])
		return ((char *)h);
	while (h[i] && i < len)
	{
		j = 0;
		while (i + j < len && h[i + j] && n[j] && n[j] == h[i + j])
			++j;
		if (!n[j])
			return ((char *)&h[i]);
		++i;
	}
	return (NULL);
}
