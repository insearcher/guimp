cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

target_sources(ui PUBLIC
        ui_event_init.c
        ui_event_add_listener.c
        ui_event_add_listener_front.c
        ui_event_clear.c
        ui_event_invoke.c
        ui_event_destroy.c
        )