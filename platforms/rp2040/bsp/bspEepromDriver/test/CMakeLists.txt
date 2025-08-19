add_executable(bspEepromDriverTestRp2040 src/IncludeTest.cpp)

target_include_directories(bspEepromDriverTestRp2040 PRIVATE ../include)

target_link_libraries(bspEepromDriverTestRp2040 PRIVATE gtest_main bspIo
                                                        utbspMcu util)

gtest_discover_tests(bspEepromDriverTestRp2040
                     PROPERTIES LABELS "bspEepromDriverTestRp2040")
