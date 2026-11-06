// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_spinyroll.h"

s32 ref_func_80A1E648(ObjSpinyroll* this, PlayState* play, s32 arg2) {
    f32 sp1C;

    if (ref_func_80A1E3D8(this, play, &sp1C, arg2)) {
        this->dyna.actor.world.pos.y += sp1C;
        return true;
    }
    return false;
}
