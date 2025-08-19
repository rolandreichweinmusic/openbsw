// Copyright 2024 Accenture.

#include <printf/printf.h>
#include "pico.h"
#include "pico/stdlib.h"
#include <cstdio>

#include "systems/BspSystem.h"

#include <etl/alignment.h>

#include <cinttypes>
#ifdef PLATFORM_SUPPORT_CAN
#include "systems/CanSystem.h"
#endif
#include "cache/cache.h"
#include "clock/clockConfig.h"
#include "commonDebug.h"
#include "lifecycle/StaticBsp.h"

#include <lifecycle/LifecycleManager.h>
#include <safeLifecycle/SafeSupervisor.h>
#include <safeWatchdog/SafeWatchdog.h>
#include <watchdog/Watchdog.h>
#include <watchdogManager/watchdogManager.h>
#include <async/Config.h>

extern void app_main();

extern safety::SafeWatchdog safeWatchdog;

extern "C"
{
void ExceptionHandler()
{
    while (true)
    {
        printf("ExceptionHandler :(");
    }
}

void boardInit()
{
    /* Disables the watchdog early before the timeout occurs, which is then enabled later in the
       main function. */
    bsp::Watchdog::disableWatchdog();
    configurPll();
    cacheEnable();
}

void setupApplicationsIsr(void)
{
#if 0
    // interrupts
    SYS_SetPriority(CAN0_ORed_0_15_MB_IRQn, 8);  // can0 buffer 0 - 15
    SYS_SetPriority(CAN0_ORed_16_31_MB_IRQn, 8); // can0 buffer 16 - 32

    SYS_EnableIRQ(CAN0_ORed_0_15_MB_IRQn);
    SYS_EnableIRQ(CAN0_ORed_16_31_MB_IRQn);

    ENABLE_INTERRUPTS();
#endif
}
} // extern "C"

namespace platform
{
StaticBsp staticBsp;

StaticBsp& getStaticBsp() { return staticBsp; }

::etl::typed_storage<::systems::BspSystem> bspSystem;

#ifdef PLATFORM_SUPPORT_CAN
::etl::typed_storage<::systems::CanSystem> canSystem;
#endif // PLATFORM_SUPPORT_CAN

/**
 * Callout from main application to give platform the chance to add a
 * ::lifecycle::ILifecycleComponent to the \p lifecycleManager at a given \p level.
 */
void platformLifecycleAdd(::lifecycle::LifecycleManager& lifecycleManager, uint8_t const level)
{
    if (level == 1U)
    {
        lifecycleManager.addComponent("bsp", bspSystem.create(TASK_BSP, staticBsp), level);
    }
    if (level == 2U)
    {
#ifdef PLATFORM_SUPPORT_CAN
        lifecycleManager.addComponent("can", canSystem.create(TASK_CAN, staticBsp), level);
#endif // PLATFORM_SUPPORT_CAN
    }
}
} // namespace platform

#ifdef PLATFORM_SUPPORT_CAN
namespace systems
{
::can::ICanSystem& getCanSystem() { return *::platform::canSystem; }
} // namespace systems
#endif // PLATFORM_SUPPORT_CAN

int main()
{
    stdio_init_all();
    printf("main()\r\n");
    auto& safeSupervisor = safety::SafeSupervisor::getInstance();
    safeSupervisor.enterLimpHome();
    bool watchdogTest = safety::WatchdogManager::startTest();
    if (watchdogTest)
    {
        safeSupervisor.leaveLimpHome();
    }
    else
    {
        safeSupervisor.watchdogStartupCheckMonitor.trigger();
    }
    safeWatchdog.enableMcuWatchdog();
    ::platform::staticBsp.init();
    printf("app_main()\r\n");
    app_main(); // entry point for the generic part
    return (1); // we never reach this point
}
