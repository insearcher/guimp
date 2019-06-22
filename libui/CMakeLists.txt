cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

add_library(ui STATIC)

include_directories(
        include
        ../libft/include
        ../libjtoc/include
        ../frameworks/SDL2.framework/Versions/A/Headers
        ../frameworks/SDL2_image.framework/Versions/A/Headers
        ../frameworks/SDL2_ttf.framework/Versions/A/Headers
        )

add_subdirectory(src)