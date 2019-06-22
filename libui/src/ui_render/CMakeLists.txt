cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

target_sources(ui PUBLIC
        ui_draw.c
        ui_draw_window.c
        ui_draw_windows.c
        ui_clear_windows.c
        ui_show_window.c
        ui_show_windows.c
        )