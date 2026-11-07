// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_f40_block.h"

void BgF40Block_Init(Actor* thisx, PlayState* play) {
    BgF40Block* this = (BgF40Block*)thisx;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    DynaPolyActor_LoadMesh(play, &this->dyna, &gStoneTowerBlockCol);

    if (BGF40BLOCK_GET_PATH_INDEX(&this->dyna.actor) != BGF40BLOCK_PATH_INDEX_NONE) {
        this->path = &play->setupPathList[BGF40BLOCK_GET_PATH_INDEX(&this->dyna.actor)];
    } else {
        this->path = NULL;
    }

    if (this->path != NULL) {
        if (Flags_GetSwitch(play, BGF40BLOCK_GET_SWITCH_FLAG(&this->dyna.actor))) {
            this->actionFunc = ref_func_80BC4530;
            this->dyna.actor.speed = 40.0f;
            ref_func_80BC3A2C(this, play);
        } else {
            this->actionFunc = ref_func_80BC4380;
            this->dyna.actor.speed = 20.0f;
            ref_func_80BC3980(this, play);
        }
    } else {
        this->actionFunc = ref_func_80BC457C;
    }
    this->unk_168 = 6;
}
