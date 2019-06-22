cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

add_library(jtoc STATIC)

include_directories(
        include
        ../libft/include
)

add_subdirectory(src)