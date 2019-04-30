/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_add_font_by_path.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:17:22 by sbednar           #+#    #+#             */
/*   Updated: 2019/04/30 20:21:32 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_main_add_font_by_path(t_ui_main *m, const char *path, int font_id)
{
	TTF_Font	*font;
	t_list		*lst;

	if (!(font = TTF_OpenFont(path, 24)) || !(lst = ft_lstnew(NULL, 0)))
		return (FUNCTION_FAILURE);
	lst->content = (void *)font;
	lst->content_size = font_id;
	ft_lstadd_back(&(m->sdl_fonts), lst);
	return (FUNCTION_SUCCESS);
}
