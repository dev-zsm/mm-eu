// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_sda.h"

void ref_func_8094702C(EnSda* this, u8* shadowTexture, Player* player, PlayState* play) {
    s16 temp_t0;
    s16 temp_t1;
    s16 temp_v0;
    s16 temp_v1;
    s16 phi_a0;
    s16 phi_a3;
    s16 i;
    s16 j;
    Vec3f sp194;
    Vec3f sp188;
    s32* shadowTextureTemp32;
    u8* shadowTextureTemp;
    Vec3s sp178;
    Vec3f sp16C;
    Vec3f sp64[22];

    if (BREG(57) != 0) {
        for (shadowTextureTemp = shadowTexture, i = 0; i < 0x1000; i++, shadowTextureTemp++) {
            if (((i >= 0) && (i < 0x40)) || ((i >= 0xFC0) && (i < 0x1000)) || ((i & 0x3F) == 0) ||
                ((i & 0x3F) == 0x3F)) {
                *shadowTextureTemp = 255;
            } else {
                *shadowTextureTemp = 0;
            }
        }
    } else {
        for (shadowTextureTemp32 = (s32*)shadowTexture, i = 0; i < 0x400; i++, shadowTextureTemp32++) {
            *shadowTextureTemp32 = 0;
        }
    }

    Matrix_RotateXFNew((BREG(50) + 70) / 100.0f);

    for (i = 0; i < PLAYER_BODYPART_MAX; i++) {
        if (ref_D_80947AFC[i] >= 0) {
            ref_D_80947EA0[ref_D_80947AFC[i]] = player->bodyPartsPos[i];
        }
    }

    ref_D_80947EA0[0].y += 3.0f;
    ref_D_80947EA0[15].x = ref_D_80947EA0[0].x + ((ref_D_80947EA0[15].x - ref_D_80947EA0[0].x) * 1.2f);
    ref_D_80947EA0[15].y = ref_D_80947EA0[0].y + ((ref_D_80947EA0[15].y - ref_D_80947EA0[0].y) * -1.2f);
    ref_D_80947EA0[15].z = ref_D_80947EA0[0].z + ((ref_D_80947EA0[15].z - ref_D_80947EA0[0].z) * 1.2f);

    for (i = 0; i < 6; i++) {
        ref_func_809469C0(player, shadowTexture, i / 5.0f);
    }

    if (this->actor.params != ENSDA_1) {
        Matrix_MtxFToYXZRot(&player->shieldMf, &sp178, false);

        sp178.y += (KREG(87) * 0x8000) + 0x8000;
        sp178.x *= (KREG(88) - 1);

        Matrix_Mult(&player->shieldMf, MTXMODE_NEW);
        Matrix_MultVec3f(&ref_D_80947A60, &sp16C);
        Matrix_RotateYS(sp178.y, MTXMODE_NEW);
        Matrix_RotateXS(sp178.x, MTXMODE_APPLY);

        for (i = 0; i < 22; i++) {
            Matrix_MultVec3f(&ref_D_80947B10[i], &sp188);
            sp64[i].x = (((KREG(82) / 100.0f) + 4.0f) * sp188.x) + sp16C.x;
            sp64[i].y = (((KREG(82) / 100.0f) + 4.0f) * sp188.y) + sp16C.y;
            sp64[i].z = (((KREG(82) / 100.0f) + 4.0f) * sp188.z) + sp16C.z;
        }

        Matrix_RotateXFNew((BREG(50) + 70) / 100.0f);

        for (i = 0; i < 22; i++) {
            sp194.x = sp64[i].x - player->actor.world.pos.x;
            sp194.y = sp64[i].y - player->actor.world.pos.y + KREG(80) + 16.0f;
            sp194.z = sp64[i].z - player->actor.world.pos.z;

            Matrix_MultVec3f(&sp194, &sp188);

            sp188.x *= (1.0f + (KREG(90) / 100.0f));
            sp188.y *= (1.0f + (KREG(90) / 100.0f));
            temp_t0 = sp188.x + 32.0f;
            temp_t1 = sp188.y * 64.0f;

            do {
                for (j = 0, phi_a3 = -0xC0; j < 7; j++, phi_a3 += 0x40) {
                    for (phi_a0 = -ref_D_80947A78[j]; phi_a0 < ref_D_80947A78[j] - 1; phi_a0++) {
                        temp_v0 = temp_t0 + phi_a0;
                        if ((temp_v0 >= 0) && (temp_v0 < 0x40)) {
                            temp_v1 = temp_t1 + phi_a3;
                            if ((temp_v1 >= 0) && (temp_v1 < 0x1000)) {
                                shadowTexture[temp_v0 + temp_v1] = 255;
                            }
                        }
                    }
                }
                j++;
            } while (j < 6);
        }
    }

    if (BREG(61) == 1) {
        for (shadowTextureTemp = shadowTexture, i = 0; i < 0x1000; i++, shadowTextureTemp++) {
            if (*shadowTextureTemp != 0) {
                *shadowTextureTemp = -((i >> 6) * (BREG(60) + 4)) + (255 - BREG(61));
            }
        }
    }
}
