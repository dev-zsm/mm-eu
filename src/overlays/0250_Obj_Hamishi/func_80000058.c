// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hamishi.h"

void ref_func_809A0F78(ObjHamishi* this) {
    if (this->unk_198 > 0) {
        this->unk_198--;
        this->unk_19A += 0x1388;
        this->unk_19C += 0xE10;

        Math_StepToF(&this->unk_190, 0.0f, 0.15f);
        Math_StepToF(&this->unk_194, 0.0f, 40.0f);

        this->actor.world.pos.x = (Math_SinS(this->unk_19A * 4) * this->unk_190) + this->actor.home.pos.x;
        this->actor.world.pos.z = (Math_CosS(this->unk_19A * 7) * this->unk_190) + this->actor.home.pos.z;

        this->actor.shape.rot.x = (s32)(Math_SinS(this->unk_19C * 4) * this->unk_194) + this->actor.home.rot.x;
        this->actor.shape.rot.z = (s32)(Math_CosS(this->unk_19C * 7) * this->unk_194) + this->actor.home.rot.z;
    } else {
        Math_StepToF(&this->actor.world.pos.x, this->actor.home.pos.x, 1.0f);
        Math_StepToF(&this->actor.world.pos.z, this->actor.home.pos.z, 1.0f);
        Math_ScaledStepToS(&this->actor.shape.rot.x, this->actor.home.rot.x, 0xBB8);
        Math_ScaledStepToS(&this->actor.shape.rot.z, this->actor.home.rot.z, 0xBB8);
    }
}
