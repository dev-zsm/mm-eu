// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bigicicle.h"

void ref_func_80AE9180(ObjBigicicle* this, PlayState* play) {
    this->unk_14A--;

    if (this->unk_14A > 0) {
        this->unk_14A--;
        this->actor.shape.rot.x = BINANG_ADD((s32)(Rand_CenteredFloat(0x580) * 0.02f * this->unk_14A), 0x4000);
        this->actor.shape.rot.z = Rand_CenteredFloat(0x580) * 0.02f * this->unk_14A;
    } else {
        this->actor.shape.rot.x = 0x4000;
        this->actor.shape.rot.z = 0;
        CutsceneManager_Stop(this->actor.csId);
        this->actionFunc = ref_func_80AE8FD4;
    }
}
