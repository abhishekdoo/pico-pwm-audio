# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(PICO_BOARD pico_w)
set(WIFI_SSID "Airtel_abhi_home")
set(WIFI_PASSWORD "504296504296")

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
# set(PICO_SDK_PATH "/YOUR_PICO_SDK_PATH/pico-sdk")

# Pull in Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(pico-pwm-audio C CXX ASM)

set(PICO_CXX_ENABLE_EXCEPTIONS 1)

set(PICO_CXX_ENABLE_RTTI 1)

# Initialise the Pico SDK
pico_sdk_init()

#aux_source_directory(. DIR_SRCS)

# Add executable. Default name is the project name, version 0.1

add_executable(pico-pwm-audio ${DIR_SRCS}
#        "src/audio.cpp"
        "picow_tcp_server.c"       
)

include_directories(pico-pwm-audio 
        "./"
        "./src"
)

add_subdirectory(lib/no-OS-FatFS-SD-SPI-RPi-Pico/FatFs_SPI build)

pico_set_program_name(pico-pwm-audio "pico-pwm-audio")
pico_set_program_version(pico-pwm-audio "0.1")

# Add the standard library to the build
target_link_libraries(pico-pwm-audio pico_stdlib)

# Add any user requested libraries
target_link_libraries(pico-pwm-audio
        pico_cyw43_arch_lwip_poll
        hardware_dma
        hardware_pio
        hardware_timer
        hardware_clocks
        hardware_pwm
        hardware_spi
        FatFs_SPI
        )

pico_enable_stdio_usb(pico-pwm-audio 1)
pico_enable_stdio_uart(pico-pwm-audio 0)

pico_add_extra_outputs(pico-pwm-audio)

