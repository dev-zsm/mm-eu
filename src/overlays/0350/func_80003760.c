// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void EnKusa2_Draw(Actor* thisx, PlayState* play) {
    EnKusa2* this = (EnKusa2*)thisx;

    if (this->actor.projectedPos.z <= 1200.0f) {
        if ((play->roomCtx.curRoom.type == ROOM_TYPE_NORMAL) && (this->actor.projectedPos.z > -150.0f) &&
            (this->actor.projectedPos.z < 400.0f)) {
            ref_func_80A5B954(&ref_D_80A60908[this->unk_1CE], 0.0015f);
        }
        Gfx_DrawDListOpa(play, gKusaBushType1DL);
    } else if (this->actor.projectedPos.z < 1300.0f) {
        ref_func_80A5E80C(play, (1300.0f - this->actor.projectedPos.z) * 2.55f);
    }
}
