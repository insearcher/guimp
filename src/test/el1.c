#include "guimp_test.h"

void	el1(t_guimp *guimp)
{
	t_ui_el *el;

	el = &guimp->el1;
	ui_el_setup_default(el);
	ui_el_set_default_resize(el);
	ui_el_set_default_draggable(el);
	ui_el_add_child(&(guimp->w1.canvas), el);
	ui_el_set_pos(el, 0, PIXEL, (t_fvec2){10, 10});
	ui_el_set_size(el, 0, PIXEL, (t_fvec2){100, 100});
	el->id = 2;
	el->sdl_renderer = guimp->w1.sdl_renderer;
	ui_el_add_texture_from_main_by_id(&guimp->m, el, "bl", "default");
}
