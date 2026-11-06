// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_skateblock.h"

void ref_func_80A21E9C(ObjSkateblock* this, PlayState* play) {
    DynaPolyActor* temp_v0;
    s32 i;
    ObjSkateblockFloor* ptr;

    if (!(this->unk_1C1 & 4)) {
        return;
    }

    for (i = 0; i < ARRAY_COUNT(this->unk_184); i++) {
        ptr = &this->unk_184[i];

        temp_v0 = DynaPoly_GetActor(&play->colCtx, ptr->bgId);
        if ((temp_v0 != NULL) && (temp_v0->actor.id == ACTOR_OBJ_SKATEBLOCK)) {
            ObjSkateblock* skateBlock = (ObjSkateblock*)temp_v0;
            f32 height = this->dyna.actor.world.pos.y - ptr->height;

            if (fabsf(height) < 0.1f) {
                skateBlock->unk_1C1 |= 2;
            }
        }
    }
}
