add_executable(lib_simple
        lib_simple.c
        )



target_link_libraries(lib_simple
        pico_stdlib
        )

pico+pico_add_extra_outputs(lib_simple)