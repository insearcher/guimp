cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

target_sources(guimp_cmake PUBLIC
        filler.c
        eraser.c
        zoom.c
        hand.c
        pipette.c
        line.c
        rect.c
        square.c
        ellipse.c
        modes.c
        brush.c
        )
