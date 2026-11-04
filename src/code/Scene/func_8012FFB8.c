// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_scene.h"

void Scene_CommandObjectList(PlayState* play, SceneCmd* cmd) {
    s32 i;
    s32 j;
    s32 k;
    ObjectEntry* firstObject;
    ObjectEntry* entry;
    ObjectEntry* invalidatedEntry;
    s16* objectEntry;
    void* nextPtr;

    objectEntry = Lib_SegmentedToVirtual(cmd->objectList.segment);
    k = 0;
    i = play->objectCtx.numPersistentEntries;
    entry = &play->objectCtx.slots[i];
    firstObject = &play->objectCtx.slots[0];

    while (i < play->objectCtx.numEntries) {
        if (entry->id != *objectEntry) {
            invalidatedEntry = &play->objectCtx.slots[i];

            for (j = i; j < play->objectCtx.numEntries; j++) {
                invalidatedEntry->id = OBJECT_INVALID;
                invalidatedEntry++;
            }

            play->objectCtx.numEntries = i;
            Actor_KillAllWithMissingObject(play, &play->actorCtx);

            continue;
        }

        i++;
        k++;
        objectEntry++;
        entry++;
    }

    while (k < cmd->objectList.num) {
        nextPtr = ref_func_8012F73C(&play->objectCtx, i, *objectEntry);

        if (i < ARRAY_COUNT(play->objectCtx.slots) - 1) {
            firstObject[i + 1].segment = nextPtr;
        }

        i++;
        k++;
        objectEntry++;
    }

    play->objectCtx.numEntries = i;
}
