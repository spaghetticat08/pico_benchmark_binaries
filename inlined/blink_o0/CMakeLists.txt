add_executable(blink_o0
        blink_o0.c
        )

target_compile_options(blink_o0 PRIVATE
        -O0
        )

#target_compile_options(blink_noinl PRIVATE
#        -fdump-tree-all-graph   
#)

target_link_libraries(blink_o0 pico_stdlib)

pico_add_extra_outputs(blink_o0)