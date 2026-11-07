// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bell.h"

s32 ref_func_80A35510(ObjBell* this, s32 arg1) {
    Vec3f bumperPos;
    Vec3f worldPos;
    s32 phi_a3 = false;

    if (((arg1 == 0) && (this->unk_21C < 1000.0f)) || ((arg1 == 1) && (this->unk_21C < 4000.0f)) || (arg1 == 2)) {
        phi_a3 = true;
    }

    switch (arg1) {
        case 0:
            this->unk_21C += ((this->unk_21C > 1000.0f) ? 250.0f : 1000.0f);
            break;

        case 1:
            this->unk_21C += ((this->unk_21C > 3000.0f) ? 750.0f : 3000.0f);
            break;

        case 2:
            this->unk_21C += 9000.0f;
            break;
    }

    this->unk_21C = CLAMP(this->unk_21C, 0.0f, 18000.0f);
    if (phi_a3 == true) {
        Math_Vec3s_ToVec3f(&bumperPos, &this->collider2.elem.acDmgInfo.hitPos);
        Math_Vec3f_Copy(&worldPos, &this->dyna.actor.world.pos);
        this->dyna.actor.world.rot.y = Math_Vec3f_Yaw(&bumperPos, &worldPos);
        if (this->unk_20C <= 0x4000 && this->unk_20C >= -0x4000) {
            this->unk_20C -= 0x4000;
        } else {
            this->unk_20C += 0x4000;
        }
    }
    return phi_a3;
}
