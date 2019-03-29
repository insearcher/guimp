/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_deinit_enviroment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 22:46:42 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/29 22:51:35 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_deinit_enviroment(void)
{
	SDL_Quit();
	IMG_Quit();
	TTF_Quit();
	exit(EXIT_SUCCESS);
}
