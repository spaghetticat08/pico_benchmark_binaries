add_executable(simple_math)

target_sources(simple_math PRIVATE simple_math.c)

add_subdirectory(math_library)

target_link_libraries(simple_math PRIVATE
    pico_stdlib
    math_library)

pico_add_extra_outputs(simple_math)