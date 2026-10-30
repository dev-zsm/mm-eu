// FLAGS: -O2 -g0 -mips2
#include "dmamgr.h"

s32 DmaMgr_FindDmaIndex(u32 vrom) {
    DmaEntry *entry = DmaMgr_FindDmaEntry(vrom);

    if (entry != NULL) {
        return entry - D_8009FC80;
    }
    return -1;
}
