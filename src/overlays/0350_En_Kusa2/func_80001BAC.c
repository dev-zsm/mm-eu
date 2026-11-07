// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5CD0C(EnKusa2* this) {
    s32 i;
    Vec3f spA8;
    Vec3f sp9C;
    Vec3s sp94;
    Vec3s sp8C;
    f32 temp_f20;
    s16 temp_s0;
    s32 pad;

    for (i = 0; i < 2; i++) {
        temp_s0 = Rand_Next() & 0xFFFF;
        temp_f20 = Rand_ZeroOne() * 30.0f;

        spA8.x = Math_SinS(temp_s0) * temp_f20;
        spA8.y = Rand_ZeroOne() * 30.0f;
        spA8.z = Math_CosS(temp_s0) * temp_f20;

        sp9C.x = ((Rand_ZeroOne() * 4.0f) - 2.0f) + (spA8.x * 0.18f);
        sp9C.y = (Rand_ZeroOne() * 8.0f) + 3.0f;
        sp9C.z = ((Rand_ZeroOne() * 4.0f) - 2.0f) + (spA8.z * 0.18f);

        spA8.x += this->actor.world.pos.x;
        spA8.y += this->actor.world.pos.y;
        spA8.z += this->actor.world.pos.z;

        sp94.x = Rand_Next() & 0xFFFF;
        sp94.y = Rand_Next() & 0xFFFF;
        sp94.z = Rand_Next() & 0xFFFF;

        sp8C.x = (Rand_Next() % 0x4000) - 0x1FFF;
        sp8C.y = (Rand_Next() % 0x2000) - 0xFFF;
        sp8C.z = (Rand_Next() % 0x4000) - 0x1FFF;

        ref_func_80A5C2FC(&ref_D_80A5F1C0, (Rand_ZeroOne() * 0.4f) + 0.02f, &spA8, &sp9C, &sp94, &sp8C);
    }
}
