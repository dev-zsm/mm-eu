// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball.h"

void ref_func_80B030F8(ObjSnowball* this, PlayState* play) {
    s32 pad;
    f32 temp_f28 = sqrtf(this->unk_20C);
    Vec3f spFC;
    Vec3f spF0;
    Vec3f spE4;
    s32 i;
    s32 phi_s6;
    Gfx* temp_s2;
    s16 scale;
    s32 temp_s1;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f26;
    s16 temp_s0;
    s32 temp_s7;
    f32 phi_f22;
    s32 gravity;
    s32 phi_s0;
    s32 phi_s4;

    for (i = 0, phi_s6 = 0; i < 25; i++, phi_s6 += 0xA3D) {
        temp_s7 = i & 7;
        if (temp_s7 < 4) {
            temp_s2 = ref_D_80B04FC8[2];
            gravity = -280;
            phi_s4 = 0;
            phi_s0 = 0x40;
            phi_f22 = 1.0f;
        } else if (temp_s7 < 6) {
            temp_s2 = ref_D_80B04FC8[1];
            gravity = -340;
            phi_s4 = 0;
            phi_f22 = 0.9f;
            if (Rand_ZeroOne() < 0.4f) {
                phi_s0 = 0x20;
            } else {
                phi_s0 = 0x40;
            }
        } else {
            temp_s2 = ref_D_80B04FC8[0];
            gravity = -400;
            phi_s4 = 1;
            phi_f22 = 0.8f;
            if ((s32)Rand_Next() > 0) {
                phi_s0 = 0x21;
            } else {
                phi_s0 = 0x41;
            }
        }

        temp_f20 = (Rand_ZeroOne() * (40.0f * this->unk_20C)) + 20.0f;

        spFC.x = Math_SinS((s32)(Rand_ZeroOne() * 2621.44f) + phi_s6) * temp_f20;
        spFC.y = (Rand_ZeroOne() - 0.4f) * temp_f20 * 1.6666666f;
        spFC.z = Math_CosS((s32)(Rand_ZeroOne() * 2621.44f) + phi_s6) * temp_f20;

        spF0.x = spFC.x * 0.16f * phi_f22;
        spF0.y = (Rand_ZeroOne() * 16.0f) + 3.0f;
        spF0.z = spFC.z * 0.16f * phi_f22;

        spFC.x += this->actor.world.pos.x;
        spFC.y += this->actor.world.pos.y;
        spFC.z += this->actor.world.pos.z;

        scale = ((Rand_ZeroOne() * 15.0f) + 30.0f) * this->unk_20C;

        EffectSsKakera_Spawn(play, &spFC, &spF0, &spFC, gravity, phi_s0, 30, 0, 0, scale, phi_s4, 0, 50, -1,
                             OBJECT_GOROIWA, temp_s2);
        if ((this->unk_210 == 0) && (temp_s7 >= 3)) {
            spFC.x += (Rand_ZeroOne() * 120.0f) - 60.0f;
            spFC.y += Rand_ZeroOne() * 80.0f;
            spFC.z += (Rand_ZeroOne() * 120.0f) - 60.0f;

            temp_s0 = (s32)(Rand_ZeroOne() * 50.0f * temp_f28) + 40;
            temp_s1 = (s32)(Rand_ZeroOne() * 60.0f * temp_f28) + 50;
            ref_func_800B0E48(play, &spFC, &gZeroVec3f, &ref_D_80B04FBC, &ref_D_80B04FB4, &ref_D_80B04FB8, temp_s0, temp_s1);
        }
    }

    if (this->unk_210 != 0) {
        temp_f26 = this->unk_20C * 60.0f;

        for (i = 0, phi_s6 = 0; i < 16; i++, phi_s6 += 0x1000) {
            temp_s0 = Rand_Next() >> 0x10;
            temp_f20 = Math_SinS(temp_s0);
            temp_f22 = Math_CosS(temp_s0);

            spFC.x = Math_SinS(phi_s6);
            spFC.z = Math_CosS(phi_s6);

            spF0.x = 2.0f * spFC.x;
            spF0.y = (2.0f * Rand_ZeroOne()) + 1.0f;
            spF0.z = 2.0f * spFC.z;

            spFC.x *= temp_f22 * temp_f26;
            spFC.y = temp_f20 * temp_f26;
            spFC.z *= temp_f22 * temp_f26;

            spFC.x += this->actor.world.pos.x;
            spFC.y += this->actor.world.pos.y;
            spFC.z += this->actor.world.pos.z;

            spE4.x = spF0.x * -0.02f;
            spE4.y = spF0.y * -0.05f;
            spE4.z = spF0.z * -0.02f;

            EffectSsIceSmoke_Spawn(play, &spFC, &spF0, &spE4, ((s32)(Rand_ZeroOne() * 170.0f) + 150) * temp_f28);
        }
    }
}
