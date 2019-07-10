/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jtoc_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 00:22:42 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/09 19:22:46 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libjtoc.h"

static void	jtoc_atof_fraction(const char *str, int i, int s, float *res)
{
	float	b;

	b = 0.1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*res += (str[i++] - '0') * b * s;
		b /= 10;
	}
}

static void	jtoc_atof(const char *str, float *res)
{
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		++i;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
		*res = (*res * 10) + (str[i++] - '0') * sign;
	if (str[i] == '.')
		jtoc_atof_fraction(str, ++i, sign, res);
}

int				jtoc_parse_number(t_jnode *p, const char *str, int b, int e)
{
	char	*sub;
	float	*data;

	if (!(sub = ft_strsub(str, b, e - b + 1)))
		return (FUNCTION_FAILURE);
	if (!(data = (float *)malloc(sizeof(float))))
	{
		free(sub);
		return (FUNCTION_FAILURE);
	}
	jtoc_atof(sub, data);
	p->data = (void *)data;
	free(sub);
	return (FUNCTION_SUCCESS);
}

int				jtoc_parse_value(t_jnode *p, const char *str, int b, int e)
{
	if ((p->type == array && jtoc_parse_array(p, str, b, e) < 0) ||
		(p->type == string && jtoc_parse_string(p, str, b, e) < 0) ||
		(p->type == object && jtoc_parse_object(p, str, b, e) < 0) ||
		(p->type == number && jtoc_parse_number(p, str, b, e) < 0))
		return (FUNCTION_FAILURE);
	return (FUNCTION_SUCCESS);
}

t_jnode			*jtoc_parse(const char *str)
{
	t_jnode	*root;

	if (!(root = jtoc_node_create(none, "root", NULL)))
		return (NULL);
	if (jtoc_parse_object(root, str, 0, ft_strlen(str) - 1) < 0)
	{
		jtoc_node_clear(root);
		return (NULL);
	}
	return (root);
}
