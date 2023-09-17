add_library(lcd_library INTERFACE)

target_sources(lcd_library INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/lcd_1602_i2c.c)

target_link_libraries(lcd_library INTERFACE
        pico_stdlib
        hardware_i2c
        )

target_include_directories(lcd_library INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
        )