cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

project(GUIMP VERSION 1.0.0 LANGUAGES C)

add_executable(guimp_cmake)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/sdl2-cmake-modules)

set_target_properties(guimp_cmake
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        )

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_subdirectory(libft)
add_subdirectory(libjtoc)
add_subdirectory(libui)

set(${PROJECT_NAME}_INCLUDE_DIRS
        ${PROJECT_SOURCE_DIR}/include)
include_directories(
        ${GUIMP_INCLUDE_DIRS}
        ${LIBUI_INCLUDE_DIRS}
)

add_subdirectory(src)

target_link_libraries(guimp_cmake
        ft
        jtoc
        ui
        SDL2::Core
        SDL2::Main
        SDL2::Image
        SDL2::TTF)

install(TARGETS guimp_cmake DESTINATION .)