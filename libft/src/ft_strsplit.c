/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 01:35:13 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/28 20:26:17 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(const char *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	wrd;
	char	**s;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	wrd = ft_wordscnt(str, c);
	if (!(s = (char **)malloc(sizeof(s) * (ft_wordscnt(str, c) + 1))))
		return (NULL);
	while (str[i] && j < wrd)
	{
		while (str[i] && str[i] == c)
			++i;
		if (!(s[j] = ft_strallcpy(&str[i], ft_wordlen(&str[i], c))))
			return (ft_strsfree(s));
		i += ft_wordlen(&str[i], c);
		++j;
	}
	s[j] = NULL;
	return (s);
}
