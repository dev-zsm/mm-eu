// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A24AA8(ObjIceblock* this, PlayState* play) {
    s32 i;
    f32 x;
    ObjIceblock* temp_v0;

    if (this->unk_1B0 & 4) {
        for (i = 0; i < ARRAY_COUNT(this->unk_1F4); i++) {
            temp_v0 = (ObjIceblock*)DynaPoly_GetActor(&play->colCtx, ((void)0, this->unk_1F4[i]).unk_08);
            if ((temp_v0 != NULL) && (temp_v0->dyna.actor.id == ACTOR_OBJ_ICEBLOCK)) {
                x = this->dyna.actor.world.pos.y - this->unk_1F4[i].unk_04;

                if (fabsf(x) < 0.1f) {
                    temp_v0->unk_1B0 |= 2;
                }
            }
        }
    }
}
