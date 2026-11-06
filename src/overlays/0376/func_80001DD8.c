// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9CAA8(BgHakuginPost* this, PlayState* play) {
    s32 pad[2];
    s32 i;

    this->unk_160 = ref_func_80A9B244(&ref_D_80A9E028);
    Math_Vec3f_Copy(&this->dyna.actor.home.pos, &ref_D_80A9E028.unk_0000[0].unk_08);
    Math_Vec3f_Copy(&this->dyna.actor.world.pos, &this->dyna.actor.home.pos);
    this->unk_168 = this->dyna.actor.home.pos.y;

    if (1) {}

    this->unk_164 = this->unk_168 - 1800.0f;
    if (this->unk_170 != 0) {
        for (i = 0; i < ref_D_80A9E028.count; i++) {
            ref_D_80A9E028.unk_0000[i].unk_08.x -= this->dyna.actor.home.pos.x;
            ref_D_80A9E028.unk_0000[i].unk_08.y -= this->dyna.actor.home.pos.y;
            ref_D_80A9E028.unk_0000[i].unk_08.z -= this->dyna.actor.home.pos.z;

            ref_D_80A9E028.unk_0000[i].unk_14.x = ref_D_80A9E028.unk_0000[i].unk_08.x;
            ref_D_80A9E028.unk_0000[i].unk_14.y = ref_D_80A9E028.unk_0000[i].unk_08.y;
            ref_D_80A9E028.unk_0000[i].unk_14.z = ref_D_80A9E028.unk_0000[i].unk_08.z;
        }
    } else {
        f32 phi_f0 = 0.0f;

        for (i = 0; i < ref_D_80A9E028.count; i++) {
            ref_D_80A9E028.unk_0000[i].unk_08.x -= this->dyna.actor.home.pos.x;
            ref_D_80A9E028.unk_0000[i].unk_08.y -= this->dyna.actor.home.pos.y;
            ref_D_80A9E028.unk_0000[i].unk_08.z -= this->dyna.actor.home.pos.z;

            ref_D_80A9E028.unk_0000[i].unk_14.x = ref_D_80A9E028.unk_0000[i].unk_08.x;
            ref_D_80A9E028.unk_0000[i].unk_14.y = phi_f0;
            ref_D_80A9E028.unk_0000[i].unk_14.z = ref_D_80A9E028.unk_0000[i].unk_08.z;

            if (ref_D_80A9E028.unk_0000[i].unk_34 == 1) {
                phi_f0 += ref_D_80A9D880[ref_D_80A9E028.unk_0000[i].unk_00].unk_00;
            }
        }
    }

    ref_func_80A9AD18(this, play, &ref_D_80A9E028);
    this->dyna.actor.draw = ref_func_80A9D61C;
    if (this->unk_170 != 0) {
        ref_func_80A9CC84(this);
    } else {
        ref_func_80A9CE00(this);
    }
}
