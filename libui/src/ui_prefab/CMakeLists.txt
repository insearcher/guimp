cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

target_sources(ui PUBLIC
        ui_prefab_scroll_menu.c
        ui_prefab_get_pixel_pos.c
        ui_prefab_get_pixel_size.c
        )