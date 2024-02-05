add_executable(blink_regs
        blink_regs.c
        )

target_link_libraries(blink_regs pico_stdlib)

pico_add_extra_outputs(blink_regs)

