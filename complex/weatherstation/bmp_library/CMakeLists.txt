add_library(bmp_library INTERFACE)

target_sources(bmp_library INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/bmp280_i2c.c)

target_link_libraries(bmp_library INTERFACE
        pico_stdlib
        hardware_i2c
        )

target_include_directories(bmp_library INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    )