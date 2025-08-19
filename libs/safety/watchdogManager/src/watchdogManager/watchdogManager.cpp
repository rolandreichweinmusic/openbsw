// Copyright 2024 Accenture.

#include "watchdogManager/watchdogManager.h"

#include "bsp/timer/SystemTimer.h"
#include "commonDebug.h"
#ifdef PLATFORM_SUPPORT_WATCHDOG
#include "mcu/mcu.h"
#include "watchdog/Watchdog.h"
#endif

namespace safety
{
bool WatchdogManager::startTest()
{
    return true;
}

bool WatchdogManager::isWDFastTestLow()
{
#ifdef PLATFORM_SUPPORT_WATCHDOG
#if 0
    return (WDOG->CS & WDOG_CS_TST_MASK) == WDOG_CS_TST(0x02U);
#endif
#endif
    return false;
}

bool WatchdogManager::isWDFastTestHigh()
{
#ifdef PLATFORM_SUPPORT_WATCHDOG
#if 0
    return (WDOG->CS & WDOG_CS_TST_MASK) == WDOG_CS_TST(0x03U);
#endif
#endif
    return false;
}
} // namespace safety
