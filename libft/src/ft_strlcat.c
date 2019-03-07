/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:49:31 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/27 17:19:24 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	char	*cdst;
	char	*csrc;
	size_t	src_len;
	size_t	dst_len;

	if (!(cdst = (char *)ft_memchr(dst, '\0', size)))
		return (size + ft_strlen(src));
	csrc = (char *)src;
	cdst = (char *)dst;
	dst_len = ft_strlen(dst);
	src_len = dst_len + ft_strlen(src);
	cdst += dst_len;
	while (++dst_len < size && *csrc)
		*cdst++ = *csrc++;
	*cdst = '\0';
	return (src_len);
}
