// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A25D28(ObjIceblock* this, PlayState* play) {
    s32 sp34;
    s32 sp30;
    Vec3f sp24;

    ref_func_80A23690(this);
    ref_func_80A23F90(this, play);
    sp30 = ref_func_80A25238(this);
    ref_func_80A252DC(this, sp30);
    sp34 = true;
    if (sp30 == -1) {
        sp34 = false;
    } else if (!(this->unk_1B0 & 2) && (this->unk_26E[sp30] >= 11)) {
        sp34 = true;
        if (!ref_func_80A24118(this, play, (this->dyna.pushForce > 0.0f) ? 59.9f : 89.9f, &sp24)) {
            ref_func_80A232C4(this, sp30);
            ref_func_80A25E3C(this);
            sp34 = false;
        }
    }

    if (sp34) {
        ref_func_80A2541C(this, play);
    }

    ref_func_80A24A48(this, play);
}
