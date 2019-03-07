/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:06:02 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/27 23:41:39 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *h, char const *n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!n[0])
		return ((char *)h);
	while (h[i])
	{
		j = 0;
		while (h[i + j] && n[j] && n[j] == h[i + j])
			++j;
		if (!n[j])
			return ((char *)&h[i]);
		++i;
	}
	return (NULL);
}
