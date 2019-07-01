cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

target_sources(guimp_cmake PUBLIC
        main.c
        draw_func.c
        draw_main_canvas_event.c
        draw_with_selected_tool.c
        gm_init.c
        ui_main_fill_default_functions.c
        gm_generate_surfaces_id.c
        draw_fat_line.c
        )
