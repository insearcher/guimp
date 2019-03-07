/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 23:24:16 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/27 23:31:09 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsfree(char **src)
{
	char	*cur;
	char	*tmp;

	if (!src || !*src)
		return (NULL);
	cur = *src;
	while (*cur)
	{
		tmp = cur++;
		free(tmp);
	}
	free(src);
	return (NULL);
}
