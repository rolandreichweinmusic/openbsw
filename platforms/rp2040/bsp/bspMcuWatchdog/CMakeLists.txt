add_library(bspMcuWatchdog src/watchdog/Watchdog.cpp)

target_include_directories(bspMcuWatchdog PUBLIC include)

target_link_libraries(
    bspMcuWatchdog
    PUBLIC platform pico-sdk
    PRIVATE bspInterrupts bspMcu)
