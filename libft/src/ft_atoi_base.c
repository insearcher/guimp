/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 02:50:50 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/19 18:51:50 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_num_ok(char num, int base)
{
	char *arr;

	arr = ft_strdup("0123456789ABCDEF");
	if (num >= 'a' && num <= 'z')
		num -= 32;
	while (base--)
		if (arr[base] == num)
		{
			free(arr);
			return (1);
		}
	free(arr);
	return (0);
}

static int	net_value(char num)
{
	if (num >= 'a')
		return (num - 'a' + 10);
	if (num >= 'A')
		return (num - 'A' + 10);
	return (num - '0');
}

int			ft_atoi_base(const char *str, int str_base)
{
	int		i;
	int		sign;
	int		res;

	sign = 1;
	res = 0;
	i = 0;
	while (ft_isstn(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (is_num_ok(str[i], str_base))
		res = res * str_base + net_value(str[i++]);
	return (res * sign);
}
