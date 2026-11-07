// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hakaisi.h"

void ref_func_80B14A24(ObjHakaisi* this, PlayState* play, Vec3f vec) {
    s32 i;

    ref_func_80B14CF8(play, vec, 100, 30, 5);

    for (i = 0; i < 5; i++) {
        vec.x += Rand_Centered() * 20.0f;
        vec.y += Rand_ZeroOne() * 5.0f;
        vec.z += Rand_Centered() * 20.0f;
        EffectSsHahen_SpawnBurst(play, &vec, 5.0f, 0, 20, 15, 3, OBJECT_HAKAISI, 10, object_hakaisi_DL_0021B0);
    }
}
