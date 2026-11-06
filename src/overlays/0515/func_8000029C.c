// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_balance.h"

void ref_func_80B8264C(BgDblueBalance* this) {
    s32 pad;
    s32 i;
    BgDblueBalanceStruct* phi_s0;
    Vec3f sp78;
    f32 temp_f0;
    s16 phi_s2;

    if (this->isSwitchFlagSet) {
        if (this->unk_183 < 8) {
            this->unk_183 = 0;
        } else {
            this->unk_183 -= 7;
        }
    } else {
        if (this->unk_183 > 250) {
            this->unk_183 = 255;
        } else {
            this->unk_183 += 4;
        }
    }

    Matrix_Translate(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y, this->dyna.actor.world.pos.z,
                     MTXMODE_NEW);
    Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_APPLY);

    for (i = 0, phi_s0 = &this->unk_188[0], phi_s2 = 0; i < ARRAY_COUNT(this->unk_188);
         i++, phi_s2 += 0x2000, phi_s0++) {
        phi_s0->unk_0C = this->dyna.actor.shape.rot.x + phi_s2;

        Matrix_Push();
        Matrix_RotateXS(phi_s0->unk_0C, MTXMODE_NEW);
        Matrix_Translate(-545.0f, 0.0f, 270.0f, MTXMODE_APPLY);
        Matrix_MultZero(&sp78);
        Matrix_Pop();
        Matrix_MultVec3f(&sp78, &phi_s0->unk_00);

        temp_f0 = (sp78.z - 135.0f);
        if (sp78.z > 135.0f) {
            temp_f0 *= 1.8962963f;
            if (temp_f0 > 255.0f) {
                phi_s0->unk_0E = 0xFF;
                phi_s0->unk_10 = 0.1f;
            } else if (temp_f0 < 1.0f) {
                phi_s0->unk_0E = 0;
                phi_s0->unk_10 = 0.0f;
            } else {
                phi_s0->unk_0E = temp_f0;
                phi_s0->unk_10 = temp_f0 * 0.000390625f;
            }
        } else {
            phi_s0->unk_0E = 0;
        }
    }
}
