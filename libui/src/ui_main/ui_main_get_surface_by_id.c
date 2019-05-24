/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_get_surface_by_id.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:13:13 by sbednar           #+#    #+#             */
/*   Updated: 2019/05/24 19:29:49 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

SDL_Surface	*ui_main_get_surface_by_id(t_ui_main *m, const char *sur_id)
{
	SDL_Surface	*res;
	t_list		*tmp;
	int			hash;

	res = NULL;
	tmp = m->sdl_surfaces;
	hash = ft_strhash(sur_id);
	while (tmp && !res)
	{
		if (tmp->content_size == (size_t)hash)
			res = (SDL_Surface *)tmp->content;
		tmp = tmp->next;
	}
	return (res);
}

