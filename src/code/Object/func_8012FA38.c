// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_scene.h"

void Object_LoadAll(ObjectContext* objectCtx) {
    s32 i;
    s32 id;
    uintptr_t vromSize;

    for (i = 0; i < objectCtx->numEntries; i++) {
        id = objectCtx->slots[i].id;
        vromSize = gObjectTable[id].vromEnd - gObjectTable[id].vromStart;

        if (vromSize == 0) {
            continue;
        }

        DmaMgr_RequestSync(objectCtx->slots[i].segment, gObjectTable[id].vromStart, vromSize);
    }
}
