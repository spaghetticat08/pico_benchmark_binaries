add_executable(weatherstation
        weatherstation.c
        )

add_subdirectory(lcd_library)
add_subdirectory(bmp_library)

target_link_libraries(weatherstation
        pico_stdlib
        hardware_i2c
        lcd_library
        bmp_library
        )

pico_enable_stdio_usb(weatherstation 1)
pico_enable_stdio_uart(weatherstation 0)

pico_add_extra_outputs(weatherstation)