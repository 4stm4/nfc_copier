cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)
project(Pico_NFC_Copier)
pico_sdk_init()

add_subdirectory(lib/Config)
add_subdirectory(lib/LCD)
add_subdirectory(lib/Fonts)
add_subdirectory(lib/GUI)
add_subdirectory(modules)
include_directories(modules)
include_directories(./lib/Config)
include_directories(./lib/GUI)
include_directories(./lib/LCD)
add_executable(main 
main.c
)

# enable usb output, disable uart output
pico_enable_stdio_usb(main 0)
pico_enable_stdio_uart(main 1)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(main)

target_link_libraries(main modules LCD GUI Fonts Config pico_stdlib hardware_spi)
