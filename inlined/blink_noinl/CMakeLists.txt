add_executable(blink_noinl
        blink_noinl.c
        )

target_compile_options(blink_noinl PRIVATE
        -fno-inline
        )

#target_compile_options(blink_noinl PRIVATE
#        -fdump-tree-all-graph   
#)

target_link_libraries(blink_noinl pico_stdlib)

pico_add_extra_outputs(blink_noinl)