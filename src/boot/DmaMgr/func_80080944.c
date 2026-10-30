// FLAGS: -O2 -g0 -mips2
#include "dmamgr.h"

// Returns the row of D_8009FC80 that contains vrom, or NULL.
DmaEntry *DmaMgr_FindDmaEntry(u32 vrom) {
    DmaEntry *iter;
    DmaEntry *first = D_8009FC80; /* matching: separate start pointer */

    if (first->vromEnd != 0) {
        iter = first;
        while (1) {
            if (vrom >= iter->vromStart && vrom < iter->vromEnd) {
                return iter;
            }
            iter++;
            if (iter->vromEnd == 0) {
                break;
            }
        }
    }
    return NULL;
}
