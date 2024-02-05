add_executable(echo
        echo.c
        )

target_link_libraries(echo pico_stdlib)

pico_add_extra_outputs(echo)
