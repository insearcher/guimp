/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_from_json.1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 18:47:42 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/19 01:41:34 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int	ui_get_el_param_from_string(const char *str)
{
	int	i;

	i = 0;
	i |= (ft_strcmp(str, "EL_IGNOR_RAYCAST") ? EL_IGNOR_RAYCAST : 0);
	i |= (ft_strcmp(str, "EL_IS_HIDDEN") ? EL_IS_HIDDEN : 0);
	i |= (ft_strcmp(str, "EL_IS_SCROLLABLE") ? EL_IS_SCROLLABLE : 0);
	i |= (ft_strcmp(str, "EL_IS_DEPENDENT") ? EL_IS_DEPENDENT : 0);
	return (i);
}

static int	ui_get_pos_size(const char *str)
{
	int	i;

	i = 0;
	i |= (ft_strcmp(str, "ABS") ? ABS: 0);
	i |= (ft_strcmp(str, "PIXEL") ? PIXEL : 0);
	return (i);
}

static int	ui_el_setup_by_type(t_ui_el *e, t_jnode *n)
{
	int		hash;
	t_jnode	*tmp;

	ui_el_setup_default(e);
	if ((tmp = jtoc_node_get_by_path(n, "type")))
	{
		tmp = tmp->down;
		while (tmp)
		{
			if (tmp->type != string)
				return (FUNCTION_FAILURE);
			hash = ft_strhash(jtoc_get_string(tmp));
			(hash == ft_strhash("DRAGGABLE") ? ui_el_setup_default_draggable(e) : 0);
			(hash == ft_strhash("RESIZE") ? ui_el_setup_default_resize(e) : 0);
			(hash == ft_strhash("SCROLL_MENU_ELEM") ? ui_el_setup_default_scroll_menu_elem(e) : 0);
			(hash == ft_strhash("SCROLL_MENU") ? ui_el_setup_default_scroll_menu(e) : 0);
			(hash == ft_strhash("HOR_DRAGGABLE") ? ui_el_setup_hor_draggable(e) : 0);
			(hash == ft_strhash("MENU_RESIZE") ? ui_el_setup_menu_resize(e) : 0);
			tmp = tmp->right;
		}
	}
	return (FUNCTION_SUCCESS);
}

static int	ui_el_from_json_texture(t_ui_main *m, t_ui_el *e, t_jnode *n)
{
	t_jnode	*tmp;
	char	*main_id;
	char	*el_id;

	if (!(tmp = jtoc_node_get_by_path(n, "main_id")) || tmp->type != string ||
		!(main_id = jtoc_get_string(tmp)) ||
		!(tmp = jtoc_node_get_by_path(n, "el_id")) || tmp->type != string ||
		!(el_id = jtoc_get_string(tmp)))
		return (FUNCTION_FAILURE);
	ui_el_add_texture_from_main_by_id(m, e, main_id, el_id);
	return (FUNCTION_SUCCESS);
}

t_ui_event		*ui_el_from_json_get_event_by_name(t_ui_el *e, const char *n)
{
	int			hash;
	t_ui_event	*res;

	hash = ft_strhash(n);
	res = NULL;
	res = (hash == ft_strhash("onPointerEnter") ? &e->events->onPointerEnter : res);
	res = (hash == ft_strhash("onPointerStay") ? &e->events->onPointerStay : res);
	res = (hash == ft_strhash("onPointerExit") ? &e->events->onPointerExit : res);
	res = (hash == ft_strhash("onPointerLeftButtonPressed") ? &e->events->onPointerLeftButtonPressed : res);
	res = (hash == ft_strhash("onPointerLeftButtonHold") ? &e->events->onPointerLeftButtonHold : res);
	res = (hash == ft_strhash("onPointerLeftButtonReleased") ? &e->events->onPointerLeftButtonReleased : res);
	res = (hash == ft_strhash("onPointerRightButtonPressed") ? &e->events->onPointerRightButtonPressed : res);
	res = (hash == ft_strhash("onPointerRightButtonHold") ? &e->events->onPointerRightButtonHold : res);
	res = (hash == ft_strhash("onPointerRightButtonReleased") ? &e->events->onPointerRightButtonReleased : res);
	res = (hash == ft_strhash("onScrollUp") ? &e->events->onScrollUp : res);
	res = (hash == ft_strhash("onScrollDown") ? &e->events->onScrollDown : res);
	res = (hash == ft_strhash("onRender") ? &e->events->onRender : res);
	res = (hash == ft_strhash("onResize") ? &e->events->onResize : res);
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

static int	ui_el_from_json_event(t_ui_el *e, t_jnode *n)
{
	t_jnode		*tmp;
	char		*name;
	t_ui_event	*ev;
	// func_ptr	f;

	if (!(tmp = jtoc_node_get_by_path(n, "name")) || tmp->type != string ||
		!(name = jtoc_get_string(tmp)) ||
		!(ev = ui_el_from_json_get_event_by_name(e, name)) ||
		!(tmp = jtoc_node_get_by_path(n, "functions")) || tmp->type != array)
		return (FUNCTION_FAILURE);
	tmp = tmp->down;
	while (tmp)
	{
		// if (tmp->type != string || !(name = jtoc_get_string(tmp)) ||
		// 	!(f = ui_el_from_json_get_function_by_name(name)))
		// 	return (FUNCTION_FAILURE);
		// ui_event_add_listener(ev, f);
		tmp = tmp->right;
	}
	return (FUNCTION_SUCCESS);
}

static int	ui_el_from_json_events(t_ui_el *e, t_jnode *n)
{
	t_jnode	*tmp;

	if ((tmp = jtoc_node_get_by_path(n, "events")))
	{
		tmp = tmp->down;
		while (tmp)
		{
			if (tmp->type != object || ui_el_from_json_event(e, tmp))
				return (FUNCTION_FAILURE);
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
	return (ui_el_from_json_events(e, n));
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

	if (!(tmp = jtoc_node_get_by_path(n, "size.x")) || tmp->type != number ||
		(x = jtoc_get_float(tmp)) ||
		!(tmp = jtoc_node_get_by_path(n, "size.y")) || tmp->type != number ||
		(y = jtoc_get_float(tmp)))
		return (FUNCTION_FAILURE);
	p = 0;
	if ((tmp = jtoc_node_get_by_path(n, "size.params")))
	{
		tmp = tmp->down;
		while (tmp)
		{
			if (tmp->type != string)
				return (FUNCTION_FAILURE);
			p |= ui_get_pos_size(jtoc_get_string(tmp));
			tmp = tmp->right;
		}
		ui_el_set_size(e, w->canvas, p, (t_fvec2){x, y});
	}
	return (ui_el_from_json_textures(m, e, n));
}

static int	ui_el_from_json_pos(t_ui_main *m, t_ui_win *w, t_ui_el *e, t_jnode *n)
{
	float	x;
	float	y;
	int		p;
	t_jnode	*tmp;

	if (!(tmp = jtoc_node_get_by_path(n, "pos.x")) || tmp->type != number)
		return (FUNCTION_FAILURE);
	x = jtoc_get_float(tmp);
	if (!(tmp = jtoc_node_get_by_path(n, "pos.y")) || tmp->type != number)
		return (FUNCTION_FAILURE);
	y = jtoc_get_float(tmp);
	p = 0;
	if ((tmp = jtoc_node_get_by_path(n, "pos.params")))
	{
		tmp = tmp->down;
		while (tmp)
		{
			if (tmp->type != string)
				return (FUNCTION_FAILURE);
			p |= ui_get_pos_size(jtoc_get_string(tmp));
			tmp = tmp->right;
		}
	}
	ui_el_set_pos(e, w->canvas, p, (t_fvec2){x, y});
	return (ui_el_from_json_size(m, w, e, n));
}

static int	ui_el_from_json_params(t_ui_main *m, t_ui_win *w, t_ui_el *e, t_jnode *n)
{
	t_jnode	*tmp;

	if (!(tmp = jtoc_node_get_by_path(n, "params")))
		return (FUNCTION_FAILURE);
	tmp = tmp->down;
	while (tmp)
	{
		if (tmp->type != string)
			return (FUNCTION_FAILURE);
		e->params |= ui_get_el_param_from_string(jtoc_get_string(tmp));
		tmp = tmp->right;
	}
	if (ui_el_setup_by_type(e, n))
		return (FUNCTION_FAILURE);
	return (ui_el_from_json_pos(m, w, e, n));
}

int			ui_el_from_json(t_ui_main *m, t_ui_win *w, t_jnode *n)
{
	t_ui_el	*p;
	t_ui_el	*e;
	t_jnode	*tmp;

	if (!(e = (t_ui_el *)malloc(sizeof(t_ui_el))) ||
		!(tmp = jtoc_node_get_by_path(n, "id")) || tmp->type != number)
		return (FUNCTION_FAILURE);
	ui_el_init(e);
	if ((e->id = jtoc_get_int(tmp)) == 0)
		ui_parse_canvas(m, e, n);
	else
	{
		if (!(tmp = jtoc_node_get_by_path(n, "parent")) ||
			tmp->type != number ||
			!(p = ui_win_find_el_by_id(w, jtoc_get_int(tmp))))
			return (FUNCTION_FAILURE);
		ui_el_add_child(p, e);
		if (ui_el_from_json_params(m, w, e, n))
			return (FUNCTION_FAILURE);
	}
	return (FUNCTION_SUCCESS);
}
