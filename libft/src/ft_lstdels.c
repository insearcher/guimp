/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 23:34:33 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/10 20:30:57 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_lstdels(t_list **alst)
{
	if (!alst || !(*alst))
		return ;
	if ((*alst)->next)
		ft_lstdels(&((*alst)->next));
	ft_lstdelones(alst);
}
