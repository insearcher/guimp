#include "guimp_test.h"

void    el_text(t_guimp *guimp)
{
	t_ui_el *el;

	el = &guimp->el_text;
	ui_el_setup_default(el);
	ui_el_set_default_resize(el);
	ui_el_set_default_draggable(el);
	ui_el_add_child(&(guimp->w1.canvas), el);
	ui_el_set_pos(el, 0, PIXEL, (t_fvec2){220, 70});
	ui_el_set_size(el, 0, PIXEL, (t_fvec2){500, 100});
	el->id = 4;
	el->sdl_renderer = guimp->w1.sdl_renderer;
	ui_el_set_text(&guimp->m, el, "Neco",
			(t_text_params){(SDL_Color){255, 0, 0, 0}, (SDL_Color){0, 0, 0, 0}, 1, 0, 0});
	ui_el_update_text(el, "123456789");
	el->params |= EL_IS_DEPENDENT;
//	ui_el_update_text(el, "R");
}
