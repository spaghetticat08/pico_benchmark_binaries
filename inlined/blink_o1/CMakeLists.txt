add_executable(blink_o1
        blink_o1.c
        )

target_compile_options(blink_o1 PRIVATE
        -O1
        )

#target_compile_options(blink_noinl PRIVATE
#        -fdump-tree-all-graph   
#)

target_link_libraries(blink_o1 pico_stdlib)

pico_add_extra_outputs(blink_o1)