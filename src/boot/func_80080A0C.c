// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void *DmaMgr_FindDmaEntry(void);
extern u8 D_8009FC80[];

s32 DmaMgr_FindDmaIndex(void) {
    u8 *p = DmaMgr_FindDmaEntry();

    if (p != 0) {
        return (p - D_8009FC80) >> 4;
    }
    return -1;
}
