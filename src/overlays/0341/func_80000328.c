// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_dnb.h"

s32 ref_func_80A500F8(EnDnb* this) {
    static Vec3f ref_D_80A50CB0 = { 0.0f, 0.0f, 1000.0f };
    Actor* actor = &this->dyna.actor;
    Vec3f spA8 = gZeroVec3f;
    Vec3f sp9C;
    s32 i;
    f32 temp_f20;

    for (i = 0; i < 16; i++) {
        Lib_Vec3f_TranslateAndRotateY(&actor->world.pos, i * 4096, &ref_D_80A50CB0, &spA8);
        temp_f20 = Rand_ZeroOne() * 240.0f;
        sp9C.x = Math_SinS(i * 4096) * temp_f20;
        sp9C.z = Math_CosS(i * 4096) * temp_f20;
        sp9C.y = Rand_ZeroOne() * 180.0f;
        ref_func_80A507C0(this->unk_0D38, spA8, sp9C, 16, 50.0f, 30.0f);
    }

    return i;
}
