add_executable(blink_simple
        blink_simple.c
        )

target_compile_options(blink_simple PRIVATE
        -O0
        -fno-inline
        )

target_link_libraries(blink_simple pico_stdlib)

pico_add_extra_outputs(blink_simple)