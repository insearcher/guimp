/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_from_json.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 18:47:42 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/07 22:14:38 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int	ui_el_from_json_white_texture(t_ui_el *e, t_jnode *n)
{
	t_jnode	*tmp;
	int		w;
	int		h;
	char	*el_id;

	if (!(tmp = jtoc_node_get_by_path(n, "width")) || tmp->type != number ||
		(w = jtoc_get_int(tmp)) <= 0 ||
		!(tmp = jtoc_node_get_by_path(n, "height")) || tmp->type != number ||
		(h = jtoc_get_int(tmp)) <= 0 ||
		!(tmp = jtoc_node_get_by_path(n, "el_id")) || tmp->type != string ||
		!(el_id = jtoc_get_string(tmp)))
		return (ui_sdl_log_error("NODE EL (WHITE TEXTURE)", e->id));
	ui_el_add_white_texture(e, w, h, el_id);
	return (FUNCTION_SUCCESS);
}

static int	ui_el_from_json_empty_texture(t_ui_el *e, t_jnode *n)
{
	t_jnode	*tmp;
	int		w;
	int		h;
	char	*el_id;

	if (!(tmp = jtoc_node_get_by_path(n, "width")) || tmp->type != number ||
		(w = jtoc_get_int(tmp)) <= 0 ||
		!(tmp = jtoc_node_get_by_path(n, "height")) || tmp->type != number ||
		(h = jtoc_get_int(tmp)) <= 0 ||
		!(tmp = jtoc_node_get_by_path(n, "el_id")) || tmp->type != string ||
		!(el_id = jtoc_get_string(tmp)))
		return (ui_sdl_log_error("NODE EL (EMPTY TEXTURE)", e->id));
	ui_el_add_empty_texture(e, w, h, el_id);
	return (FUNCTION_SUCCESS);
}

static int	ui_el_from_json_color_texture(t_ui_el *e, t_jnode *n)
{
	t_jnode	*tmp;
	char	*color;
	char	*el_id;

	if (!(tmp = jtoc_node_get_by_path(n, "color")) || tmp->type != string ||
		!(color = jtoc_get_string(tmp)) ||
		!(tmp = jtoc_node_get_by_path(n, "el_id")) || tmp->type != string ||
		!(el_id = jtoc_get_string(tmp)))
		return (ui_sdl_log_error("NODE EL (COLOR TEXTURE)", e->id));
	ui_el_add_color_texture(e, (t_vec2){e->rect.w, e->rect.h}, ft_atoi_base(color, 16), el_id);
	return (FUNCTION_SUCCESS);
}

static int	ui_el_from_json_gradient_texture(t_ui_el *e, t_jnode *n)
{
	t_jnode	*tmp;
	char	*color;
	char	*el_id;

	if (!(tmp = jtoc_node_get_by_path(n, "color")) || tmp->type != string ||
		!(color = jtoc_get_string(tmp)) ||
		!(tmp = jtoc_node_get_by_path(n, "el_id")) || tmp->type != string ||
		!(el_id = jtoc_get_string(tmp)))
		return (ui_sdl_log_error("NODE EL (GRADIENT TEXTURE)", e->id));
	ui_el_add_gradient_texture(e, (t_vec2){e->rect.w, e->rect.h}, ft_atoi_base(color, 16), el_id);
	return (FUNCTION_SUCCESS);
}

static int	ui_el_from_json_texture(t_ui_main *m, t_ui_el *e, t_jnode *n)
{
	t_jnode	*tmp;
	char	*main_id;
	char	*el_id;

	if ((tmp = jtoc_node_get_by_path(n, "type")))
	{
		if (tmp->type != string ||
			(!ft_strcmp(jtoc_get_string(tmp), "empty") && ui_el_from_json_empty_texture(e, n)) ||
			(!ft_strcmp(jtoc_get_string(tmp), "white") && ui_el_from_json_white_texture(e, n)) ||
			(!ft_strcmp(jtoc_get_string(tmp), "color") && ui_el_from_json_color_texture(e, n)) ||
			(!ft_strcmp(jtoc_get_string(tmp), "gradient") && ui_el_from_json_gradient_texture(e, n)))
			return (ui_sdl_log_error("NODE EL (TEXTURE TYPE)", e->id));
	}
	else
	{
		if (!(tmp = jtoc_node_get_by_path(n, "main_id")) || tmp->type != string ||
		!(main_id = jtoc_get_string(tmp)) ||
		!(tmp = jtoc_node_get_by_path(n, "el_id")) || tmp->type != string ||
		!(el_id = jtoc_get_string(tmp)))
			return (ui_sdl_log_error("NODE EL (TEXTURE)", e->id));
		ui_el_add_texture_from_main_by_id(m, e, main_id, el_id);
	}
	return (FUNCTION_SUCCESS);
}

t_ui_event		*ui_el_from_json_get_event_by_name(t_ui_el *e, const char *n)
{
	int			hash;
	t_ui_event	*res;

	hash = ft_strhash(n);
	res = NULL;
	res = (hash == ft_strhash("onPointerEnter") ? e->events->onPointerEnter : res);
	res = (hash == ft_strhash("onPointerStay") ? e->events->onPointerStay : res);
	res = (hash == ft_strhash("onPointerExit") ? e->events->onPointerExit : res);
	res = (hash == ft_strhash("onPointerLeftButtonPressed") ? e->events->onPointerLeftButtonPressed : res);
	res = (hash == ft_strhash("onPointerLeftButtonHold") ? e->events->onPointerLeftButtonHold : res);
	res = (hash == ft_strhash("onPointerLeftButtonReleased") ? e->events->onPointerLeftButtonReleased : res);
	res = (hash == ft_strhash("onPointerRightButtonPressed") ? e->events->onPointerRightButtonPressed : res);
	res = (hash == ft_strhash("onPointerRightButtonHold") ? e->events->onPointerRightButtonHold : res);
	res = (hash == ft_strhash("onPointerRightButtonReleased") ? e->events->onPointerRightButtonReleased : res);
	res = (hash == ft_strhash("onScrollUp") ? e->events->onScrollUp : res);
	res = (hash == ft_strhash("onScrollDown") ? e->events->onScrollDown : res);
	res = (hash == ft_strhash("onRender") ? e->events->onRender : res);
	res = (hash == ft_strhash("onResize") ? e->events->onResize : res);
	return (res);
}

// static func_ptr	ui_el_from_json_get_function_by_name(const char *n)
// {
// 	int			hash;
// 	func_ptr	res;

// 	hash = ft_strhash(n);
// 	res = NULL;
// 	return (FUNCTION_SUCCESS);
// }

static int	ui_el_from_json_event(t_ui_main *m, t_ui_el *e, t_jnode *n)
{
	char		*event_name;
	char		*func_name;
	t_ui_event	*ev;
	func_ptr	f;
	t_jnode		*tmp;

	if (n->type != object ||
		!(tmp = jtoc_node_get_by_path(n, "event_name")) || tmp->type != string ||
		!(event_name  = jtoc_get_string(tmp)) ||
		!(ev = ui_el_from_json_get_event_by_name(e, event_name)) ||
		!(tmp = jtoc_node_get_by_path(n, "func_name")) || tmp->type != string ||
		!(func_name  = jtoc_get_string(tmp)) ||
		(ft_strcmp(func_name, "clear") && !(f = ui_main_get_function_by_id(m, func_name))))
		return (ui_sdl_log_error("NODE EL (EVENT)", e->id));
	if (!ft_strcmp(func_name, "clear"))
		ui_event_clear(ev);
	else
		ui_event_add_listener(ev, f);
	return (FUNCTION_SUCCESS);
}

static int	ui_el_from_json_events(t_ui_main *m, t_ui_el *e, t_jnode *n)
{
	t_jnode	*tmp;

	if ((tmp = jtoc_node_get_by_path(n, "events")))
	{
		tmp = tmp->down;
		while (tmp)
		{
			if (tmp->type != object || ui_el_from_json_event(m, e, tmp))
				return (FUNCTION_FAILURE);
			tmp = tmp->right;
		}
	}
	return (FUNCTION_SUCCESS);
}

static int	ui_el_from_json_textures(t_ui_main *m, t_ui_el *e, t_jnode *n)
{
	t_jnode	*tmp;

	if ((tmp = jtoc_node_get_by_path(n, "textures")))
	{
		tmp = tmp->down;
		while (tmp)
		{
			if (tmp->type != object || ui_el_from_json_texture(m, e, tmp))
				return (FUNCTION_FAILURE);
			tmp = tmp->right;
		}
	}
	if ((tmp = jtoc_node_get_by_path(n, "current_texture")))
	{
		if (tmp->type != string)
			return (ui_sdl_log_error("NODE EL (CURRENT TEXTURE)", e->id));
		ui_el_set_current_texture_by_id(e, jtoc_get_string(tmp));
	}
	return (ui_el_from_json_events(m, e, n));
}

static int	ui_parse_canvas(t_ui_main *m, t_ui_el *e, t_jnode *n)
{
	if (ui_el_from_json_textures(m, e, n))
		return (FUNCTION_FAILURE);
	return (FUNCTION_SUCCESS);
}

static int	ui_el_from_json_size(t_ui_main *m, t_ui_win *w, t_ui_el *e, t_jnode *n)
{
	float	x;
	float	y;
	int		p;
	t_jnode	*tmp;

	if (!(tmp = jtoc_node_get_by_path(n, "size.x")) || tmp->type != number)
		return (ui_sdl_log_error("NODE EL (SIZE.X)", e->id));
	x = jtoc_get_float(tmp);
	if (!(tmp = jtoc_node_get_by_path(n, "size.y")) || tmp->type != number)
		return (ui_sdl_log_error("NODE EL (SIZE.Y)", e->id));
	y = jtoc_get_float(tmp);
	p = 0;
	if ((tmp = jtoc_node_get_by_path(n, "size.params")))
	{
		tmp = tmp->down;
		while (tmp)
		{
			if (tmp->type != string)
				return (ui_sdl_log_error("NODE EL (SIZE.PARAMS)", e->id));
			p |= ui_get_pos_size(jtoc_get_string(tmp));
			tmp = tmp->right;
		}
	}
	(void)w;
	ui_el_set_size(e, p, (t_fvec2){x, y});
	return (ui_el_from_json_textures(m, e, n));
}

static int	ui_el_from_json_pos(t_ui_main *m, t_ui_win *w, t_ui_el *e, t_jnode *n)
{
	float	x;
	float	y;
	int		p;
	t_jnode	*tmp;

	if (!(tmp = jtoc_node_get_by_path(n, "pos.x")) || tmp->type != number)
		return (ui_sdl_log_error("NODE EL (POS.X)", e->id));
	x = jtoc_get_float(tmp);
	if (!(tmp = jtoc_node_get_by_path(n, "pos.y")) || tmp->type != number)
		return (ui_sdl_log_error("NODE EL (POS.Y)", e->id));
	y = jtoc_get_float(tmp);
	p = 0;
	if ((tmp = jtoc_node_get_by_path(n, "pos.params")))
	{
		tmp = tmp->down;
		while (tmp)
		{
			if (tmp->type != string)
				return (ui_sdl_log_error("NODE EL (POS.PARAMS)", e->id));
			p |= ui_get_pos_size(jtoc_get_string(tmp));
			tmp = tmp->right;
		}
	}
	ui_el_set_pos(e, p, (t_fvec2){x, y});
	return (ui_el_from_json_size(m, w, e, n));
}

static int	ui_el_from_json_params(t_ui_main *m, t_ui_win *w, t_ui_el *e, t_jnode *n)
{
	t_jnode	*tmp;

	e->params = 0;
	if ((tmp = jtoc_node_get_by_path(n, "params")))
	{
		tmp = tmp->down;
		while (tmp)
		{
			if (tmp->type != string)
				return (ui_sdl_log_error("NODE EL (PARAMS)", e->id));
			e->params |= ui_get_el_param_from_string(jtoc_get_string(tmp));
			tmp = tmp->right;
		}
	}
	if (ui_el_setup_by_type(e, n))
		return (FUNCTION_FAILURE);
	if (ui_el_pref_text(m, e, n))
		return (FUNCTION_FAILURE);
	if (ui_el_pref_modal_win(m, e, n))
		return (FUNCTION_FAILURE);
	return (ui_el_from_json_pos(m, w, e, n));
}

int			ui_el_from_json(t_ui_main *m, t_ui_win *w, t_jnode *n)
{
	t_ui_el	*p;
	t_ui_el	*e;
	t_jnode	*tmp;

	if (!(tmp = jtoc_node_get_by_path(n, "id")) || tmp->type != number)
		return (ui_sdl_log_error("NODE EL (ID)", -1));
	if (jtoc_get_int(tmp) == 0)
		ui_parse_canvas(m, w->canvas, n);
	else
	{
		if (!(e = ui_el_init()) ||
			((e->id = jtoc_get_int(tmp)) == 0) ||
			!(tmp = jtoc_node_get_by_path(n, "parent")) ||
			tmp->type != number ||
			!(p = ui_win_find_el_by_id(w, jtoc_get_int(tmp))))
			return (ui_sdl_log_error("NODE EL (INIT/NO PARENT)", e->id));
		ui_el_add_child(p, e);
		if (ui_el_from_json_params(m, w, e, n))
			return (FUNCTION_FAILURE);
	}
	return (FUNCTION_SUCCESS);
}
