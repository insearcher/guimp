/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_change_text_in_focused_el.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:18:31 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/13 09:35:54 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static char	*circumcision(t_ui_el *el)
{
	char	*str;

	if (el->text_area->text == NULL || *el->text_area->text == '\0')
		return (ft_strnew(1));
	str = ft_strsub(el->text_area->text, 0, ft_strlen(el->text_area->text) - 1);
	return (str);
}

static char	*join_with_letter(t_ui_el *el, unsigned int keycode)
{
	char	*str;
	char	*str_letter;

	str_letter = ft_strnew(1);
//	if (el->text_area->params & TEXT_IS_BIG)
//		str_letter[0] = (char)(keycode + 64);
//	else
	str_letter[0] = (char)(keycode + 93);
	if (el->text_area->text == NULL)
		return (str_letter);
	str = ft_strjoin(el->text_area->text, str_letter);
	free(str_letter);
	return(str);
}

static char	*join_with_number(t_ui_el *el, unsigned int keycode)
{
	char	*str_letter;
	char	*str;

	str_letter = ft_strnew(1);
	str_letter[0] = (char)(keycode + 19);
	if (el->text_area->text == NULL)
		return (str_letter);
	str = ft_strjoin(el->text_area->text, str_letter);
	free(str_letter);
	return(str);
}

static char	*join_with_other(t_ui_el *el, unsigned int keycode)
{
	char	*str_letter;
	char	*str;

	str_letter = ft_strnew(1);
	if (keycode == SDL_SCANCODE_SLASH)
		str_letter[0] = '/';
	if (el->text_area->text == NULL)
		return (str_letter);
	str = ft_strjoin(el->text_area->text, str_letter);
	free(str_letter);
	return(str);
}

int	ui_win_event_change_text_in_focused_el(t_ui_main *m, void *a)
{
	t_ui_win	*w;
	t_ui_el		*el;
	char		*new_text;

	w = (t_ui_win *)a;
	el = m->focused_el;
	if (!el || !(el->params & EL_IS_TEXT) || !(el->text_area->params & TEXT_IS_INPUTTING))
		return (1);
	if (m->cur_keycode >= SDL_SCANCODE_A && m->cur_keycode <= SDL_SCANCODE_Z)
	{
		new_text = join_with_letter(el, m->cur_keycode);
		ui_el_update_text(el, new_text);
		if (new_text != NULL)
			free(new_text);
		new_text = NULL;
	}
	else if (m->cur_keycode >= SDL_SCANCODE_1 && m->cur_keycode <= SDL_SCANCODE_9)
	{
		new_text = join_with_number(el, m->cur_keycode);
		ui_el_update_text(el, new_text);
		if (new_text != NULL)
			free(new_text);
		new_text = NULL;
	}
	else if (m->cur_keycode == SDL_SCANCODE_BACKSPACE)
	{
		new_text = circumcision(el);
		ui_el_update_text(el, new_text);
		if (new_text != NULL)
			free(new_text);
		new_text = NULL;
	}
	else if (m->cur_keycode == SDL_SCANCODE_SLASH)
	{
		new_text = join_with_other(el, m->cur_keycode);
		ui_el_update_text(el, new_text);
		if (new_text != NULL)
			free(new_text);
		new_text = NULL;
	}
	SDL_Log("%s\n", el->text_area->text);
	return (1);
}
