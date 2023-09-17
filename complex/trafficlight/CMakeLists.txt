add_executable(trafficlight
        trafficlight.c
        )

target_link_libraries(trafficlight
        pico_stdlib
        )

pico_add_extra_outputs(trafficlight)