cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

target_sources(ui PUBLIC
        ui_main_loop.c
        ui_main_init.c
        ui_main_add_window.c
        ui_main_closing_windows.c
        ui_main_handle_event.c
        ui_main_handle_mouse_event.c
        ui_main_handle_window_event.c
        ui_main_find_window_by_id.c
        ui_main_handle_keyboard_event.c
        ui_main_handle_raycast.c
        ui_main_handle_continious_event.c
        ui_main_lmb_pressed.c
        ui_main_lmb_released.c
        ui_main_rmb_pressed.c
        ui_main_rmb_released.c
        ui_main_scroll_up.c
        ui_main_scroll_down.c
        ui_main_pointer_moved.c
        ui_main_add_font_by_path.c
        ui_main_add_surface_by_path.c
        ui_main_get_font_by_id.c
        ui_main_get_surface_by_id.c
        ui_main_fill_default_surfaces.c
        ui_main_fill_default_fonts.c
        ui_main_set_font_params.c
        ui_main_add_function_by_id.c
        ui_main_get_function_by_id.c
        ui_main_add_window_opener_el.c
        )