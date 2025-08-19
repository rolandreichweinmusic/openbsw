# The 3rdparty pico-sdk, the FreeRTOS port and the startup code are Cortex-M0+
# only, so they are left out of the host unit test build.
if (NOT BUILD_EXECUTABLE STREQUAL "unitTest")
    # 3rdparty modules
    add_subdirectory(3rdparty/freertos_rp2040)
    add_subdirectory(3rdparty/pico-sdk)

    # Safety modules
    add_subdirectory(safety)

    # ETL implementation
    add_subdirectory(etlImpl)

    # Other modules
    add_subdirectory(hardFaultHandler)
    add_subdirectory(lwipSysArch)
endif ()

# BSP modules
add_subdirectory(bsp)
