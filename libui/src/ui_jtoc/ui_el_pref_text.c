/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_pref_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 23:00:31 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/10 04:43:23 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	get_font_color(t_ui_main *m, t_ui_el *e, t_jnode *n)
{
	t_jnode	*tmp;
	int		color;

	if ((tmp = jtoc_node_get_by_path(n, "text_area.font")) && tmp->type == string)
	{
		if (!(e->text_area->font = ui_main_get_font_by_id(m, jtoc_get_string(tmp))))
			ui_sdl_deinit(228);
	}
	else
		ui_sdl_deinit(228);
	if ((tmp = jtoc_node_get_by_path(n, "text_area.color")) && tmp->type == string)
	{
		color = ft_atoi_base(jtoc_get_string(tmp), 16);
		e->text_area->text_color = (SDL_Color){(Uint8)((color & 0xFF0000) >> 16),
			(Uint8)((color & 0x00FF00) >> 8), (Uint8)(color & 0x0000FF), 255};
	}
	else
		ui_sdl_deinit(228);
	if ((tmp = jtoc_node_get_by_path(n, "text_area.bg_color")) && tmp->type == string)
	{
		color = ft_atoi_base(jtoc_get_string(tmp), 16);
		e->text_area->bg_color = (SDL_Color){(Uint8)((color & 0xFF0000) >> 16),
			(Uint8)((color & 0x00FF00) >> 8), (Uint8)(color & 0x0000FF), 255};
	}
	return (FUNCTION_SUCCESS);
}

int	get_text_params(t_ui_el *e, t_jnode *n)
{
	int		hash;
	t_jnode	*tmp;

	if ((tmp = jtoc_node_get_by_path(n, "text_area.string_len")) && tmp->type == number)
		e->text_area->string_len = jtoc_get_int(tmp);
	if ((tmp = jtoc_node_get_by_path(n, "text_area.render_param")) && tmp->type == string)
	{
		hash = ft_strhash(jtoc_get_string(tmp));
		e->text_area->render_param |= (hash == ft_strhash("TEXT_IS_SOLID") ? TEXT_IS_SOLID : 0);
		e->text_area->render_param |= (hash == ft_strhash("TEXT_IS_SHADED") ? TEXT_IS_SHADED : 0);
		e->text_area->render_param |= (hash == ft_strhash("TEXT_IS_BLENDED") ? TEXT_IS_BLENDED : 0);
	}
	else
		e->text_area->render_param |= TEXT_IS_BLENDED;
	if ((tmp = jtoc_node_get_by_path(n, "text_area.params")))
	{
		tmp = tmp->down;
		while (tmp)
		{
			if (tmp->type != string)
				return (FUNCTION_FAILURE);
			hash = ft_strhash(jtoc_get_string(tmp));
			e->text_area->params |= (hash == ft_strhash("TEXT_IS_CENTERED") ? TEXT_IS_CENTERED : 0);
			e->text_area->params |= (hash == ft_strhash("TEXT_IS_INPUTTING") ? TEXT_IS_INPUTTING : 0);
			e->text_area->params |= (hash == ft_strhash("TEXT_IS_REGULAR") ? TEXT_IS_REGULAR : 0);
			tmp = tmp->right;
		}
	}
	return (FUNCTION_SUCCESS);
}

int ui_el_pref_text(t_ui_main *m, t_ui_el *e, t_jnode *n)
{
	char	*tmp_text;
	t_jnode	*tmp;

	tmp_text = NULL;
	if ((jtoc_node_get_by_path(n, "text_area")))
	{
		e->text_area = (t_ui_text *)ft_memalloc(sizeof(t_ui_text));
		if (get_font_color(m, e, n))
			ui_sdl_deinit(228);
		if (get_text_params(e, n))
			ui_sdl_deinit(228);
		if ((tmp = jtoc_node_get_by_path(n, "text_area.text")) && tmp->type == string)
			tmp_text = ft_strdup(jtoc_get_string(tmp));
		else
			ui_sdl_deinit(228);
		e->params |= EL_IS_TEXT;
		ui_el_update_text(e, tmp_text);
		free(tmp_text);
		/*
		   SDL_Log("str: %s\n", e->text_area->text);
		   SDL_Log("str color: (%d, %d, %d)\n", e->text_area->text_color.r,
		   e->text_area->text_color.g, e->text_area->text_color.b);
		   SDL_Log("bg color: (%d, %d, %d)\n", e->text_area->bg_color.r,
		   e->text_area->bg_color.g, e->text_area->bg_color.b);
		   */
	}
	return (FUNCTION_SUCCESS);
}
