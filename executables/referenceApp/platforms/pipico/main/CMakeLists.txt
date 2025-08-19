add_library(
    startUp
    src/bsp/bootHeader.S
    src/bsp/startUp.S
    src/os/isr/isr_can.cpp
    src/os/isr/isr_erm.cpp
    src/os/isr/isr_ftfc.cpp
    src/os/isr/isr_sys.cpp
    src/os/isr/isr_wdg.cpp)

target_link_libraries(startUp PRIVATE bspMcu common hardFaultHandler)

add_library(main src/systems/BspSystem.cpp src/lifecycle/StaticBsp.cpp
                 src/main.cpp)

if (PLATFORM_SUPPORT_CAN)
    target_sources(main PRIVATE src/systems/CanSystem.cpp)
    target_link_libraries(main PRIVATE canTransceiver)
endif ()

target_include_directories(main PUBLIC include)

target_link_libraries(
    main
    PRIVATE asyncConsole
            bsp
            bspClock
            bspCore
            bspSci
            safeBspMcuWatchdog
            configuration
            etl
            freeRtosRP2040
            lifecycle
            startUp
            safeLifecycle
            safeSupervisor
            safeWatchdog
    PUBLIC pico-interface bspInputManager bspOutputManager)

add_library(osHooks src/osHooks.cpp)

target_include_directories(osHooks PRIVATE include)

target_link_libraries(osHooks PRIVATE common freeRtosRP2040)

set_target_properties(
    startUp
    PROPERTIES PROP_LINKER_SCRIPT
               "${CMAKE_CURRENT_SOURCE_DIR}/linkerscript/application.dld")
set_target_properties(
    startUp
    PROPERTIES LINK_DEPENDS
               "${CMAKE_CURRENT_SOURCE_DIR}/linkerscript/application.dld")
