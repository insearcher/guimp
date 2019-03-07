/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:53:37 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/29 19:25:14 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	char	*cdst;
	char	*csrc;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	cdst = (char *)dst;
	csrc = (char *)src;
	i = -1;
	if (csrc < cdst)
	{
		while ((int)(--len) >= 0)
			cdst[len] = csrc[len];
	}
	else
	{
		while (++i < len)
			cdst[i] = csrc[i];
	}
	return ((void *)cdst);
}
