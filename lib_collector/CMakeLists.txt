

add_executable(lib_collector lib_collector.c)

target_compile_options(lib_collector PRIVATE
        -O0
        -fno-inline
        )

target_link_libraries(lib_collector
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

