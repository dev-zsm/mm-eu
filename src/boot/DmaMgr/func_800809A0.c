// FLAGS: -O2 -g0 -mips2
#include "dmamgr.h"

// Translates vrom to a ROM address; a compressed file (romEnd != 0) only maps its first address.
// Returns -1 if vrom is not mapped.
s32 DmaMgr_TranslateVromToRom(u32 vrom) {
    DmaEntry *entry = DmaMgr_FindDmaEntry(vrom);

    if (entry != NULL) {
        if (entry->romEnd == 0) {
            return entry->romStart + vrom - entry->vromStart;
        }
        if (vrom == entry->vromStart) {
            return entry->romStart;
        }
        return -1;
    }
    return -1;
}
