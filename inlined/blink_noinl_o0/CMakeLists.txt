add_executable(blink_noinl_o0
        blink_noinl_o0.c
        )

target_compile_options(blink_noinl_o0 PRIVATE
        -fno-inline
        -O0
        )

#target_compile_options(blink_noinl PRIVATE
#        -fdump-tree-all-graph   
#)

target_link_libraries(blink_noinl_o0 pico_stdlib)

pico_add_extra_outputs(blink_noinl_o0)