add_executable(blink_conditional
        blink_conditional.c
        )

# add pico stdlib libraries with commonly used functionality
target_link_libraries(blink_conditional pico_stdlib
                                        pico_rand)

# create map/bin/hex/uf2 file in addition to ELF
pico_add_extra_outputs(blink_conditional)

# TODO: need to check what this does and if we need it
# Optional: add url via pico_set_program_url 
#example_auto_set_url(blink_pin)
