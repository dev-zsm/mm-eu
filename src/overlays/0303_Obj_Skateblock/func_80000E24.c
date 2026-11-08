// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_skateblock.h"

void ref_func_80A21F74(ObjSkateblock* this, PlayState* play) {
    s32 pad;
    Vec3f spA8;
    Vec3f sp9C;
    f32 phi_f22;
    s32 i;
    f32 temp;
    s32 pad2;
    s16 sp8A = this->dyna.yRotation;

    if (this->dyna.pushForce < 0.0f) {
        sp8A -= 0x8000;
    }

    this->unk_17C++;

    if (this->dyna.actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) {
        if (this->unk_17C >= 46) {
            phi_f22 = 1.0f;
        } else {
            phi_f22 = (this->unk_17C * 0.017777778f) + 0.2f;
        }
        sp9C.y = 12.0f;

        for (i = 0; i < 2; i++) {
            if (phi_f22 < (Rand_ZeroOne() * 1.2f)) {
                continue;
            }
            this->unk_180 += Rand_ZeroOne();

            if (this->unk_180 > 1.0f) {
                this->unk_180 -= 1.0f;
            }

            sp9C.x = (this->unk_180 - 0.5f) * 600.0f * this->dyna.actor.scale.x;
            sp9C.z = (this->dyna.actor.scale.z * -300.0f) + 4.0f;

            ref_func_80A212F0(&spA8, &sp9C, sp8A);

            spA8.x += this->dyna.actor.world.pos.x;
            spA8.y += this->dyna.actor.world.pos.y;
            spA8.z += this->dyna.actor.world.pos.z;

            temp = ((Rand_ZeroOne() * 800.0f) + (1600.0f * this->dyna.actor.scale.x)) * phi_f22;
            ref_func_800B0E48(play, &spA8, &gZeroVec3f, &ref_D_80A22ACC, &ref_D_80A22AD8, &ref_D_80A22ADC, temp,
                          (Rand_ZeroOne() * 20.0f) + 30.0f);
        }
    }
}
