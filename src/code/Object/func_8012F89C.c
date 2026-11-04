// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_scene.h"

void Object_UpdateEntries(ObjectContext* objectCtx) {
    s32 i;
    ObjectEntry* entry = &objectCtx->slots[0];
    RomFile* objectFile;
    size_t size;

    for (i = 0; i < objectCtx->numEntries; i++) {
        if (entry->id < 0) {
            s32 id = -entry->id;

            if (entry->dmaReq.vromAddr == 0) {
                objectFile = &gObjectTable[id];
                size = objectFile->vromEnd - objectFile->vromStart;

                if (size == 0) {
                    entry->id = OBJECT_INVALID;
                } else {
                    osCreateMesgQueue(&entry->loadQueue, &entry->loadMsg, 1);
                    DmaMgr_RequestAsync(&entry->dmaReq, entry->segment, objectFile->vromStart, size, 0,
                                        &entry->loadQueue, NULL);
                }
            } else if (osRecvMesg(&entry->loadQueue, NULL, OS_MESG_NOBLOCK) == 0) {
                entry->id = id;
            }
        }

        entry++;
    }
}
