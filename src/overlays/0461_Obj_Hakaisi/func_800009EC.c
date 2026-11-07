// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hakaisi.h"

void ref_func_80B14B6C(ObjHakaisi* this, PlayState* play, Vec3f vec, s16 arg3) {
    s32 i;
    s16 temp_s1;
    Vec3f sp6C;

    Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_WALL_BROKEN);

    for (i = 0; i < 5; i++) {
        temp_s1 = Rand_Next();

        sp6C.x = (Math_SinS(temp_s1) * 15.0f) + vec.x;
        sp6C.y = (Rand_ZeroOne() * 3.0f) + vec.y;
        sp6C.z = (Math_CosS(temp_s1) * 15.0f) + vec.z;

        EffectSsHahen_SpawnBurst(play, &sp6C, 10.0f, 0, arg3, 30, 2, OBJECT_HAKAISI, 15, object_hakaisi_DL_0021B0);
    }

    ref_func_80B14CF8(play, vec, 100, 50, 20);
}
