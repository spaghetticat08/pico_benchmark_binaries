add_executable(blink_random
        blink_random.c
        )

target_link_libraries(blink_random pico_stdlib
                                pico_rand)

pico_add_extra_outputs(blink_random)

#example_auto_set_url(blink_random)
