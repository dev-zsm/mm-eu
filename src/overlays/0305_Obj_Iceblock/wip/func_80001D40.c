// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A24DD0(ObjIceblock* this, PlayState* play) {
    static Vec3f ref_D_80A26F90 = { 0.0f, 0.3f, 0.0f };
    static Color_RGBA8 ref_D_80A26F9C = { 250, 250, 250, 255 };
    static Color_RGBA8 ref_D_80A26FA0 = { 180, 180, 180, 255 };
    s32 pad;
    Vec3f spA8;
    Vec3f sp9C;
    s32 i;
    f32 temp_f20;
    f32 phi_f22;
    s32 pad2;
    s16 sp8A;

    sp8A = this->dyna.yRotation;
    if (this->dyna.pushForce < 0.0f) {
        sp8A -= 0x8000;
    }

    this->unk_2A2++;
    if (this->dyna.actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) {
        if (this->unk_2A2 >= 0x2E) {
            phi_f22 = 1.0f;
        } else {
            phi_f22 = (this->unk_2A2 * 0.017777778f) + 0.2f;
        }
        sp9C.y = 12.0f;

        for (i = 0; i < 2; i++) {
            if (phi_f22 < (Rand_ZeroOne() * 1.2f)) {
                continue;
            }

            this->unk_2A4 += Rand_ZeroOne();
            if (this->unk_2A4 > 1.0f) {
                this->unk_2A4 -= 1.0f;
            }

            sp9C.x = (this->unk_2A4 - 0.5f) * 600.0f * this->dyna.actor.scale.x;
            sp9C.z = (this->dyna.actor.scale.z * -300.0f) + 4.0f;

            ref_func_80A2311C(&spA8, &sp9C, sp8A);

            spA8.x += this->dyna.actor.world.pos.x;
            spA8.y += this->dyna.actor.world.pos.y;
            spA8.z += this->dyna.actor.world.pos.z;

            temp_f20 = ((Rand_ZeroOne() * 800.0f) + (1600.0f * this->dyna.actor.scale.x)) * phi_f22;
            ref_func_800B0E48(play, &spA8, &gZeroVec3f, &ref_D_80A26F90, &ref_D_80A26F9C, &ref_D_80A26FA0, temp_f20,
                          (Rand_ZeroOne() * 20.0f) + 30.0f);
        }
    }
}
