add_library(math_library INTERFACE)
target_sources(math_library INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/math_library.c)

target_include_directories(math_library INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    )