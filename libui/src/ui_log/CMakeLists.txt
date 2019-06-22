cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

target_sources(ui PUBLIC
        ui_log_mouse_motion.c
        ui_log_mouse_button_down.c
        ui_log_mouse_button_up.c
        ui_log_window_focus_gained.c
        ui_log_window_focus_lost.c
        ui_log_window_closed.c
        ui_log_window_resized.c
        ui_log_window_moved.c
        ui_log_el_pointer_stay.c
        ui_log_el_pointer_enter.c
        ui_log_el_pointer_exit.c
        ui_log_key_pressed.c
        ui_log_key_released.c
        ui_log_el_left_button_hold.c
        ui_log_el_left_button_pressed.c
        ui_log_el_left_button_released.c
        ui_log_el_right_button_hold.c
        ui_log_el_right_button_pressed.c
        ui_log_el_right_button_released.c
        ui_log_el_scroll_up.c
        ui_log_el_scroll_down.c
        )