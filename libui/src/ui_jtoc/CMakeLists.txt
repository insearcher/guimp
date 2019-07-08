cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

target_sources(ui PUBLIC
        ui_main_from_json.c
        ui_win_from_json.c
        ui_el_from_json.c
        ui_el_get_and_setup_json.c
        ui_jtoc_utils.c
        ui_el_pref_text.c
        )