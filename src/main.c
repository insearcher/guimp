/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:09:10 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/16 22:32:17 by sbednar          ###   ########.fr       */
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
	ui_create_env(&e);
	ui_create_win("kek", &e);

	exit(EXIT_SUCCESS);
}
