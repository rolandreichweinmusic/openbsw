// Copyright 2024 Accenture.

#include "watchdog/Watchdog.h"

#include <interrupts/SuspendResumeAllInterruptsScopedLock.h>
#include <mcu/mcu.h>
#include <hardware/watchdog.h>

namespace bsp
{
uint32_t Watchdog::watchdogServiceCounter = 0;

void Watchdog::enableWatchdog(
    uint32_t const timeout, bool const interruptActive, uint32_t const clockSpeed)
{
    ESR_UNUSED const interrupts::SuspendResumeAllInterruptsScopedLock lock;
    watchdog_enable(timeout, 1);
}

void Watchdog::disableWatchdog()
{
    ESR_UNUSED const interrupts::SuspendResumeAllInterruptsScopedLock lock;
    watchdog_disable();
}

void Watchdog::serviceWatchdog()
{
    ESR_UNUSED const interrupts::SuspendResumeAllInterruptsScopedLock lock;
    watchdogServiceCounter++;
    watchdog_update();
}

void Watchdog::startFastTestLow()
{
#if 0
    ESR_UNUSED const interrupts::SuspendResumeAllInterruptsScopedLock lock;

    WDOG->CNT = FEATURE_WDOG_UNLOCK_VALUE;
    while ((WDOG->CS & WDOG_CS_ULK_MASK) == 0U)
    {
        // wait until registers are unlocked
    }

    WDOG->TOVAL = WDOG_TOVAL_TOVALLOW_MASK;
    uint32_t const controlStatus
        = WDOG_CS_UPDATE(1U) | WDOG_CS_EN(1U) | WDOG_CS_CLK(1U) | WDOG_CS_TST(0x02U);

    WDOG->CS = controlStatus;

    while ((WDOG->CS & WDOG_CS_RCS_MASK) == 0U)
    {
        // wait until new configuration takes effect
    }
#endif
}

void Watchdog::startFastTestHigh()
{
#if 0
    ESR_UNUSED const interrupts::SuspendResumeAllInterruptsScopedLock lock;

    WDOG->CNT = FEATURE_WDOG_UNLOCK_VALUE;
    while ((WDOG->CS & WDOG_CS_ULK_MASK) == 0U)
    {
        // wait until registers are unlocked
    }

    WDOG->TOVAL = WDOG_TOVAL_TOVALLOW_MASK;
    uint32_t const controlStatus
        = WDOG_CS_UPDATE(1U) | WDOG_CS_EN(1U) | WDOG_CS_CLK(1U) | WDOG_CS_TST(0x03U);

    WDOG->CS = controlStatus;

    while ((WDOG->CS & WDOG_CS_RCS_MASK) == 0U)
    {
        // wait until new configuration takes effect
    }
#endif
}

void Watchdog::setUserMode()
{
#if 0
    ESR_UNUSED const interrupts::SuspendResumeAllInterruptsScopedLock lock;

    WDOG->CNT = FEATURE_WDOG_UNLOCK_VALUE;
    while ((WDOG->CS & WDOG_CS_ULK_MASK) == 0U)
    {
        // wait until registers are unlocked
    }

    uint32_t const controlStatus
        = WDOG_CS_UPDATE(1U) | WDOG_CS_CLK(1U) | WDOG_CS_CMD32EN(1U) | WDOG_CS_TST(1U);

    WDOG->CS = controlStatus;

    while ((WDOG->CS & WDOG_CS_RCS_MASK) == 0U)
    {
        // wait until new configuration takes effect
    }
#endif
}

uint32_t Watchdog::getWatchdogServiceCounter() {
    return watchdogServiceCounter;
}

} // namespace bsp
