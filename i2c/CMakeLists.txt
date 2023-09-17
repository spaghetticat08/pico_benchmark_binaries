add_executable(i2c_scanner
        i2c_scanner.c
        )

target_link_libraries(i2c_scanner
        pico_stdlib
        hardware_i2c
        )

pico_add_extra_outputs(i2c_scanner)