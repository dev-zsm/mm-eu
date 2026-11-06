// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_sda.h"

void ref_func_809469C0(Player* player, u8* shadowTexture, f32 arg2) {
    s16 temp_t0;
    s16 temp_t1;
    s16 temp_v1;
    s16 temp_v0;
    s16 phi_a0;
    s16 phi_a3;
    s16 i;
    s16 j;
    Vec3f lerp;
    Vec3f sp88;
    Vec3f sp7C;

    for (i = 0; i < 16; i++) {
        
        if ((arg2 == 0.0f) || ((j = ref_D_80947ACC[i]) >= 0)) {
            if (arg2 > 0.0f) {
                lerp.x = ref_D_80947EA0[i].x + (ref_D_80947EA0[j].x - ref_D_80947EA0[i].x) * arg2;
                lerp.y = ref_D_80947EA0[i].y + (ref_D_80947EA0[j].y - ref_D_80947EA0[i].y) * arg2;
                lerp.z = ref_D_80947EA0[i].z + (ref_D_80947EA0[j].z - ref_D_80947EA0[i].z) * arg2;

                sp88.x = lerp.x - player->actor.world.pos.x;
                sp88.y = lerp.y - player->actor.world.pos.y + BREG(48) + 76.0f + 30.0f - 105.0f + 15.0f;
                sp88.z = lerp.z - player->actor.world.pos.z;
            } else {
                sp88.x = ref_D_80947EA0[i].x - player->actor.world.pos.x;
                sp88.y = ref_D_80947EA0[i].y - player->actor.world.pos.y + BREG(48) + 76.0f + 30.0f - 105.0f + 15.0f;
                sp88.z = ref_D_80947EA0[i].z - player->actor.world.pos.z;
            }

            Matrix_MultVec3f(&sp88, &sp7C);
            sp7C.x *= (1.0f + (BREG(49) / 100.0f));
            sp7C.y *= (1.0f + (BREG(49) / 100.0f));
            temp_t0 = sp7C.x + 32.0f;
            temp_t1 = sp7C.y * 64.0f;

            if (ref_D_80947AEC[i] == 2) {
                for (j = 0, phi_a3 = -384; j < 12; j++, phi_a3 += 64) {
                    for (phi_a0 = -ref_D_80947A98[j]; phi_a0 < ref_D_80947A98[j]; phi_a0++) {
                        temp_v1 = temp_t0 + phi_a0;
                        if ((temp_v1 >= 0) && (temp_v1 < 64)) {
                            temp_v0 = temp_t1 + phi_a3;
                            if ((temp_v0 >= 0) && (temp_v0 < 0x1000)) {
                                shadowTexture[temp_v1 + temp_v0] = 255;
                            }
                        }
                    }
                }
            } else if (ref_D_80947AEC[i] == 1) {
                for (j = 0, phi_a3 = -256; j < 8; j++, phi_a3 += 64) {
                    for (phi_a0 = -ref_D_80947A88[j]; phi_a0 < ref_D_80947A88[j]; phi_a0++) {
                        temp_v1 = temp_t0 + phi_a0;
                        if ((temp_v1 >= 0) && (temp_v1 < 64)) {
                            temp_v0 = temp_t1 + phi_a3;
                            if ((temp_v0 >= 0) && (temp_v0 < 0x1000)) {
                                shadowTexture[temp_v1 + temp_v0] = 255;
                            }
                        }
                    }
                }
            } else if (ref_D_80947AEC[i] == 0) {
                for (j = 0, phi_a3 = -192; j < 7; j++, phi_a3 += 64) {
                    for (phi_a0 = -ref_D_80947A78[j]; phi_a0 < ref_D_80947A78[j] - 1; phi_a0++) {
                        temp_v1 = temp_t0 + phi_a0;
                        if ((temp_v1 >= 0) && (temp_v1 < 64)) {
                            temp_v0 = temp_t1 + phi_a3;
                            if ((temp_v0 >= 0) && (temp_v0 < 0x1000)) {
                                shadowTexture[temp_v1 + temp_v0] = 255;
                            }
                        }
                    }
                }
            } else if (ref_D_80947AEC[i] == 4) {
                for (j = 0, phi_a3 = -448; j < 14; j++, phi_a3 += 64) {
                    for (phi_a0 = -ref_D_80947AB0[j]; phi_a0 < ref_D_80947AB0[j]; phi_a0++) {
                        temp_v1 = temp_t0 + phi_a0;
                        if ((temp_v1 >= 0) && (temp_v1 < 64)) {
                            temp_v0 = temp_t1 + phi_a3;
                            if ((temp_v0 >= 0) && (temp_v0 < 0x1000)) {
                                shadowTexture[temp_v1 + temp_v0] = 255;
                            }
                        }
                    }
                }
            } else {
                for (j = 0, phi_a3 = -128; j < 6; j++, phi_a3 += 64) {
                    for (phi_a0 = -ref_D_80947A6C[j]; phi_a0 < ref_D_80947A6C[j] - 1; phi_a0++) {
                        temp_v1 = temp_t0 + phi_a0;
                        if ((temp_v1 >= 0) && (temp_v1 < 64)) {
                            temp_v0 = temp_t1 + phi_a3;
                            if ((temp_v0 >= 0) && (temp_v0 < 0x1000)) {
                                shadowTexture[temp_v1 + temp_v0] = 255;
                            }
                        }
                    }
                }
            }
        }
    }
}
