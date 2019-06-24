cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

target_sources(ui PUBLIC
        ui_cursor_init.c
        ui_cursor_to_default.c
        ui_cursor_from_el_data.c
        ui_cursor_from.c
        )