// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

s32 ref_func_80A24954(ObjIceblock* this, PlayState* play) {
    s32 pad[2];
    s8 sp27 = this->unk_2B0;
    f32 temp = (this->dyna.actor.scale.y * 600.0f) - 90.0f;

    if ((this->unk_244 > BGCHECK_Y_MIN + 1) && (temp < (this->unk_244 - this->dyna.actor.world.pos.y))) {
        ref_func_80A262BC(this);
        this->unk_2B0 = 3;
    } else if (this->unk_1B0 & 4) {
        if (SurfaceType_GetFloorType(&play->colCtx, this->dyna.actor.floorPoly, this->dyna.actor.floorBgId) ==
            FLOOR_TYPE_5) {
            ref_func_80A25FA0(this);
            this->unk_2B0 = 2;
        } else {
            ref_func_80A25CF4(this);
            this->unk_2B0 = 1;
        }
    }
    return sp27 != this->unk_2B0;
}
