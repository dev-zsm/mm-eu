// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball.h"

void ref_func_80B04648(ObjSnowball* this, PlayState* play) {
    this->unk_208--;
    if (this->unk_208 <= 0) {
        if (this->unk_20B != 0) {
            CutsceneManager_Stop(this->actor.csId);
        }

        if (this->actor.home.rot.y == 1) {
            ref_func_80B04B48(this, play);
        } else {
            Actor_Kill(&this->actor);
        }
    } else if (this->unk_208 == 0x2D) {
        ref_func_80B03688(this, play);
    }
}
