add_subdirectory(src/boot_stage2)

add_library(
    pico-sdk
    OBJECT
    src/bit_ops_aeabi.S
    src/bootrom.cpp
    src/claim.cpp
    src/clocks.cpp
    src/crt0.S
    src/divider_hardware.S
    src/double_aeabi_rp2040.S
    src/double_init_rom_rp2040.cpp
    src/double_v1_rom_shim_rp2040.S
    src/exception.cpp
    src/exit.cpp
    src/float_aeabi_rp2040.S
    src/float_init_rom_rp2040.cpp
    src/float_v1_rom_shim_rp2040.S
    src/gpio.cpp
    src/irq.cpp
    src/irq_handler_chain.S
    src/lock_core.cpp
    src/mem_ops_aeabi.S
    src/mutex.cpp
    src/newlib_interface.cpp
    src/panic.cpp
    src/pico_int64_ops_aeabi.S
    src/pll.cpp
    src/printf.cpp
    src/runtime.cpp
    src/runtime_init.cpp
    src/runtime_init_clocks.cpp
    src/standard_binary_info.cpp
    src/stdio.cpp
    src/stdio_uart.cpp
    src/sync.cpp
    src/sync_spin_lock.cpp
    src/ticks.cpp
    src/time.cpp
    src/timer.cpp
    src/uart.cpp
    src/watchdog.cpp
    src/xosc.cpp
)

#target_link_libraries(
#    pico-sdk
#    PUBLIC
#    main
#)

target_include_directories(
    pico-sdk PUBLIC include)

target_compile_definitions(pico-sdk PUBLIC
    PICO_NO_HARDWARE=0
    PICO_ON_DEVICE=1
    PICO_BUILD=1
    PICO_RP2040=1
    PICO_32BIT=1
    LIB_PICO_CLIB_INTERFACE=1
    LIB_PICO_CRT0=1
    LIB_PICO_CLIB_INTERFACE=1
    LIB_PICO_CRT0=1
    LIB_PICO_STDIO_UART=1
    LIB_PICO_PRINTF=1
    LIB_PICO_PRINTF_PICO=1
    LIB_PICO_RUNTIME=1
    LIB_PICO_RUNTIME_INIT=1
    LIB_PICO_STDIO=1
    LIB_PICO_STDIO_UART=1
    LIB_PICO_STDLIB=1
    LIB_PICO_UTIL=1
    LIB_PICO_NEWLIB_INTERFACE=1
    LIB_PICO_PLATFORM=1
    LIB_PICO_PLATFORM_COMMON=1
    LIB_PICO_PLATFORM_COMPILER=1
    PICO_BOARD=\"pico\"
)

add_library(pico-interface INTERFACE)

target_include_directories(
    pico-interface INTERFACE include)

target_compile_definitions(pico-interface INTERFACE
    PICO_NO_HARDWARE=0
    PICO_ON_DEVICE=1
    PICO_BUILD=1
    PICO_RP2040=1
    PICO_32BIT=1
    LIB_PICO_CLIB_INTERFACE=1
    LIB_PICO_CRT0=1
    LIB_PICO_STDIO_UART=1
    LIB_PICO_PRINTF=1
    LIB_PICO_PRINTF_PICO=1
    LIB_PICO_RUNTIME=1
    LIB_PICO_RUNTIME_INIT=1
    LIB_PICO_STDIO=1
    LIB_PICO_STDIO_UART=1
    LIB_PICO_STDLIB=1
    LIB_PICO_UTIL=1
    LIB_PICO_NEWLIB_INTERFACE=1
    LIB_PICO_PLATFORM=1
    LIB_PICO_PLATFORM_COMMON=1
    LIB_PICO_PLATFORM_COMPILER=1
    PICO_BOARD=\"pico\"
)
