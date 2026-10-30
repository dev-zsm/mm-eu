// FLAGS: -O2 -g3 -mips2
#include "dmamgr.h"

void DmaMgr_Init(void) {
    DmaEntry *first;
    DmaEntry *iter;
    s32 count;

    func_800807E0((u32)D_1A8D0, D_8009FC80, (u32)D_20C20 - (u32)D_1A8D0);
    first = D_8009FC80; iter = D_8009FC80; count = 0; if (first->vromEnd != 0) { iter = first;
        do {
            iter++;
            count++;
        } while (iter->vromEnd != 0);
    }
    D_8009B68C = count;
block_split: // matching: statements per source line and this label steer the -g3 scheduling
    ;
    ;
    osCreateMesgQueue(&D_8009B690, D_8009B6A8, 0x20);
    StackCheck_Init(&D_8009B670, D_8009B8D8, D_8009BDD8, 0, 0x100, D_80098494);
    osCreateThread(&D_8009B728, 0x12, DmaMgr_ThreadEntry, NULL, D_8009BDD8, 0x11);
    osStartThread(&D_8009B728);
}
