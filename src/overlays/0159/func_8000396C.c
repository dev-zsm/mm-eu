// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void ref_func_8094220C(EnGoroiwa* this, PlayState* play) {
    s32 pad;
    EnGoroiwaStruct* ptr;
    s32 i;
    s32 bgId;
    Vec3f spC4;
    Vec3f spB8;
    f32 phi_f12;
    f32 temp_f20;
    f32 spAC;
    s32 params;
    Vec3f sp9C;
    s16 sp9A;

    for (i = 0; i < ARRAY_COUNT(this->unk_1E8); i++) {
        ptr = &this->unk_1E8[i];

        if (!(ptr->unk_2D & 1)) {
            ptr->unk_10 -= 6.0f;
            if (ptr->unk_10 < -20.0f) {
                ptr->unk_10 = -20.0f;
            }
            ptr->unk_00.x += ptr->unk_0C;
            ptr->unk_00.y += ptr->unk_10;
            ptr->unk_00.z += ptr->unk_14;

            ptr->unk_1C += ptr->unk_22;
            ptr->unk_1E += ptr->unk_24;
            ptr->unk_20 += ptr->unk_26;

            spC4.x = ptr->unk_00.x;
            spC4.y = ptr->unk_00.y + 25.0f;
            spC4.z = ptr->unk_00.z;

            ptr->unk_18 = BgCheck_EntityRaycastFloor5(&play->colCtx, &ptr->unk_28, &bgId, &this->actor, &spC4);

            if (ptr->unk_10 <= 0.0f) {
                Matrix_RotateZYX(ptr->unk_1C, ptr->unk_1E, ptr->unk_20, MTXMODE_NEW);
                Matrix_MultVec3f(&ref_D_80942E6C, &spB8);
                temp_f20 = this->unk_1DC * 0.9f;

                if (spB8.y > 0.0f) {
                    if (Math3D_CosOut(&ref_D_80942E60, &spB8, &spAC)) {
                        phi_f12 = 1.0f;
                    } else {
                        phi_f12 = 1.0f - SQ(spAC);
                    }

                    if (phi_f12 <= 0.0f) {
                        temp_f20 = 0.0f;
                    } else {
                        temp_f20 *= sqrtf(phi_f12);
                    }
                }

                if (((ptr->unk_00.y + (this->unk_1DC - temp_f20)) < ptr->unk_18) ||
                    (ptr->unk_18 < (BGCHECK_Y_MIN + 10))) {
                    params = ENGOROIWA_GET_C000(&this->actor);
                    ptr->unk_2D |= 1;
                    sp9C.x = ptr->unk_00.x;
                    sp9C.y = (ptr->unk_00.y - ptr->unk_10) + 10.0f;
                    sp9C.z = ptr->unk_00.z;
                    ref_func_80940A1C(play, &sp9C, ref_D_80942E0C[params], &ref_D_80942E30[params], &ref_D_80942E3C[params],
                                  this->actor.scale.x);
                }
            }
        }
    }

    if ((this->unk_1E8[0].unk_2D & 1) && (this->unk_1E8[1].unk_2D & 1)) {
        ref_func_809425CC(this);
        return;
    }

    sp9A = this->actor.shape.shadowAlpha;
    Math_StepToS(&sp9A, 0, 40);
    this->actor.shape.shadowAlpha = sp9A;

    for (i = 0; i < ARRAY_COUNT(this->unk_1E8); i++) {
        ptr = &this->unk_1E8[i];

        if (ptr->unk_2D & 1) {
            ptr->unk_2C = 0;
        } else {
            sp9A = ptr->unk_2C;
            Math_StepToS(&sp9A, 160, 24);
            ptr->unk_2C = sp9A;
        }
    }
}
