// Copyright 2024 Accenture.

#include "reset/softwareSystemReset.h"

#include "mcu/mcu.h"
#include "hardware/watchdog.h"

extern "C"
{
[[noreturn]] void softwareSystemReset(void)
{
    watchdog_reboot(0, 0, 0);
    while(true);
}

void softwareDestructiveReset(void) { softwareSystemReset(); }
}
