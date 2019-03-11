/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 19:09:04 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/12 02:36:16 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_image.h>
# include "libft.h"

# define WIN_W		640
# define WIN_H		480

typedef struct		s_sdl
{
	SDL_Event		*evt;
	SDL_Window		*win;
	SDL_Renderer	*ren;
}					t_sdl;

typedef struct		s_env
{
	t_sdl			sdl;
	SDL_Surface		*sur;
}					t_env;

void				ui_create_env(t_env *e);
void				ui_create_win(const char *name, t_env *e);
SDL_Surface			*ui_create_sur(const int h, const int w);

void				ui_exit_with_msg(const char *msg, t_env *e);
void				ui_exit(t_env *e);

#endif
