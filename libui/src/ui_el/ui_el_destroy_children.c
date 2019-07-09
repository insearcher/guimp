/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_destroy_children.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:23:18 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/09 21:23:18 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_el_destroy_children(t_list *c)
{
	t_list	*p;

	p = c;
	while (c)
	{
		ui_el_destroy((t_ui_el *)c->content);
		c = c->next;
		free(p);
		p = c;
	}
}