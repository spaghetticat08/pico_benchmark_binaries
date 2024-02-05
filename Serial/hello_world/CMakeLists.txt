add_executable(hello_world
        hello_world.c
        )

target_link_libraries(hello_world pico_stdlib)

pico_add_extra_outputs(hello_world)