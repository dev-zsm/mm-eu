// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_scene.h"

void Object_InitContext(GameState* gameState, ObjectContext* objectCtx) {
    PlayState* play = (PlayState*)gameState;
    s32 pad;
    u32 spaceSize;
    s32 i;

    if (play->sceneId == SCENE_CLOCKTOWER || play->sceneId == SCENE_TOWN || play->sceneId == SCENE_BACKTOWN ||
        play->sceneId == SCENE_ICHIBA) {
        spaceSize = 1530 * 1024;
    } else if (play->sceneId == SCENE_MILK_BAR) {
        spaceSize = 1580 * 1024;
    } else if (play->sceneId == SCENE_00KEIKOKU) {
        spaceSize = 1470 * 1024;
    } else {
        spaceSize = 1380 * 1024;
    }

    objectCtx->numEntries = 0;
    objectCtx->numPersistentEntries = 0;
    objectCtx->mainKeepSlot = 0;
    objectCtx->subKeepSlot = 0;

    
    for (i = 0; i < ARRAY_COUNT(objectCtx->slots); i++) { objectCtx->slots[i].id = OBJECT_INVALID; }
    

    objectCtx->spaceStart = objectCtx->slots[0].segment = THA_AllocTailAlign16(&gameState->tha, spaceSize);
    objectCtx->spaceEnd = (void*)((u32)objectCtx->spaceStart + spaceSize);
    objectCtx->mainKeepSlot = Object_SpawnPersistent(objectCtx, GAMEPLAY_KEEP);

    gSegments[0x04] = OS_K0_TO_PHYSICAL(objectCtx->slots[objectCtx->mainKeepSlot].segment);
}
