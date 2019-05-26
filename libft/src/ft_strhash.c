/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 18:51:06 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/24 19:47:25 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strhash(const char *str)
{
	int	res;
	int	p;
	int	i;

	res = 0;
	p = 1;
	i = -1;
	while (str[++i])
	{
		res = (res + (str[i] - 'a') * p) % HASH_M;
		p = (p * HASH_P) % HASH_M;
	}
	return (res);
}
