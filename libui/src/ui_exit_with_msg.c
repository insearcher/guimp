/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_exit_with_msg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 20:40:28 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/10 20:55:43 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_exit_with_msg(const char *msg, t_env *e)
{
	(void)e;
	perror(msg);
	TTF_Quit();
	SDL_Quit();
	exit(EXIT_FAILURE);
}
