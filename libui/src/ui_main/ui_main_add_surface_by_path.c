/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_add_surface_by_path.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:20:16 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/09 18:48:35 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_main_add_surface_by_path(t_ui_main *m, const char *path, const char *sur_id)
{
	SDL_Surface	*sur;
	t_list		*lst;
	int			hash;

	lst = NULL;
	if (!(sur = IMG_Load(path)) || !(lst = ft_lstnew(NULL, 0)))
		ui_sdl_deinit(228);
	hash = ft_strhash(sur_id);
	lst->content = (void *)sur;
	lst->content_size = hash;
	ft_lstadd(&(m->sdl_surfaces), lst);
	return (FUNCTION_SUCCESS);
}
