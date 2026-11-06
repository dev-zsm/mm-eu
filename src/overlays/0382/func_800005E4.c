// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char03.h"

void ref_func_80AABA84(PlayState* play, DmChar03* this) {
    s32 pad;

    if (this->actor.objectSlot == this->objectSlot) {
        Matrix_Translate(this->offset.x, this->offset.y, this->offset.z, MTXMODE_NEW);
        Matrix_RotateZYX(0, (play->gameplayFrames * 0x3E8), 0, MTXMODE_APPLY);
        Matrix_Scale(0.2f, 0.2f, 0.2f, MTXMODE_APPLY);
        GetItem_Draw(play, GID_MASK_DEKU);
    }
    if (Object_IsLoaded(&play->objectCtx, this->objectSlot)) {
        this->actor.objectSlot = this->objectSlot;
    }
}
