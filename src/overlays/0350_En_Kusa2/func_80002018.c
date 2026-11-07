// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5D178(EnKusa2* this) {
    s32 i;
    Vec3f spB0;
    Vec3f spA4;
    Vec3s sp9C;
    Vec3s sp94;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    s16 temp_s0;
    s32 pad;

    for (i = 0; i < 8; i++) {
        temp_s0 = Rand_Next();
        temp_f22 = Math_SinS(temp_s0);
        temp_f20 = Math_CosS(temp_s0);
        temp_f24 = (Rand_ZeroOne() * 40.0f) + 10.0f;

        spB0.x = temp_f24 * temp_f22;
        spB0.y = Rand_ZeroOne() * 30.0f;
        spB0.z = temp_f24 * temp_f20;

        spA4.x = ((Rand_ZeroOne() * 6.0f) - 3.0f) + ((temp_f20 * 6.0f) + (spB0.x * 0.1f));
        spA4.y = (Rand_ZeroOne() * 3.0f) + 1.0f;
        spA4.z = ((Rand_ZeroOne() * 6.0f) - 3.0f) + ((temp_f22 * -6.0f) + (spB0.z * 0.1f));

        spB0.x += this->actor.world.pos.x;
        spB0.y += this->actor.world.pos.y;
        spB0.z += this->actor.world.pos.z;

        sp9C.x = Rand_Next() & 0xFFFF;
        sp9C.y = Rand_Next() & 0xFFFF;
        sp9C.z = Rand_Next() & 0xFFFF;

        sp94.x = Rand_S16Offset(-12000, 24000);
        sp94.y = (Rand_Next() % 0x4000) - 0x1FFF;
        sp94.z = Rand_S16Offset(-12000, 24000);
        ref_func_80A5C2FC(&ref_D_80A5F1C0, (Rand_ZeroOne() * 0.38f) + 0.02f, &spB0, &spA4, &sp9C, &sp94);
    }
}
