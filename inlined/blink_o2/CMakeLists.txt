add_executable(blink_o2
        blink_o2.c
        )

target_compile_options(blink_o2 PRIVATE
        -O2
        )

#target_compile_options(blink_noinl PRIVATE
#        -fdump-tree-all-graph   
#)

target_link_libraries(blink_o2 pico_stdlib)

pico_add_extra_outputs(blink_o2)