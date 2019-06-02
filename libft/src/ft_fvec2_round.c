/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fvec2_round.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 20:09:07 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/01 20:09:53 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fvec2  ft_fvec2_round(t_fvec2 v)
{
	t_fvec2 ronded_v;

	ronded_v.x = roundf(v.x);
	ronded_v.y = roundf(v.y);
	return (ronded_v);
}
