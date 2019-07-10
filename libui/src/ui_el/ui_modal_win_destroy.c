/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_modal_win_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:58:35 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/09 21:59:07 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_modal_win_destroy(t_ui_modal_win *mw)
{
	int	i;

	free(mw->text);
	free(mw->output_text);
	i = -1;
	while (mw->text[++i])
		free(mw->text[++i]);
	free(mw->text);
	free(mw);
}