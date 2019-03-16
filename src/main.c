/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:09:10 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/16 23:17:31 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	t_env	e;

	// (void)e;
	// ft_putchar('a');
	ui_create_env(&e, WIN_W, WIN_H);
	ui_create_win(&e, "kek");

	for (int i = 0; i < e.w; ++i)
	{
		for (int j = 0; j < e.h; ++j)
		{
			ui_set_pixel(&e, i, j, 0x00000000);
		}
	}

	SDL_Delay( 2000 );

	ui_exit(&e);

	exit(EXIT_SUCCESS);
}
