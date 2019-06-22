cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

target_sources(ui PUBLIC
        bfs_iter.c
        bfs_for_resize.c
        queue.c
        )