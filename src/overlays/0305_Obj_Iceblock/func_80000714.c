// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A237A4(ObjIceblock* this) {
    s32 pad[2];
    ObjIceBlockUnkStruct4* ptr = &this->unk_27C;
    f32 sp20;

    ptr->unk_10 += ptr->unk_0C;
    ptr->unk_12 += ptr->unk_0E;
    Math_StepToF(&this->unk_27C.unk_08, this->unk_27C.unk_04, 0.08f);

    if (this->unk_1B0 & 0x20) {
        Math_StepToF(&ptr->unk_00, -5.0f, (Math_CosS(fabsf(ptr->unk_00) * 3276.8f) * 0.3f) + 0.02f);
    } else {
        Math_StepToF(&ptr->unk_00, 0.0f, (Math_SinS(fabsf(ptr->unk_00) * 3276.8f) * 0.3f) + 0.02f);
    }

    sp20 = Math_SinS(ptr->unk_10);
    this->dyna.actor.world.pos.y =
        (Math_SinS(ptr->unk_12) * ptr->unk_08 * 0.5f) +
        ((this->unk_244 - ((600.0f * this->dyna.actor.scale.y) - 90.0f)) + (sp20 * ptr->unk_08)) + ptr->unk_00;
}
