cmake_minimum_required(VERSION 3.20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(avr_blink C)

set(MCU atmega328p)
set(F_CPU 16000000UL)

add_executable(${PROJECT_NAME}.elf
    src/main.c
)

target_compile_definitions(${PROJECT_NAME}.elf PRIVATE F_CPU=${F_CPU})
target_compile_options(${PROJECT_NAME}.elf PRIVATE
    -mmcu=${MCU}
    -Os
    -ffunction-sections -fdata-sections
    -Wall -Wextra
    -gdwarf-2
)
target_link_options(${PROJECT_NAME}.elf PRIVATE
    -mmcu=${MCU}
    -Wl,--gc-sections
)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND avr-objcopy ${PROJECT_NAME}.elf -O ihex ${PROJECT_NAME}.hex -R .eeprom
    COMMAND avr-size --format=berkeley --target=ihex ${PROJECT_NAME}.elf
    BYPRODUCTS ${PROJECT_NAME}.hex
    COMMAND ${CMAKE_SIZE} --format=berkeley --target=ihex --totals $<TARGET_FILE:${PROJECT_NAME}.elf>
)
