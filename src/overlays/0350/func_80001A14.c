// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5CB74(EnKusa2* this) {
    static s8 ref_D_80A5EB4C = 0;
    s32 pad;
    Vec3f sp40;
    s16 sp3E;
    s16 sp3C;
    f32 sp38;
    s16 sp36;
    f32 temp_f0;

    sp40.x = this->actor.world.pos.x;
    sp40.y = this->actor.world.pos.y + 20.0f;
    sp40.z = this->actor.world.pos.z;
    sp3E = Rand_S16Offset(-10000, 20000) + this->actor.world.rot.y;

    if (this->unk_1C0 != NULL) {
        sp36 = Actor_WorldYawTowardActor(&this->actor, &this->unk_1C0->actor);
        sp3C = Rand_S16Offset(-4000, 8000) + sp36;
    } else {
        sp3C = 0;
    }

    ref_D_80A5EB4C++;
label:
    ref_D_80A5EB4C &= 0x7;

    temp_f0 = Rand_ZeroOne();
    if (ref_D_80A5EB4C == 0) {
        sp38 = temp_f0 * 0.70000005f;
    } else {
        sp38 = SQ(temp_f0) * 0.4f;
    }
    this->unk_1B8 = ref_func_80A5C104(&ref_D_80A5F1C0, &sp40, (Rand_ZeroOne() * 3.5f) + 4.0f, sp38, sp3E, sp3C);
}
