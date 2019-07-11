/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_on_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 01:35:42 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/10 15:28:18 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	*get_lens_arr(const char *s, size_t num_words)
{
	size_t	*len_arr;
	size_t	i;
	size_t	j;

	len_arr = (size_t *)ft_memalloc(sizeof(size_t) * num_words);
	i = -1;
	j = -1;
	while (s[++i])
	{
		if (s[i] != ' ')
		{
			len_arr[++j] = ft_wordlen(&s[i], ' ');
			i += len_arr[j];
		}
		if (!s[i])
			break ;
	}
	return (len_arr);
}

static size_t	*num_join_free(size_t *arr, size_t num, size_t size)
{
	size_t	*tmp_arr;
	size_t	i;

	if (size == 1)
	{
		arr = (size_t *)malloc(sizeof(size_t));
		arr[0] = num;
		return (arr);
	}
	i = -1;
	tmp_arr = arr;
	arr = (size_t *)malloc(sizeof(size_t) * size);
	while (++i < size - 1)
		arr[i] = tmp_arr[i];
	arr[i] = num;
	return (arr);
}

static size_t	*get_num_words_in_strs(size_t *len_arr,
						size_t num_word, size_t s_len, size_t *num_strs)
{
	size_t *num_words_in_strs;
	size_t i;
	size_t len;
	size_t num_words_in_str;

	i = -1;
	len = 0;
	num_words_in_str = 0;
	while (++i < num_word)
	{
		len += len_arr[i] + 1;
		if (len <= s_len + 1)
		{
			num_words_in_str++;
			if (i + 1 == num_word)
			{
				(*num_strs)++;
				num_words_in_strs = num_join_free(num_words_in_strs,
									num_words_in_str, *num_strs);
			}
		}
		else
		{
			(*num_strs)++;
			len = 0;
			if (num_words_in_str == 0)
				num_words_in_strs = num_join_free(num_words_in_strs, 1, *num_strs);
			else if (--i || 1)
			{
				num_words_in_strs = num_join_free(num_words_in_strs,
										num_words_in_str, *num_strs);
				num_words_in_str = 0;
			}
		}
	}
	return (num_words_in_strs);
}

char			*cut_str_by_num_words(const char *s, size_t num_words)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	new_len_str;
	char	*res;

	i = -1;
	j = 0;
	new_len_str = 0;
	while (s[++i] && j < num_words)
	{
		if (s[i] != ' ')
		{
			j++;
			while (s[i] != ' ' && s[i])
			{
				new_len_str++;
				i++;
			}
			new_len_str++;
			i--;
		}
	}
	res = (char *)ft_memalloc(new_len_str + 2);
	i = -1;
	j = 0;
	k = -1;
	while (s[++i] && j < num_words)
	{
		if (s[i] != ' ')
		{
			while (s[i] != ' ' && s[i])
			{
				res[++k] = s[i];
				i++;
			}
			j++;
			res[++k] = ' ';
		}
	}
	res[k] = '\0';
	return (res);
}

char			**get_strs(const char *s, size_t num_strs,
								size_t *num_words_in_strs)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**strs;

	i = -1;
	j = -1;
	k = -1;
	strs = (char **)ft_memalloc(sizeof(char *) * (num_strs + 1));
	while (s[++i])
	{
		strs[++j] = cut_str_by_num_words(&(s[i]), num_words_in_strs[++k]);
		while (num_words_in_strs[k])
		{
			num_words_in_strs[k]--;
			while (s[i] == ' ' && s[i])
				++i;
			while (s[i] != ' ' && s[i])
				++i;
		}
		if (!s[i])
			break;
	}
	return (strs);
}

char			**ft_strsplit_on_size(const char *s, size_t s_len, size_t *num_strs)
{
	size_t	*arr_lens;
	size_t	*num_words_in_strs;
	size_t	num_word;

	if (!s)
		return (NULL);
	num_word = ft_wordscnt(s, ' ');
	arr_lens = get_lens_arr(s, num_word);
	*num_strs = 0;
	num_words_in_strs = get_num_words_in_strs(arr_lens,
							num_word, s_len, num_strs);
	return (get_strs(s, *num_strs, num_words_in_strs));
}
