/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 19:04:10 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/16 22:30:50 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIMP_H
# define GUIMP_H

# include "libft.h"
# include "libui.h"

void				ui_create_env(t_env *e);
void				ui_create_win(const char *name, t_env *e);
SDL_Surface			*ui_create_sur(const int h, const int w);

void				ui_exit_with_msg(const char *msg, t_env *e);
void				ui_exit(t_env *e);

#endif
