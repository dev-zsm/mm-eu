// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9BD24(BgHakuginPost* this, PlayState* play, BgHakuginPostUnkStruct* unkStruct) {
    s32 i;
    s32 j;

    for (i = 0; i < unkStruct->count; i++) {
        if ((unkStruct->unk_0000[i].unk_34 == 5) || (unkStruct->unk_0000[i].unk_34 == 4)) {
            unkStruct->unk_0000[i].unk_24 = 0.0f;
        } else {
            unkStruct->unk_0000[i].unk_24 -= 2.8f;
            unkStruct->unk_0000[i].unk_24 *= 0.9f;
        }

        if ((unkStruct->unk_0000[i].unk_34 == 2) || (unkStruct->unk_0000[i].unk_34 == 3)) {
            unkStruct->unk_0000[i].unk_20 = 25.0f;
        } else {
            unkStruct->unk_0000[i].unk_20 = 0.0f;
        }

        unkStruct->unk_0000[i].unk_14.x += Math_SinS(unkStruct->unk_0000[i].unk_28) * unkStruct->unk_0000[i].unk_20;
        unkStruct->unk_0000[i].unk_14.z =
            Math_CosS(unkStruct->unk_0000[i].unk_28) * unkStruct->unk_0000[i].unk_20 + unkStruct->unk_0000[i].unk_14.z;
        unkStruct->unk_0000[i].unk_14.y += unkStruct->unk_0000[i].unk_24;

        if ((unkStruct->unk_0000[i].unk_34 == 1) || (unkStruct->unk_0000[i].unk_34 == 2)) {
            for (j = i - 1; j >= 0; j--) {
                if ((unkStruct->unk_0000[j].unk_34 == 1) || (unkStruct->unk_0000[j].unk_34 == 2)) {
                    break;
                }
            }

            if (j < 0) {
                if (unkStruct->unk_0000[i].unk_14.y < 0.0f) {
                    unkStruct->unk_0000[i].unk_14.y = 0.0f;
                    unkStruct->unk_0000[i].unk_24 = 0.0f;
                    if (unkStruct->unk_0000[i].unk_2F & 1) {
                        unkStruct->unk_0000[i].unk_2F &= ~2;
                    } else {
                        unkStruct->unk_0000[i].unk_2F |= (2 | 1);
                    }
                } else {
                    unkStruct->unk_0000[i].unk_2F &= ~(2 | 1);
                }
            } else {
                if (unkStruct->unk_0000[i].unk_14.y <
                    (unkStruct->unk_0000[j].unk_14.y + ref_D_80A9D880[unkStruct->unk_0000[j].unk_00].unk_00)) {
                    unkStruct->unk_0000[i].unk_14.y =
                        unkStruct->unk_0000[j].unk_14.y + ref_D_80A9D880[unkStruct->unk_0000[j].unk_00].unk_00;
                    unkStruct->unk_0000[i].unk_24 = 0.0f;
                    if (unkStruct->unk_0000[i].unk_2F & 1) {
                        unkStruct->unk_0000[i].unk_2F &= ~2;
                    } else {
                        unkStruct->unk_0000[i].unk_2F |= (2 | 1);
                    }
                } else {
                    unkStruct->unk_0000[i].unk_2F &= ~(2 | 1);
                }
            }
        }

        if (unkStruct->unk_0000[i].unk_34 == 2) {
            if (Math3D_Dist1DSq(unkStruct->unk_0000[i].unk_14.x, unkStruct->unk_0000[i].unk_14.z) >
                SQ(440.0f) + 0.02f) {
                unkStruct->unk_0000[i].unk_34 = 3;
            }
        } else if (unkStruct->unk_0000[i].unk_34 == 3) {
            if (Math3D_Dist1DSq(unkStruct->unk_0000[i].unk_14.x, unkStruct->unk_0000[i].unk_14.z) > 278784.03f) {
                ref_func_80A9B554(this, play, unkStruct, &unkStruct->unk_0000[i]);
                Audio_PlaySfx_2(NA_SE_EV_GLASSBROKEN_IMPACT);
                unkStruct->unk_0000[i].unk_34 = 4;
                unkStruct->unk_0000[i].unk_30 = 30;
            }
        } else if (unkStruct->unk_0000[i].unk_34 == 4) {
            unkStruct->unk_0000[i].unk_30--;
            if (unkStruct->unk_0000[i].unk_30 <= 0) {
                unkStruct->unk_0000[i].unk_34 = 5;
            }
        }
    }
}
