// Copyright 2024 Accenture.

#include "mcu/mcu.h"
#include "platform/estdint.h"

extern "C"
{
void cacheEnable(void)
{
#if 0
    LMEM->PCCCR
        = LMEM_PCCCR_INVW0(1) | LMEM_PCCCR_INVW1(1) | LMEM_PCCCR_GO(1) | LMEM_PCCCR_ENCACHE(1);
#endif
}

void cacheDisable(void)
{
#if 0
    LMEM->PCCCR
        = LMEM_PCCCR_INVW0(1) | LMEM_PCCCR_INVW1(1) | LMEM_PCCCR_GO(1) | LMEM_PCCCR_ENCACHE(0);
#endif
}

void cacheInvalidate(uint32_t const /* addr */, uint32_t const /* size */)
{
#if 0
    LMEM->PCCCR
        = LMEM_PCCCR_INVW0(1) | LMEM_PCCCR_INVW1(1) | LMEM_PCCCR_GO(1) | LMEM_PCCCR_ENCACHE(1);
#endif
}

} // extern "C"
