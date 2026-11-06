// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5E604(Actor* thisx, PlayState* play) {
    s32 pad;
    EnKusa2* this = (EnKusa2*)thisx;

    this->actionFunc(this, play);

    if (ref_D_80A60900 == play->gameplayFrames) {
        this->actor.draw = NULL;
    } else {
        this->actor.draw = ref_func_80A5E6F0;

        if (play->roomCtx.curRoom.type == ROOM_TYPE_NORMAL) {
            ref_func_80A5B508();
        }
        ref_func_80A5CAF4(&ref_D_80A5F1C0);
        ref_D_80A60900 = play->gameplayFrames;
    }
}
