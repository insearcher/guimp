/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_pref_modal_win.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 20:24:48 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/10 06:30:06 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int get_modal_text_params(t_ui_el *e, t_jnode *n)
{
	int     hash;
	t_jnode *tmp;

	if ((tmp = jtoc_node_get_by_path(n, "text_area.string_len")) && tmp->type == number)
		e->modal_win->string_len = jtoc_get_int(tmp);
	if ((tmp = jtoc_node_get_by_path(n, "text_area.render_param")) && tmp->type == string)
	{
		hash = ft_strhash(jtoc_get_string(tmp));
		e->modal_win->render_param |= (hash == ft_strhash("TEXT_IS_SOLID") ? TEXT_IS_SOLID : 0);
		e->modal_win->render_param |= (hash == ft_strhash("TEXT_IS_SHADED") ? TEXT_IS_SHADED : 0);
		e->modal_win->render_param |= (hash == ft_strhash("TEXT_IS_BLENDED") ? TEXT_IS_BLENDED : 0);
	}
	else
		e->modal_win->render_param |= TEXT_IS_BLENDED;
	if ((tmp = jtoc_node_get_by_path(n, "text_area.params")))
	{
		tmp = tmp->down;
		while (tmp)
		{
			if (tmp->type != string)
				return (FUNCTION_FAILURE);
			hash = ft_strhash(jtoc_get_string(tmp));
			e->modal_win->params |= (hash == ft_strhash("TEXT_IS_CENTERED") ? TEXT_IS_CENTERED : 0);
			e->modal_win->params |= (hash == ft_strhash("TEXT_IS_INPUTTING") ? TEXT_IS_INPUTTING : 0);
			e->modal_win->params |= (hash == ft_strhash("TEXT_IS_REGULAR") ? TEXT_IS_REGULAR : 0);
			tmp = tmp->right;
		}
	}
	return (FUNCTION_SUCCESS);
}

int get_modal_font_color(t_ui_main *m, t_ui_el *e, t_jnode *n)
{
	t_jnode *tmp;
	int     color;

	if ((tmp = jtoc_node_get_by_path(n, "text_area.font")) && tmp->type == string)
	{
		if (!(e->modal_win->font = ui_main_get_font_by_id(m, jtoc_get_string(tmp))))
			return (FUNCTION_FAILURE);
	}
	else
		return (FUNCTION_FAILURE);
	if ((tmp = jtoc_node_get_by_path(n, "text_area.color")) && tmp->type == string)
	{
		color = ft_atoi_base(jtoc_get_string(tmp), 16);
		e->modal_win->text_color = (SDL_Color){(Uint8)((color & 0xFF0000) >> 16),
			(Uint8)((color & 0x00FF00) >> 8), (Uint8)(color & 0x0000FF), 255};
	}
	else
		return (FUNCTION_FAILURE);
	if ((tmp = jtoc_node_get_by_path(n, "text_area.bg_color")) && tmp->type == string)
	{
		color = ft_atoi_base(jtoc_get_string(tmp), 16);
		e->modal_win->bg_color = (SDL_Color){(Uint8)((color & 0xFF0000) >> 16),
			(Uint8)((color & 0x00FF00) >> 8), (Uint8)(color & 0x0000FF), 255};
	}
	return (FUNCTION_SUCCESS);
}



int ui_el_pref_text_modal_win(t_ui_main *m, t_ui_el *e, t_jnode *n)
{
	char    *tmp_text;
	size_t	num_strs;
	t_jnode *tmp;

	if ((jtoc_node_get_by_path(n, "text_area")))
	{
		if (get_modal_font_color(m, e, n) == FUNCTION_FAILURE)
			return (FUNCTION_FAILURE);
		if (get_modal_text_params(e, n) == FUNCTION_FAILURE)
			return (FUNCTION_FAILURE);
		if ((tmp = jtoc_node_get_by_path(n, "text_area.text")) && tmp->type == string)
			tmp_text = ft_strdup(jtoc_get_string(tmp));
		else
			return (FUNCTION_FAILURE);
		e->modal_win->text = ft_strsplit_on_size(tmp_text, e->modal_win->string_len, &num_strs);
		e->modal_win->size.x = 300 + e->modal_win->string_len * 16;
		e->modal_win->size.y = num_strs * 45 + 120;
		free(tmp_text);
		return (FUNCTION_SUCCESS);
	}
	return (FUNCTION_FAILURE);
}

static int	get_win_params(t_ui_el *e, t_jnode *n)
{
	t_jnode *tmp;
	int		hash;

	if ((tmp = jtoc_node_get_by_path(n, "modal_win.win_id")) && tmp->type == number)
		e->modal_win->w_id = jtoc_get_int(tmp);
	else
		return (FUNCTION_FAILURE);
	if ((tmp = jtoc_node_get_by_path(n, "modal_win.title")) && tmp->type == string)
		e->modal_win->title = ft_strdup(jtoc_get_string(tmp));
	if ((tmp = jtoc_node_get_by_path(n, "modal_win.win_type")) && tmp->type == string)
	{
		hash = ft_strhash(jtoc_get_string(tmp));
		e->params |= (hash == ft_strhash("MODAL_OK") ? EL_MODAL_OK : 0);
	}
	else
		return (FUNCTION_FAILURE);
	e->modal_win->pos.x = SDL_WINDOWPOS_CENTERED;	//TODO maybe set in json
	e->modal_win->pos.y = SDL_WINDOWPOS_CENTERED;
	return (FUNCTION_SUCCESS);
}

int ui_el_pref_modal_win(t_ui_main *m, t_ui_el *e, t_jnode *n)
{
	t_jnode *tmp;

	(void)m;
	if ((tmp = jtoc_node_get_by_path(n, "modal_win")))
	{
		e->modal_win = (t_ui_modal_win *)ft_memalloc(sizeof(t_ui_modal_win));
		if (get_win_params(e, n) == FUNCTION_FAILURE)
			return (FUNCTION_FAILURE);
		if (ui_el_pref_text_modal_win(m, e, tmp) == FUNCTION_FAILURE)
			return (FUNCTION_FAILURE);
		ui_event_add_listener(e->events->onPointerLeftButtonPressed, ui_el_create_modal_ok);
	}
	return (FUNCTION_SUCCESS);
}
