add_executable(Onewire)

target_sources(Onewire PRIVATE Onewire_temp.c)

add_subdirectory(onewire_library)

target_link_libraries(Onewire PRIVATE
    pico_stdlib
    hardware_pio
    onewire_library)


pico_enable_stdio_usb(Onewire 1)
pico_enable_stdio_uart(Onewire 0)
    
pico_add_extra_outputs(Onewire)

#example_auto_set_url(Onewire)