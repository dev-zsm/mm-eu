// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9C634(BgHakuginPost* this, PlayState* play) {
    s32 i;
    Vec3f spB8;
    Vec3f spAC;
    Vec3f spA0;
    s32 pad[2];
    s32 temp_s4;
    f32 temp_f20;

    for (i = 0; i < 70; i++) {
        temp_s4 = (s32)(Rand_ZeroOne() * 6553.0f) + i * 0x1999;
        temp_f20 = ((Rand_ZeroOne() * 0.3f) + 1.0f) * 220.0f;

        spB8.x = Math_SinS(temp_s4);
        spB8.y = i * -(60.0f / 7.0f);
        spB8.z = Math_CosS(temp_s4);

        spAC.x = spB8.x * 19.0f;
        spAC.y = 0.0f;
        spAC.z = spB8.z * 19.0f;

        spB8.x = (spB8.x * temp_f20) + this->dyna.actor.home.pos.x;
        spB8.y += this->unk_164 + this->unk_160;
        spB8.z = (spB8.z * temp_f20) + this->dyna.actor.home.pos.z;

        spA0.x = spAC.x * -0.08f;
        spA0.y = 0.8f;
        spA0.z = spAC.z * -0.08f;
        ref_func_800B0DE0(play, &spB8, &spAC, &spA0, &ref_D_80A9D8E4, &ref_D_80A9D8E8, (s32)(Rand_ZeroOne() * 400.0f) + 2500, -250);
    }
}
