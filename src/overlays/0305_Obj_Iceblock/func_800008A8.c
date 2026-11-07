// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A23938(ObjIceblock* this) {
    Actor* thisx = &this->dyna.actor;

    if (this->unk_1B0 & 0x80) {
        Math_ScaledStepToS(&thisx->shape.rot.x, 0, 0x190);
        Math_ScaledStepToS(&thisx->shape.rot.z, 0, 0x190);
    } else {
        ObjIceBlockUnkStruct4* ptr = &this->unk_27C;
        f32 phi_f0;
        s16 temp;

        if (this->unk_1B0 & 0x20) {
            phi_f0 = 0.3f;
            ptr->unk_14 = thisx->yawTowardsPlayer;
        } else {
            phi_f0 = 0.08f;
        }

        Math_StepToF(&ptr->unk_1C, phi_f0, 0.04f);
        ptr->unk_22 += TRUNCF_BINANG(ptr->unk_20 * -0.02f);
        ptr->unk_22 = ref_func_80A23090(ptr->unk_22, 50, 800);
        ptr->unk_20 += ptr->unk_22;

        temp = ptr->unk_16 - ptr->unk_14;

        ptr->unk_18 += TRUNCF_BINANG(temp * -0.04f * thisx->xzDistToPlayer * thisx->scale.x * (1.0f / 600.0f));
        ptr->unk_18 = ref_func_80A23090(ptr->unk_18, 50, 800);
        ptr->unk_16 += ptr->unk_18;

        thisx->shape.rot.x = Math_CosS(ptr->unk_16) * ptr->unk_20 * ptr->unk_1C;
        thisx->shape.rot.x = CLAMP(thisx->shape.rot.x, -2000, 2000);

        thisx->shape.rot.z = -Math_SinS(ptr->unk_16) * ptr->unk_20 * ptr->unk_1C;
        thisx->shape.rot.z = CLAMP(thisx->shape.rot.z, -2000, 2000);
    }
}
