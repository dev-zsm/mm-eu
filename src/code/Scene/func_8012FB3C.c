// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_scene.h"

void Scene_CommandSpawnList(PlayState* play, SceneCmd* cmd) {
    s32 loadedCount;
    s16 playerObjectId;
    void* objectPtr;

    play->linkActorEntry =
        (ActorEntry*)Lib_SegmentedToVirtual(cmd->spawnList.segment) + play->setupEntranceList[play->curSpawn].spawn;
    if ((PLAYER_GET_START_MODE(play->linkActorEntry) == PLAYER_START_MODE_TELESCOPE) ||
        ((gSaveContext.respawnFlag == 2) && (gSaveContext.respawn[RESPAWN_MODE_RETURN].playerParams ==
                                             PLAYER_PARAMS(0xFF, PLAYER_START_MODE_TELESCOPE)))) {
        
        Object_SpawnPersistent(&play->objectCtx, OBJECT_STK);
        return;
    }

    loadedCount = Object_SpawnPersistent(&play->objectCtx, OBJECT_LINK_CHILD);
    objectPtr = play->objectCtx.slots[play->objectCtx.numEntries].segment;
    play->objectCtx.numEntries = loadedCount;
    play->objectCtx.numPersistentEntries = loadedCount;
    playerObjectId = gPlayerFormObjectIds[GET_PLAYER_FORM];
    gActorOverlayTable[ACTOR_PLAYER].profile->objectId = playerObjectId;
    Object_SpawnPersistent(&play->objectCtx, playerObjectId);

    play->objectCtx.slots[play->objectCtx.numEntries].segment = objectPtr;
}
