/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_el_get_and_setup_json.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:40:39 by sbednar           #+#    #+#             */
/*   Updated: 2019/07/08 23:15:16 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_ui_event		*ui_win_from_json_get_event_by_name(t_ui_win *w, const char *n)
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

int				ui_get_el_param_from_string(const char *str)
{
	int	hash;
	int	i;

	hash = ft_strhash(str);
	i = 0;
	i |= (hash == ft_strhash("EL_IGNOR_RAYCAST") ? EL_IGNOR_RAYCAST : 0);
	i |= (hash == ft_strhash("EL_IS_HIDDEN") ? EL_IS_HIDDEN : 0);
	i |= (hash == ft_strhash("EL_IS_SCROLLABLE") ? EL_IS_SCROLLABLE : 0);
	i |= (hash == ft_strhash("EL_IS_DEPENDENT") ? EL_IS_DEPENDENT : 0);
	i |= (hash == ft_strhash("EL_IS_ICON") ? EL_IS_ICON : 0);
	return (i);
}

int	ui_get_pos_size(const char *str)
{
	int	hash;
	int	i;

	hash = ft_strhash(str);
	i = 0;
	i |= (hash == ft_strhash("ABS") ? ABS: 0);
	i |= (hash == ft_strhash("PIXEL") ? PIXEL : 0);
	return (i);
}

int	ui_el_pref_modal_win(t_ui_main *m, t_ui_el *e, t_jnode *n)
{
	//	int		hash;
	t_jnode	*tmp;

	e->id = e->id;
	m->params = m->params;
	if ((tmp = jtoc_node_get_by_path(n, "modal_win")))
	{
		tmp = tmp->down;
		while (tmp)
		{
			if ((tmp = jtoc_node_get_by_path(n, "modal_win.text")) && tmp->type == string)
				SDL_Log("NAAAAICE WIN\n");
			tmp = tmp->right;
		}
	}
	return (FUNCTION_SUCCESS);
}

int	ui_el_setup_by_type(t_ui_el *e, t_jnode *n)
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
				ui_sdl_deinit(228);
			hash = ft_strhash(jtoc_get_string(tmp));
			(hash == ft_strhash("DRAGGABLE") ? ui_el_setup_default_draggable(e) : 0);
			(hash == ft_strhash("RESIZABLE") ? ui_el_setup_default_resizable(e) : 0);
			(hash == ft_strhash("SCROLL_MENU_ELEM") ? ui_el_setup_default_scroll_menu_elem(e) : 0);
			(hash == ft_strhash("SCROLL_MENU") ? ui_el_setup_default_scroll_menu(e) : 0);
			(hash == ft_strhash("HORIZONTAL_DRAGGABLE") ? ui_el_setup_horizontal_draggable(e) : 0);
			(hash == ft_strhash("MENU_RESIZABLE") ? ui_el_setup_menu_resizable(e) : 0);
			tmp = tmp->right;
		}
	}
	return (FUNCTION_SUCCESS);
}

int	ui_get_win_param_from_string(const char *str)
{
	int	i;

	i = 0;
	i |= ((ft_strcmp(str, "WIN_RESIZABLE") == 0) ? WIN_RESIZABLE : 0);
	return (i);
}
