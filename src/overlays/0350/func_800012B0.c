// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5C410(EnKusa2UnkBssStruct* arg0, EnKusa2UnkBssSubStruct2* arg1, Vec3f* arg2) {
    s32 i;
    Vec3f sp98;
    EnKusa2UnkBssSubStruct* s;
    s32 pad;

    Math_Vec3f_Copy(arg2, &gZeroVec3f);

    for (i = 0; i < ARRAY_COUNT(ref_D_80A5F1C0.unk_0000); i++) {
        s = &arg0->unk_0000[i];

        if (s->unk_26 > 0) {
            f32 temp_f0;
            s32 phi_v0 = true;
            s32 phi_s2 = true;

            Math_Vec3f_Diff(&arg1->unk_04, &s->unk_00, &sp98);
            temp_f0 = Math3D_Vec3fMagnitudeSq(&sp98);

            phi_v0 = false;
            if (temp_f0 <= s->unk_4C) {
                phi_v0 = true;
            }

            phi_s2 = false;
            if (temp_f0 <= s->unk_70) {
                phi_s2 = true;
            }

            if (phi_v0 || phi_s2) {
                f32 phi_f22;

                if (temp_f0 < SQ(0.01f)) {
                    phi_f22 = 0.0f;
                } else {
                    phi_f22 = sqrtf(temp_f0);
                }

                if (phi_v0) {
                    f32 phi_f2;
                    f32 phi_f20;

                    if (phi_f22 > 1.0f) {
                        phi_f20 = 1.0f / phi_f22;
                    } else {
                        phi_f20 = 1.0f;
                    }

                    if (phi_f22 < s->unk_3C) {
                        phi_f2 = Math_SinS(s->unk_50 * phi_f22) * -s->unk_2C;
                    } else {
                        phi_f2 = (Math_CosS(s->unk_54 * (phi_f22 - s->unk_3C)) + 1.0f) * s->unk_30;
                    }

                    arg2->x += sp98.x * -(phi_f20 * phi_f2);
                    arg2->z += sp98.z * -(phi_f20 * phi_f2);

                    if (phi_s2) {
                        arg2->x += phi_f20 * sp98.z * s->unk_58;
                        arg2->z -= phi_f20 * sp98.x * s->unk_58;
                    }
                }

                if (phi_s2 && (fabsf(sp98.y) < s->unk_78)) {
                    arg2->y +=
                        s->unk_68 * (Math_CosS(s->unk_74 * phi_f22) + 1.0f) * (Math_CosS(s->unk_7C * sp98.y) + 1.0f);
                }
            }
        }
    }

    arg2->y -= 0.5f;
}
