/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_menu1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:09:44 by sbecker           #+#    #+#             */
/*   Updated: 2019/06/12 06:13:14 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp_test.h"

void	add_elems_scroll_menu1(t_guimp *guimp, t_ui_el *scroll_menu)
{
	t_scroll_m_pref scroll_data;

	ui_el_setup_default_scroll_menu_elem(&guimp->scroll_menu1_el1, scroll_menu);
	ui_el_setup_default_scroll_menu_elem(&guimp->scroll_menu1_el2, scroll_menu);
	ui_el_setup_default_scroll_menu_elem(&guimp->scroll_menu1_el3, scroll_menu);
	ui_el_setup_default_scroll_menu_elem(&guimp->scroll_menu1_el4, scroll_menu);
	ui_el_setup_default_scroll_menu_elem(&guimp->scroll_menu1_el5, scroll_menu);
	ui_el_setup_default_scroll_menu_elem(&guimp->scroll_menu1_el6, scroll_menu);
	ui_el_setup_default_scroll_menu_elem(&guimp->scroll_menu1_el7, scroll_menu);
	ui_el_setup_default_scroll_menu_elem(&guimp->scroll_menu1_el8, scroll_menu);
	ui_el_setup_default_scroll_menu_elem(&guimp->scroll_menu1_el9, scroll_menu);
	ui_el_setup_default_scroll_menu_elem(&guimp->mogila_materi_pira, scroll_menu);
	scroll_data.type_pos = 0;
	scroll_data.begin_pos = (t_fvec2){0.0, 0};
	scroll_data.type_size = 0;
	scroll_data.size = (t_fvec2){1, 0.2};
	scroll_data.type_indent = PIXEL;
	scroll_data.indent = (t_fvec2){0, 2};
	scroll_data.params = 0;
	scroll_data.begin_id = scroll_menu->id * 1000;
	scroll_data.sdl_renderer = guimp->w1.sdl_renderer;
	scroll_data.texture = ft_strdup("fractal_dick");
	ui_prefab_scroll_menu(&guimp->m, 0, scroll_menu, &scroll_data);
	ui_el_set_text(&guimp->m, &guimp->scroll_menu1_el1, "Diablo",
			(t_text_params){(SDL_Color){0, 0, 0, 0}, (SDL_Color){0, 0, 0, 0}, 1, 0, 0});
	ui_el_set_text(&guimp->m, &guimp->scroll_menu1_el2, "Neco",
			(t_text_params){(SDL_Color){0, 0, 0, 0}, (SDL_Color){0, 0, 0, 0}, 1, 1, 0});
	ui_el_set_text(&guimp->m, &guimp->scroll_menu1_el3, "DumaBold",
			(t_text_params){(SDL_Color){0, 0, 0, 0}, (SDL_Color){0, 0, 0, 0}, 4, 0, 0});
	ui_el_set_text(&guimp->m, &guimp->scroll_menu1_el4, "HighTide",
			(t_text_params){(SDL_Color){0, 0, 0, 0}, (SDL_Color){0, 0, 0, 0}, 4, 0, 0});
	ui_el_set_text(&guimp->m, &guimp->scroll_menu1_el5, "BonkOffset",
			(t_text_params){(SDL_Color){0, 0, 0, 0}, (SDL_Color){0, 0, 0, 0}, 4, 0, 0});
	ui_el_set_text(&guimp->m, &guimp->scroll_menu1_el6, "BraveOldWorld",
			(t_text_params){(SDL_Color){0, 0, 0, 0}, (SDL_Color){0, 0, 0, 0}, 4, 0, 0});
	ui_el_set_text(&guimp->m, &guimp->scroll_menu1_el7, "BodoniTwinsCaps",
			(t_text_params){(SDL_Color){0, 0, 0, 0}, (SDL_Color){0, 0, 0, 0}, 4, 0, 0});
	ui_el_set_text(&guimp->m, &guimp->scroll_menu1_el8, "PeaceWarriors",
			(t_text_params){(SDL_Color){0, 0, 0, 0}, (SDL_Color){0, 0, 0, 0}, 4, 0, 0});
	ui_el_set_text(&guimp->m, &guimp->scroll_menu1_el9, "CavePaintings",
			(t_text_params){(SDL_Color){0, 0, 0, 0}, (SDL_Color){0, 0, 0, 0}, 4, 0, 0});
	ui_el_set_text(&guimp->m, &guimp->mogila_materi_pira, "Crosses",
			(t_text_params){(SDL_Color){0, 0, 0, 0}, (SDL_Color){0, 0, 0, 0}, 4, 0, 0});
	ui_el_update_text(&guimp->scroll_menu1_el1, "AB12|");
	ui_el_update_text(&guimp->scroll_menu1_el2, "123456789");
	ui_el_update_text(&guimp->scroll_menu1_el3, "AAAAAAAB12|");
	ui_el_update_text(&guimp->scroll_menu1_el4, "AB12|");
	ui_el_update_text(&guimp->scroll_menu1_el5, "AB12|");
	ui_el_update_text(&guimp->scroll_menu1_el6, "AB12|");
	ui_el_update_text(&guimp->scroll_menu1_el7, "AB12|");
	ui_el_update_text(&guimp->scroll_menu1_el8, "AB12|");
	ui_el_update_text(&guimp->scroll_menu1_el9, "AB12|");
	ui_el_update_text(&guimp->mogila_materi_pira, "pir pidor");
}

void	scroll_menu1(t_guimp *guimp)
{
	t_ui_el	*scroll_menu;

	scroll_menu = &guimp->scroll_menu1;
	ui_el_setup_default_scroll_menu(scroll_menu);
	ui_el_add_child(&(guimp->w1.canvas), scroll_menu);
	ui_el_set_menu_resize(scroll_menu);
	ui_el_set_default_draggable(scroll_menu);
	ui_el_set_pos(scroll_menu, 0, 0, (t_fvec2){0.6, 0.1});
	ui_el_set_size(scroll_menu, 0, 0, (t_fvec2){0.4, 0.8});
	scroll_menu->id = 1;
	scroll_menu->sdl_renderer = guimp->w1.sdl_renderer;
	ui_el_add_texture_from_main_by_id(&guimp->m, scroll_menu, "flower", "default");
	SDL_SetTextureColorMod((SDL_Texture *)(scroll_menu->sdl_textures->content), 255, 255, 255);
	add_elems_scroll_menu1(guimp, scroll_menu);
}
