// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball2.h"

void ref_func_80B38EFC(ObjSnowball2* this, PlayState* play) {
    s32 pad;
    s32 i;
    Vec3f spA4;
    Vec3f sp98;
    Vec3f sp8C;
    f32 sp88 = this->actor.world.pos.y + (this->actor.shape.yOffset * this->actor.scale.y);

    for (i = 0; i < 2; i++) {
        sp8C.x = ((Rand_ZeroOne() * 30.0f) - 15.0f) + this->actor.world.pos.x;
        sp8C.y = ((Rand_ZeroOne() * 20.0f) - 10.0f) + sp88;
        sp8C.z = ((Rand_ZeroOne() * 30.0f) - 15.0f) + this->actor.world.pos.z;

        sp98.x = (Rand_ZeroOne() - 0.5f) * 1.6f;
        sp98.y = -1.5f;
        sp98.z = (Rand_ZeroOne() - 0.5f) * 1.6f;

        spA4.x = sp98.x * -0.06f;
        spA4.y = sp98.y * -0.06f;
        spA4.z = sp98.z * -0.06f;

        ref_func_800B0E48(play, &sp8C, &sp98, &spA4, &ref_D_80B3A914, &ref_D_80B3A918, (s32)(Rand_ZeroOne() * 40.0f) + 10,
                      (s32)(Rand_ZeroOne() * 30.0f) + 10);
    }
}
