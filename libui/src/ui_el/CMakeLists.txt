cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

target_sources(ui PUBLIC
        ui_el_add_child.c
        ui_el_init.c
        ui_el_create_texture.c
        ui_el_load_surface_from.c
        ui_el_set_current_texture_by_id.c
        ui_el_add_texture.c
        ui_el_create_texture.c
        ui_el_create_texture_from_surface.c
        ui_el_get_current_texture.c
        ui_el_default_pointer_enter.c
        ui_el_default_pointer_exit.c
        ui_el_resize_elems.c
        ui_el_get_texture_by_id.c
        ui_el_drag.c
        ui_el_scroll_menu.c
        ui_el_set_texture.c
        ui_el_set_text.c
        ui_el_update_text.c
        ui_el_change_pos.c
        ui_el_change_size.c
        ui_el_add_texture_from_main_by_id.c
        ui_el_set_pos.c
        ui_el_set_size.c
        ui_el_default_resize.c
        ui_el_menu_resize.c
        ui_el_set_new_pos.c
        ui_el_set_new_size.c
        ui_el_add_texture_from_file_dialog.c
        ui_el_setup_default_draggable.c
        ui_el_setup_default_resizable.c
        ui_el_setup_default_scroll_menu_elem.c
        ui_el_setup_default_scroll_menu.c
        ui_el_setup_default.c
        ui_el_setup_horizontal_draggable.c
        ui_el_setup_menu_resizable.c
        ui_el_show_child.c
        ui_el_children_set_default.c
        )