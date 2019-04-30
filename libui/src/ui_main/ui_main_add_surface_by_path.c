/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_add_surface_by_path.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:20:16 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/30 20:14:19 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_main_add_surface_by_path(t_ui_main *m, const char *path, int sur_id)
{
	SDL_Surface	*sur;
	t_list		*lst;

	if (!(sur = IMG_Load(path)) || !(lst = ft_lstnew(NULL, 0)))
		return (FUNCTION_FAILURE);
	lst->content = (void *)sur;
	lst->content_size = sur_id;
	ft_lstadd_back(&(m->sdl_surfaces), lst);
	return (FUNCTION_SUCCESS);
}
