// Copyright 2024 Accenture.

#pragma once

#include <platform/estdint.h>

namespace safety
{

class SafetyManager
{
public:
    SafetyManager();
    void init();
    void run();
    void shutdown();
    void cyclic();

private:
    uint32_t _counter;
    uint32_t const WATCHDOG_CYCLIC_COUNTER = 8;
};

} // namespace safety
