# avr_blink
Example AVR CMake project

[AVR Toolchain](https://www.microchip.com/en-us/tools-resources/develop/microchip-studio/gcc-compilers) is required to build

## Build
```shell
cmake -S . -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE="cmake/avr-gcc-toolchain.cmake"
cmake --build build
```
