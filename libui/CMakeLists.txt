cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

project(LIBUI VERSION 1.0.0 LANGUAGES C)

add_library(ui STATIC src/ui_el/ui_el_children_set_default.c)

set(${PROJECT_NAME}_INCLUDE_DIRS
        ${PROJECT_SOURCE_DIR}/include
        ${LIBFT_INCLUDE_DIRS}
        ${LIBJTOC_INCLUDE_DIRS}
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS}
        CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)

include_directories(${LIBUI_INCLUDE_DIRS})

add_subdirectory(src)