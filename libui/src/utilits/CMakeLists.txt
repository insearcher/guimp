cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

target_sources(ui PUBLIC
        ui_get_rect_from_frect.c
        ui_get_pixel_color_from_texture.c
        ui_get_pixel_color_from_el.c
        ui_set_pixel_color_to_texture.c
        )
