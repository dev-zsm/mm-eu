// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_actor_dlftbls.h"

uintptr_t ActorOverlayTable_FaultAddrConv(uintptr_t address, void* param) {
    uintptr_t addr = address;
    ActorOverlay* actorOvl = &gActorOverlayTable[0];
    uintptr_t ramConv;
    void* ramStart;
    size_t diff;
    ActorId actorId;

    for (actorId = 0; actorId < gMaxActorId; actorId++, actorOvl++) {
        diff = (uintptr_t)actorOvl->vramEnd - (uintptr_t)actorOvl->vramStart;
        ramStart = actorOvl->loadedRamAddr;
        ramConv = (uintptr_t)actorOvl->vramStart - (uintptr_t)ramStart;

        if (ramStart != NULL) {
            if ((addr >= (uintptr_t)ramStart) && (addr < (uintptr_t)ramStart + diff)) {
                return addr + ramConv;
            }
        }
    }

    return 0;
}
