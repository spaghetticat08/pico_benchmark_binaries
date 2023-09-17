add_executable(smartdoor
        smartdoor.c
        )

target_link_libraries(smartdoor
        pico_stdlib
        )
    
pico_add_extra_outputs(smartdoor)