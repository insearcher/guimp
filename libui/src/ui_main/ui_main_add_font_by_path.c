/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_add_font_by_path.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:17:22 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/09 18:48:14 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_main_add_font_by_path(t_ui_main *m, const char *path, const char *font_id)
{
	TTF_Font	*font;
	t_list		*lst;
	int			hash;

	lst = NULL;
	if (!(font = TTF_OpenFont(path, 128)) || !(lst = ft_lstnew(NULL, 0)))
		ui_sdl_deinit(228);
	hash = ft_strhash(font_id);
	lst->content = (void *)font;
	lst->content_size = hash;
	ft_lstadd(&(m->sdl_fonts), lst);
	return (FUNCTION_SUCCESS);
}
