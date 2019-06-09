/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_add_texture_from_file_dialog.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 23:16:17 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/09 23:19:30 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ui_el_add_texture_from_file_dialog(t_ui_el *el)
{
	char	*path;

	path = NULL;
	if (ui_open_file_dialog(&path) < 0)
		return (FUNCTION_FAILURE);
	ui_el_add_texture_from_file(el, path, "default");
	return (FUNCTION_SUCCESS);
}
