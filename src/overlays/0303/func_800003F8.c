// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_skateblock.h"

s32 ref_func_80A21548(ObjSkateblock* this, PlayState* play) {
    s32 i;
    ObjSkateblockFloor* floor;

    this->unk_1C1 &= ~4;

    if (ref_func_80A21370(this, play)) {
        f32 maxHeight = BGCHECK_Y_MIN;
        s32 phi_v1 = false;
        f32 temp_f12 = this->dyna.actor.world.pos.y - 10.0f;

        for (i = 0; i < ARRAY_COUNT(this->unk_184); i++) {
            floor = &this->unk_184[i];
            if ((temp_f12 < floor->height) && (floor->height > maxHeight)) {
                maxHeight = floor->height;
                phi_v1 = true;
            }
        }

        if (phi_v1) {
            this->dyna.actor.world.pos.y = maxHeight;
            this->unk_1C1 |= 4;
            this->dyna.actor.velocity.y = 0.0f;
        }
        return phi_v1;
    }
    return false;
}
