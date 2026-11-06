// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

s32 ref_func_80A23F90(ObjIceblock* this, PlayState* play) {
    this->unk_1B0 &= ~4;

    if (ref_func_80A23D08(this, play)) {
        f32 phi_f2 = BGCHECK_Y_MIN;
        s32 ret = false;
        s32 i;
        ObjIceBlockUnkStruct2* ptr;

        for (i = 0; i < ARRAY_COUNT(this->unk_1F4); i++) {
            ptr = &this->unk_1F4[i];
            if (((this->dyna.actor.world.pos.y - 10.0f) < ptr->unk_04) && (phi_f2 < ptr->unk_04)) {
                phi_f2 = ptr->unk_04;
                ret = true;
            }
        }

        if (ret) {
            this->dyna.actor.world.pos.y = phi_f2;
            this->unk_1B0 |= 4;
            this->dyna.actor.velocity.y = 0.0f;
        }
        return ret;
    }
    return false;
}
