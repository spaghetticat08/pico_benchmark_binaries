add_executable(blink_multi
        blink_multi.c
        )

target_link_libraries(blink_multi pico_stdlib)

pico_add_extra_outputs(blink_multi)

example_auto_set_url(blink_multi)
