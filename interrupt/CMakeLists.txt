add_executable(blink_irq
                blink_irq.c)

target_link_libraries(blink_irq pico_stdlib)

pico_add_extra_outputs(blink_irq)