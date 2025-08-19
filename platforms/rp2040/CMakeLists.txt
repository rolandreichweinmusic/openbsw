# 3rdparty modules
add_subdirectory(3rdparty/freertos_rp2040)
add_subdirectory(3rdparty/pico-sdk)

# BSP modules
add_subdirectory(bsp)

# Other modules
add_subdirectory(hardFaultHandler)
add_subdirectory(lwipSysArch)
