add_executable(blink_simple_d
        blink_simple_d.c
        )

target_compile_definitions(blink_simple_d PRIVATE
        PICO_DOUBLE_SUPPORT_ROM_V1=0        
)

target_compile_options(blink_simple_d PRIVATE
        -O0
        -fno-inline
        )

target_link_libraries(blink_simple_d pico_stdlib)

pico_add_extra_outputs(blink_simple_d)