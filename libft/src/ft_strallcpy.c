/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strallcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 23:15:45 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/28 20:26:06 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strallcpy(char const *src, size_t len)
{
	size_t	i;
	char	*res;

	if (!(res = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = src[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}
