add_executable(
    main
    bit_ops_aeabi.S
    blink.cpp
    bootrom.cpp
    claim.cpp
    clocks.cpp
    crt0.S
    divider_hardware.S
    double_aeabi_rp2040.S
    double_init_rom_rp2040.cpp
    double_v1_rom_shim_rp2040.S
    exit.cpp
    float_aeabi_rp2040.S
    float_init_rom_rp2040.cpp
    float_v1_rom_shim_rp2040.S
    gpio.cpp
    irq.cpp
    irq_handler_chain.S
    lock_core.cpp
    mem_ops_aeabi.S
    mutex.cpp
    newlib_interface.cpp
    panic.cpp
    pico_int64_ops_aeabi.S
    pll.cpp
    printf.cpp
    runtime.cpp
    runtime_init.cpp
    runtime_init_clocks.cpp
    standard_binary_info.cpp
    stdio.cpp
    stdio_uart.cpp
    sync.cpp
    sync_spin_lock.cpp
    ticks.cpp
    time.cpp
    timer.cpp
    uart.cpp
    xosc.cpp
    )

target_link_libraries(
    main
    PRIVATE pico boot_stage2_library
)

set_target_properties(
    main
    PROPERTIES PROP_LINKER_SCRIPT main.dld)

set_target_properties(
    main
    PROPERTIES LINK_DEPENDS ${CMAKE_CURRENT_LIST_DIR}/main.dld)

target_link_options(main PRIVATE -T ${CMAKE_CURRENT_LIST_DIR}/main.dld)
