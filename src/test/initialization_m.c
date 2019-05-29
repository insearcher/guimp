/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_m.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 07:33:51 by sbecker           #+#    #+#             */
/*   Updated: 2019/05/29 18:31:51 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp_test.h"

void	initialization_main_and_default_surfaces(t_guimp *guimp)
{
	t_ui_main	*m;

	m = &guimp->m;
	ui_main_init(m);
	ui_main_fill_default_surfaces(m);
}
