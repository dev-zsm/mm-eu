// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_door_etc.h"

void EnDoorEtc_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    EnDoorEtc* this = (EnDoorEtc*)thisx;

    this->actionFunc(this, play);
    if (this->unk_1F4 & 1) {
        Collider_UpdateCylinder(&this->knobDoor.dyna.actor, &this->collider);
        CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
    }
}
