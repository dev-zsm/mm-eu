// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_play.h"

void Play_InitScene(PlayState* this, s32 spawn) {
    this->curSpawn = spawn;
    this->linkActorEntry = NULL;
    this->actorCsCamList = NULL;
    this->setupEntranceList = NULL;
    this->setupExitList = NULL;
    this->naviQuestHints = NULL;
    this->setupPathList = NULL;
    this->sceneMaterialAnims = NULL;
    this->roomCtx.unk74 = NULL;
    this->numSetupActors = 0;
    Object_InitContext(&this->state, &this->objectCtx);
    LightContext_Init(this, &this->lightCtx);
    Scene_ResetTransitionActorList(&this->state, &this->transitionActors);
    Room_Init(this, &this->roomCtx);
    gSaveContext.worldMapArea = 0;
    Scene_ExecuteCommands(this, this->sceneSegment);
    Play_InitEnvironment(this, this->skyboxId);
}
