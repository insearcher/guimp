/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_add_function_by_id.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:10:19 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/13 06:49:34 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_main_add_function_by_id(t_ui_main *m, pred_ptr_event f, const char *func_id)
{
	long		ptr;
	t_list		*node;
	int			hash;

	ptr = (long)f;
	hash = ft_strhash(func_id);
	if ((node = ft_lstnew((void *)&ptr, sizeof(ptr))) == NULL)
		ui_sdl_deinit(228);
	node->content_size = hash;
	ft_lstadd(&(m->functions), node);
	return (FUNCTION_SUCCESS);
}
