/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelones.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 23:35:56 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/03 14:08:08 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_lstdelones(t_list **alst)
{
	t_list	*tmp;

	if (!alst)
		return ;
	tmp = *alst;
	*alst = NULL;
	free(tmp->content);
	free(tmp);
}
