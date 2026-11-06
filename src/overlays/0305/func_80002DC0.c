// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A25E50(ObjIceblock* this, PlayState* play) {
    s32 pad;
    f32 temp_f0 = this->unk_268 - *this->unk_264;
    f32 temp_f2 = (Math_SinS(fabsf(temp_f0) * 546.13336f) * 2.8f) + 1.2f;
    s32 sp38 = Math_StepToF(this->unk_264, this->unk_268, CLAMP_MAX(temp_f2, 3.5f));
    s32 pad2;
    Vec3f sp28;

    ref_func_80A23690(this);
    if (!ref_func_80A23F90(this, play)) {
        ref_func_80A24680(this, play);
        ref_func_80A23B88(this);
        ref_func_80A2541C(this, play);
        ref_func_80A25BA0(this);
    } else if (sp38) {
        if (ref_func_80A24118(this, play, 59.9f, &sp28)) {
            Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_BLOCK_BOUND);
        }
        ref_func_80A2541C(this, play);
        ref_func_80A25CF4(this);
    } else {
        Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_PL_SLIP_ICE_LEVEL - SFX_FLAG);
    }
}
