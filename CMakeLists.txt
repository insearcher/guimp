cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

project(guimp VERSION 1.0.0 LANGUAGES C)

add_executable(guimp_cmake)

#target_link_libraries(guimp
#        "-framework SDL2"
#        "-framework SDL2_image"
#        "-framework SDL2_ttf"
#        "-framework OpenGL"
#        "-framework AppKit"
#        "-framework OpenCl"
#        )

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/sdl2-cmake-modules)

set_target_properties(guimp_cmake
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        )

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /Users/frolov/Education/21school/guimp)
#set(RUNTIME_OUTPUT_DIRECTORY /Users/frolov/Education/21school/guimp)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

#find_library(ObjC objc)
#find_library(CoreFoundation CoreFoundation)
#find_library(IOKit IOKit)
#target_link_libraries(guimp ${CoreFoundation} ${IOKit} ${ObjC})

#find_package(AudioUnit REQUIRED)
#include_directories(${AUDIOUNIT_INCLUDE_DIR})

#set_target_properties(guimp PROPERTIES LINK_FLAGS "-F/Users/frolov/Education/21school/guimp/frameworks")

include_directories(
        include
        libft/include
        libjtoc/include
        libui/include
        frameworks/SDL2.framework/Versions/A/Headers
        frameworks/SDL2_image.framework/Versions/A/Headers
        frameworks/SDL2_ttf.framework/Versions/A/Headers
)

add_subdirectory(src)

add_subdirectory(libft)
add_subdirectory(libjtoc)
add_subdirectory(libui)

target_link_libraries(guimp_cmake
        ft
        jtoc
        ui
        SDL2::Core
        SDL2::Main
        SDL2::Image
        SDL2::TTF)
#        ${SDL2}
#        ${SDL2_image}
#        ${SDL2_ttf}
#        ${OpenGL}
#        ${OpenCL}
#        ${AppKit}
#        ${CoreAudio}
#        ${AudioToolbox}
#        ${CoreFoundation}
#        ${CoreGraphics}
#        ${CoreVideo}
#        ${ForceFeedback}
#        ${IOKit}
#        ${Carbon}
#        ${FreeType})

install(TARGETS guimp_cmake DESTINATION .)