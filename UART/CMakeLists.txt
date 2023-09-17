add_executable(echo
        echo.c
)

target_link_libraries(echo pico_sdtlib)

pico_add_extra_outputs(echo)

