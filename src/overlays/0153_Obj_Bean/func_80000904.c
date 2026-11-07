// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bean.h"

void ref_func_809375F4(ObjBean* this, PlayState* play) {
    static Gfx* ref_D_80939024[] = {
        gKakeraLeafMiddleDL,
        gKakeraLeafTipDL,
    };
    Vec3f spC4;
    Vec3f spB8;
    f32 temp_f20;
    s32 temp_s2;
    s16 temp_s1 = 0;
    s32 phi_s3;
    s32 phi_v0;
    s32 i;

    for (i = 0; i < 36; i++) {
        temp_s1 += 0x4E20;
        temp_f20 = Rand_ZeroOne() * 60.0f;

        spC4.x = (Math_SinS(temp_s1) * temp_f20) + this->dyna.actor.world.pos.x;
        spC4.y = this->dyna.actor.world.pos.y;
        spC4.z = (Math_CosS(temp_s1) * temp_f20) + this->dyna.actor.world.pos.z;

        spB8.x = Math_SinS(temp_s1) * 3.5f;
        spB8.y = Rand_ZeroOne() * 13.0f;
        spB8.z = Math_CosS(temp_s1) * 3.5f;

        spB8.x += this->dyna.actor.world.pos.x - this->dyna.actor.prevPos.x;
        spB8.y += this->dyna.actor.world.pos.y - this->dyna.actor.prevPos.y;
        spB8.z += this->dyna.actor.world.pos.z - this->dyna.actor.prevPos.z;

        temp_s2 = (s32)(Rand_ZeroOne() * 180.0f) + 30;

        phi_v0 = 0x40;
        if (temp_s2 < 0x5A) {
            phi_s3 = -0x50;
            if (Rand_ZeroOne() < 0.1f) {
                phi_v0 = 0x60;
            } else {
                phi_v0 = 0x40;
            }
        } else {
            phi_s3 = -100;
            phi_v0 = 0x40;
        }
        EffectSsKakera_Spawn(play, &spC4, &spB8, &spC4, phi_s3, phi_v0, 40, 3, 0, temp_s2, 0, 0, (temp_s2 >> 3) + 40,
                             -1, GAMEPLAY_KEEP, ref_D_80939024[i & 1]);
    }
}
