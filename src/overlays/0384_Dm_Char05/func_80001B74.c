// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char05.h"

void ref_func_80AAE114(PlayState* play, DmChar05* this) {
    s32 getItemDrawIndex;
    s16 getItemDrawIds[] = {
        GID_MASK_KAMARO,        GID_MASK_GREAT_FAIRY, GID_MASK_ROMANI, GID_MASK_BLAST,
        GID_MASK_CIRCUS_LEADER, GID_MASK_BREMEN,      GID_MASK_BUNNY,  GID_MASK_POSTMAN,
    };

    getItemDrawIndex = DMCHAR05_GET(&this->actor) - DMCHAR05_5;
    if (this->actor.objectSlot == this->objectSlot) {
        Matrix_Translate(this->actor.world.pos.x, this->actor.world.pos.y, this->actor.world.pos.z, MTXMODE_NEW);
        Matrix_RotateZYX(0, play->gameplayFrames * 1000, 0, MTXMODE_APPLY);
        Matrix_Scale(0.2f, 0.2f, 0.2f, MTXMODE_APPLY);
        GetItem_Draw(play, getItemDrawIds[getItemDrawIndex]);
    }

    if (Object_IsLoaded(&play->objectCtx, this->objectSlot)) {
        this->actor.objectSlot = this->objectSlot;
    }
}
