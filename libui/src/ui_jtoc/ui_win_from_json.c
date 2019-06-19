/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_from_json.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 18:19:27 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/19 18:05:56 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int	ui_get_win_param_from_string(const char *str)
{
	int	i;

	i = 0;
	i |= (ft_strcmp(str, "WIN_MAIN") ? WIN_MAIN : 0);
	i |= (ft_strcmp(str, "WIN_RESIZABLE") ? WIN_RESIZABLE : 0);
	return (i);
}

static t_ui_event		*ui_win_from_json_get_event_by_name(t_ui_win *w, const char *n)
{
	int			hash;
	t_ui_event	*res;

	hash = ft_strhash(n);
	res = NULL;
	res = (hash == ft_strhash("onPointerMoved") ? w->events->onPointerMoved : res);
	res = (hash == ft_strhash("onPointerLeftButtonPressed") ? w->events->onPointerLeftButtonPressed : res);
	res = (hash == ft_strhash("onPointerLeftButtonReleased") ? w->events->onPointerLeftButtonReleased : res);
	res = (hash == ft_strhash("onPointerRightButtonPressed") ? w->events->onPointerRightButtonPressed : res);
	res = (hash == ft_strhash("onPointerRightButtonReleased") ? w->events->onPointerRightButtonReleased : res);
	res = (hash == ft_strhash("onScrollUp") ? w->events->onScrollUp : res);
	res = (hash == ft_strhash("onScrollDown") ? w->events->onScrollDown : res);
	res = (hash == ft_strhash("onFocusGained") ? w->events->onFocusGained : res);
	res = (hash == ft_strhash("onFocusLost") ? w->events->onFocusLost : res);
	res = (hash == ft_strhash("onResize") ? w->events->onResize : res);
	res = (hash == ft_strhash("onClose") ? w->events->onClose : res);
	res = (hash == ft_strhash("onMoved") ? w->events->onMoved : res);
	return (res);
}

static int	ui_win_from_json_events(t_ui_main *m, t_ui_win *w, t_jnode *n)
{
	char		*event_name;
	char		*func_name;
	t_ui_event	*e;
	func_ptr	f;
	t_jnode		*tmp;

	n = n->down;
	while (n)
	{
		if (n->type != object ||
			!(tmp = jtoc_node_get_by_path(n, "event_name")) || tmp->type != string ||
			!(event_name  = jtoc_get_string(tmp)) ||
			!(e = ui_win_from_json_get_event_by_name(w, event_name)) ||
			!(tmp = jtoc_node_get_by_path(n, "func_name")) || tmp->type != string ||
			!(func_name  = jtoc_get_string(tmp)) ||
			!(f = ui_main_get_function_by_id(m, func_name)))
			return (FUNCTION_FAILURE);
		ui_event_add_listener(e, f);
		n = n->right;
	}
	return (FUNCTION_SUCCESS);
}

static int	ui_win_from_json_size(t_ui_main *m, t_ui_win *w, t_jnode *n)
{
	t_jnode	*tmp;

	if (!(tmp = jtoc_node_get_by_path(n, "size.x")) || tmp->type != number)
		return (FUNCTION_FAILURE);
	w->size.x = jtoc_get_int(tmp);
	if (!(tmp = jtoc_node_get_by_path(n, "size.y")) || tmp->type != number)
		return (FUNCTION_FAILURE);
	w->size.y = jtoc_get_int(tmp);
	ui_win_setup_default(w);
	ui_win_create(w);
	if (!(tmp = jtoc_node_get_by_path(n, "elements")))
		return (FUNCTION_FAILURE);
	tmp = tmp->down;
	while (tmp)
	{
		if (ui_el_from_json(m, w, tmp))
			return (FUNCTION_FAILURE);
		tmp = tmp->right;
	}
	return (FUNCTION_SUCCESS);
}

static int	ui_win_from_json_pos(t_ui_main *m, t_ui_win *w, t_jnode *n)
{
	t_jnode	*tmp;

	if (!(tmp = jtoc_node_get_by_path(n, "pos.x")) || tmp->type != number)
		return (FUNCTION_FAILURE);
	w->pos.x = jtoc_get_int(tmp);
	if (!(tmp = jtoc_node_get_by_path(n, "pos.y")))
		w->pos.y = SDL_WINDOWPOS_CENTERED;
	else
	{
		if (tmp->type != number)
			return (FUNCTION_FAILURE);
		w->pos.y = jtoc_get_int(tmp);
	}
	if (!(tmp = jtoc_node_get_by_path(n, "elements")))
		return (FUNCTION_FAILURE);
	return (ui_win_from_json_size(m, w, n));
}

int			ui_win_from_json(t_ui_main *m, t_jnode *n)
{
	t_ui_win	*w;
	t_jnode		*tmp;

	if (!(w = ui_win_init()) ||
		!(tmp = jtoc_node_get_by_path(n, "title")) || tmp->type != string ||
			!(w->title = ft_strdup(jtoc_get_string(tmp))))
		return (FUNCTION_FAILURE);
	if ((tmp = jtoc_node_get_by_path(n, "params")) &&
		(tmp = tmp->down))
		while (tmp)
		{
			if (tmp->type != string)
				return (FUNCTION_FAILURE);
			w->params |= ui_get_win_param_from_string(jtoc_get_string(tmp));
			tmp = tmp->right;
		}
	if (ui_win_from_json_pos(m, w, n))
		return (FUNCTION_FAILURE);
	ui_main_add_window(m, w);
	return (FUNCTION_SUCCESS);
}
