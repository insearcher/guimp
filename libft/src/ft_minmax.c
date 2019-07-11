/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:51:59 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/10 14:52:02 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_min(int a, int b)
{
	return (a > b ? b : a);
}

float	ft_fmin(float a, float b)
{
	return (a > b ? b : a);
}

int		ft_max(int a, int b)
{
	return (a < b ? b : a);
}

float	ft_fmax(float a, float b)
{
	return (a < b ? b : a);
}