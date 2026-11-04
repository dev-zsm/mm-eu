// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kaleido_manager.h"

uintptr_t KaleidoManager_FaultAddrConv(uintptr_t address, void* param) {
    uintptr_t addr = address;
    KaleidoMgrOverlay* kaleidoMgrOvl = gKaleidoMgrCurOvl;
    uintptr_t ramConv;
    void* ramStart;
    size_t diff;

    if (kaleidoMgrOvl != NULL) {
        diff = (uintptr_t)kaleidoMgrOvl->vramEnd - (uintptr_t)kaleidoMgrOvl->vramStart;
        ramStart = kaleidoMgrOvl->loadedRamAddr;
        ramConv = (uintptr_t)kaleidoMgrOvl->vramStart - (uintptr_t)ramStart;

        if (ramStart != NULL) {
            if ((addr >= (uintptr_t)ramStart) && (addr < (uintptr_t)ramStart + diff)) {
                return addr + ramConv;
            }
        }
    }
    return 0;
}
