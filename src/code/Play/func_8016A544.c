// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_play.h"

void Play_SpawnScene(PlayState* this, s32 sceneId, s32 spawn) {
    s32 pad;
    SceneTableEntry* scene = &gSceneTable[sceneId];

    scene->unk_D = 0;
    this->loadedScene = scene;
    this->sceneId = sceneId;
    this->sceneConfig = scene->drawConfig;
    this->sceneSegment = Play_LoadFile(this, &scene->segment);
    scene->unk_D = 0;
    gSegments[0x02] = OS_K0_TO_PHYSICAL(this->sceneSegment);
    Play_InitScene(this, spawn);
    Room_SetupFirstRoom(this, &this->roomCtx);
}
