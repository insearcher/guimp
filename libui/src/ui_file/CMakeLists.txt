cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

target_sources(ui PUBLIC
        ui_open_file_dialog.c
        ui_save_file_dialog.c
        ui_parse_path.c
        ui_find_last_slash.c
        )