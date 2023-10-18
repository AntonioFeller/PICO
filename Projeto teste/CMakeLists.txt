
cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(int C CXX ASM) 

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_BOARD pico_w)

pico_sdk_init()

add_executable(int main.c)

target_link_libraries(int pico_cyw43_arch_none pico_stdlib)

pico_enable_stdio_usb(int 1)
pico_enable_stdio_uart(int 0)

pico_add_extra_outputs(int)