/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_get_function_by_id.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:13:52 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/19 17:16:11 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

func_ptr	ui_main_get_function_by_id(t_ui_main *m, const char *func_id)
{
	func_ptr	res;
	t_list		*tmp;
	int			hash;

	res = NULL;
	tmp = m->functions;
	hash = ft_strhash(func_id);
	while (tmp && !res)
	{
		if (tmp->content_size == (size_t)hash)
			res = (func_ptr)(*((long *)tmp->content));
		tmp = tmp->next;
	}
	return (res);
}
