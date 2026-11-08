// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void ref_func_80940090(EnGoroiwa* this, PlayState* play) {
    s32 pad[3];
    s32 sp120 = ENGOROIWA_GET_C000(&this->actor);
    s32 phi_s0;
    s32 phi_s3;
    Vec3f sp10C;
    Vec3f sp100;
    Vec3f spF4;
    s32 phi_s6;
    f32 spEC;
    Gfx* phi_s1;
    s16 phi_s7;
    f32 phi_f22;
    s32 phi_s2;
    s32 spD8;
    s16 spA8;
    f32 temp_f20;
    s32 i;

    if (!(this->actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME)) {
        return;
    }

    spEC = (this->actor.scale.x + 0.1f) * 0.5f;
    sp10C.x = this->actor.world.pos.x;
    sp10C.y = this->actor.world.pos.y + this->unk_1DC;
    sp10C.z = this->actor.world.pos.z;
    spD8 = spEC * 150.0f;
    spA8 = 0x10000 / spD8;

    for (i = 0, phi_s7 = 0; i < spD8; i++, phi_s7 += spA8) {
        if ((i & 3) == 0) {
            phi_f22 = 1.0f;
            phi_s1 = ref_D_80942E0C[sp120][2];
            phi_s2 = -0x118;
            phi_s3 = 0;
            phi_s0 = 0x40;
        } else {
            phi_s2 = -0x190;
            if ((i & 3) == 1) {
                phi_s1 = ref_D_80942E0C[sp120][1];
                phi_s2 = -0x154;
                phi_s3 = 0;
                phi_f22 = 0.9f;
                if (Rand_ZeroOne() < 0.4f) {
                    phi_s0 = 0x20;
                } else {
                    phi_s0 = 0x40;
                }
            } else {
                phi_s1 = ref_D_80942E0C[sp120][0];
                phi_s3 = 1;
                phi_f22 = 0.8f;
                if ((s32)Rand_Next() > 0) {
                    phi_s0 = 0x21;
                } else {
                    phi_s0 = 0x41;
                }
            }
        }

        temp_f20 = (Rand_ZeroOne() * this->actor.scale.x * 400.0f) + 20.0f;

        sp100.x = Math_SinS((s32)(Rand_ZeroOne() * spA8) + phi_s7) * temp_f20;
        sp100.y = (Rand_ZeroOne() - 0.4f) * temp_f20 * 1.6666666f;
        sp100.z = Math_CosS((s32)(Rand_ZeroOne() * spA8) + phi_s7) * temp_f20;

        spF4.x = sp100.x * 0.16f * phi_f22;
        spF4.y = (Rand_ZeroOne() * 16.0f) + 3.0f;
        spF4.z = sp100.z * 0.16f * phi_f22;

        Math_Vec3f_Sum(&sp100, &sp10C, &sp100);
        EffectSsKakera_Spawn(play, &sp100, &spF4, &sp100, phi_s2, phi_s0, 30, 0, 0,
                             ((Rand_ZeroOne() * 150.0f) + 300.0f) * this->actor.scale.x, phi_s3, 0, 0x32, -1,
                             OBJECT_GOROIWA, phi_s1);

        if (this->unk_1E6) {
            continue;
        }

        sp100.x += ((Rand_ZeroOne() * 1200.0f) - 600.0f) * this->actor.scale.x;
        sp100.y += ((Rand_ZeroOne() * 1400.0f) - 600.0f) * this->actor.scale.y;
        sp100.z += ((Rand_ZeroOne() * 1200.0f) - 600.0f) * this->actor.scale.z;

        ref_func_800B0E48(play, &sp100, &ref_D_80942E48, &ref_D_80942E54, &ref_D_80942E30[sp120], &ref_D_80942E3C[sp120],
                      (Rand_ZeroOne() * 50.0f) + (400.0f * spEC), (Rand_ZeroOne() * 60.0f) + (500.0f * spEC));
    }

    if (this->unk_1E6) {
        ref_func_8093FC6C(this, play);
    }
}
