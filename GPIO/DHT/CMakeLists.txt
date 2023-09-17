add_executable(DHT_sensor
        DHT_sensor.c
        )

target_link_libraries(DHT_sensor pico_stdlib)

pico_add_extra_outputs(DHT_sensor)