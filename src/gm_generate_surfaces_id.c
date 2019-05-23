/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_generate_surfaces_id.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 09:37:56 by edraugr-          #+#    #+#             */
/*   Updated: 2019/05/23 12:11:51 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

int	gm_generate_surf_id(int generate_flag)
{
	static int	last_surface_id = ID_GENERATOR_START;

	if (generate_flag == ID_GENERATOR_ADD)
		last_surface_id++;
	if (generate_flag == ID_GENERATOR_DEL
		&& last_surface_id != ID_GENERATOR_START)
		last_surface_id--;
	return (last_surface_id);
}

int	gm_generator_get_surf_count(void)
{
	return (gm_generate_surf_id(ID_GENERATOR_GET) - ID_GENERATOR_START);
}

int	gm_generator_get_surf_id_by_num(int surf_serial_num)
{
	if (surf_serial_num >= gm_generator_get_surf_count()
		|| surf_serial_num < 0)
		return (-1);
	return (ID_GENERATOR_START + surf_serial_num + 1);
}
