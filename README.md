STM32F0DISCOVERY-FreeRTOS
=========================

This is a simple FreeRTOS template for STM32F0DISCOVERY board.

To build project use the GCC (arm-none-eabi) toolchain.

Just run:
`make`

and then run STLINK utility (https://github.com/texane/stlink) for flashing device in Linux platform.
`st-flash erase && st-flash write ./project.bin 0x8000000`
