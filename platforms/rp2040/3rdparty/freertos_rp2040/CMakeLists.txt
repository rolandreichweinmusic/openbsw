add_library(freeRtosRP2040Port INTERFACE)

target_include_directories(freeRtosRP2040Port INTERFACE include)

target_link_libraries(
    freeRtosRP2040Port
    INTERFACE pico-sdk
)

add_library(freeRtosRP2040 src/port.c)

target_include_directories(freeRtosRP2040 PUBLIC include)

target_link_libraries(
    freeRtosRP2040
    PUBLIC freeRtos pico-sdk bspMcu
    PRIVATE bspInterrupts)

target_compile_options(freeRtosRP2040 PRIVATE -Wno-unused-but-set-variable)
