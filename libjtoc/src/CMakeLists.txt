cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

target_sources(jtoc PUBLIC
        jtoc_read_file.c
        jtoc_validate.c
        jtoc_validate_value.c
        jtoc_parse.c
        jtoc_parse_value.c
        jtoc_utils.c
        jtoc_node.c
        jtoc_read.c
        jtoc_get.c
        )