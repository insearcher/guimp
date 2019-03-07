/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:14:24 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/29 13:22:51 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(char const *str)
{
	int			sign;
	int			i;
	long long	res;
	long long	prev;

	sign = 1;
	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		++i;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		prev = res * 10 + (str[i++] - '0') * sign;
		if ((sign > 0 && prev < res) || (sign < 0 && prev > res))
			return (sign > 0 ? -1 : 0);
		res = prev;
	}
	return (res);
}
