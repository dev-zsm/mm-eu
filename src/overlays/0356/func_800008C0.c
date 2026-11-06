// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_driftice.h"

void ref_func_80A66E30(ObjDrifticeStruct* arg0, ObjDriftice* this) {
    f32 temp;
    f32* temp_s1 = ref_D_80A67664[OBJDRIFTICE_GET_ROT(&this->dyna.actor) - 1];
    s16 sp36;
    s16 sp34;
    s16 sp32;
    s16 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    s16 sp22;

    sp2C = ref_func_80A665EC(arg0, this);
    sp28 = ref_func_80A667F0(arg0->unk_14, this);
    ref_func_80A66930(&arg0->unk_50, this, &sp32, &sp30);
    ref_func_80A66C4C(&arg0->unk_84, this, &sp36, &sp34);

    this->dyna.actor.shape.yOffset = this->unk_240 * ((sp28 * temp_s1[1]) + (sp2C * temp_s1[0]));

    sp24 = (sp32 * temp_s1[2]) + (sp36 * temp_s1[3]) * (temp = 1.0f);
    sp22 = (sp34 + sp30) - this->dyna.actor.shape.rot.y;

    this->dyna.actor.shape.rot.x = Math_CosS(sp22) * sp24;
    ref_func_80A665AC(&this->dyna.actor.shape.rot.x, 0xA28);
    this->dyna.actor.shape.rot.z = -Math_SinS(sp22) * sp24;
    ref_func_80A665AC(&this->dyna.actor.shape.rot.z, 0xA28);
}
