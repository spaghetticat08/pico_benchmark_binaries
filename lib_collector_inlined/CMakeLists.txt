add_executable(lib_collector_inlined lib_collector_inlined.c)

target_compile_options(lib_collector_inlined PRIVATE
        
        )

target_link_libraries(lib_collector_inlined
        pico_stdlib
        hardware_gpio
        hardware_i2c
        hardware_adc
        hardware_clocks
        hardware_dma
        hardware_irq
        hardware_rtc
        hardware_spi
        hardware_timer
        hardware_uart
        pico_multicore
        pico_time
        )

pico_add_extra_outputs(lib_collector_inlined)

