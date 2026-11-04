// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_scene.h"

s32 Object_SpawnPersistent(ObjectContext* objectCtx, s16 id) {
    size_t size;

    objectCtx->slots[objectCtx->numEntries].id = id;
    size = gObjectTable[id].vromEnd - gObjectTable[id].vromStart;

    
    if (1) {}

    if (size != 0) {
        DmaMgr_RequestSync(objectCtx->slots[objectCtx->numEntries].segment, gObjectTable[id].vromStart, size);
    }

    if (objectCtx->numEntries < ARRAY_COUNT(objectCtx->slots) - 1) {
        objectCtx->slots[objectCtx->numEntries + 1].segment =
            (void*)ALIGN16((uintptr_t)objectCtx->slots[objectCtx->numEntries].segment + size);
    }

    objectCtx->numEntries++;
    objectCtx->numPersistentEntries = objectCtx->numEntries;

    return objectCtx->numEntries - 1;
}
