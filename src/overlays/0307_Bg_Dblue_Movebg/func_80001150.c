// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_movebg.h"

void ref_func_80A2ABD0(BgDblueMovebg* this, PlayState* play) {
    Vec3f spAC;
    f32 temp_f0;
    f32 temp_f20;
    s32 phi_v0;
    s32 i;
    s32 j;

    for (i = 0; i < ARRAY_COUNT(this->unk_2F8); i++) {
        if (this->unk_2F8[i] == NULL) {
            ref_func_80A2A128(this, play);
            continue;
        }

        for (j = 0; j < ARRAY_COUNT(this->unk_1D8[0]); j++) {
            Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_NEW);
            Matrix_RotateXS(this->dyna.actor.shape.rot.x + (j * 0x2000), MTXMODE_APPLY);
            Matrix_RotateZS(this->dyna.actor.shape.rot.z, MTXMODE_APPLY);
            Matrix_MultVec3f(&ref_D_80A2B988, &spAC);
            Math_Vec3f_Sum(&this->dyna.actor.world.pos, &spAC, &spAC);
            Math_Vec3f_Copy(&this->unk_238[i][j], &spAC);
            temp_f20 = spAC.y - this->unk_2F8[i]->world.pos.y;
            temp_f0 = Math_Vec3f_DistXZ(&this->unk_2F8[i]->world.pos, &spAC);

            if ((this->unk_300[i][j] != 0) && (temp_f20 <= 12.0f) && (temp_f20 >= 0.0f) && (temp_f0 <= 60.0f)) {
                phi_v0 = 1;
            } else {
                phi_v0 = 1;
                phi_v0 = (s64)phi_v0;
                if (((temp_f20 >= 0.0f) && ((temp_f20 > 0.0f) || (temp_f0 > 60.f))) ||
                    ((temp_f20 < 0.0f) && ((temp_f20 < -150.0f) || (temp_f0 > 40.0f)))) {
                    phi_v0 = 0;
                }
            }

            if (phi_v0) {
                this->unk_300[i][j] = i + 1;
                Math_StepToF(&this->unk_1F8[i][j], 1.0f, 0.2f);
                Math_StepToS(&this->unk_1D8[i][j], 255, 20);
            } else {
                this->unk_300[i][j] = 0;
                Math_StepToF(&this->unk_1F8[i][j], 0.0f, 0.01f);
                Math_StepToS(&this->unk_1D8[i][j], 0, 20);
            }
        }
    }
}
