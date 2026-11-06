// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_dhouse.h"

void ref_func_80B13724(ObjDhouse* this, PlayState* play) {
    f32 temp_f0;
    f32 temp_f20 = this->dyna.actor.home.pos.y - 300.0f;
    s32 i;
    CollisionPoly* sp80;
    ObjDhouseStruct2* ptr2;
    Vec3f sp70;
    s32 bgId;

    for (i = 0, ptr2 = &this->unk_240[0]; i < ARRAY_COUNT(this->unk_240); i++, ptr2++) {
        if (ptr2->unk_28 > 0) {
            ptr2->unk_0C.y -= 2.2f;

            Math_Vec3f_Scale(&ptr2->unk_0C, 0.95f);

            ptr2->unk_00.x += ptr2->unk_0C.x;
            ptr2->unk_00.y += ptr2->unk_0C.y;
            ptr2->unk_00.z += ptr2->unk_0C.z;

            if (ptr2->unk_00.y < temp_f20) {
                ptr2->unk_28 = 0;
            } else {
                ptr2->unk_1C.x += ptr2->unk_22;
                ptr2->unk_1C.y += ptr2->unk_24;
                ptr2->unk_1C.z += ptr2->unk_26;
                ptr2->unk_28--;

                if (ptr2->unk_29 & 1) {
                    temp_f0 =
                        BgCheck_EntityRaycastFloor5(&play->colCtx, &sp80, &bgId, &this->dyna.actor, &ptr2->unk_00);
                    if (((ptr2->unk_00.y - 20.0f) < temp_f0) && (temp_f0 > BGCHECK_Y_MIN + 1.0f)) {
                        Math_Vec3f_Copy(&sp70, &ptr2->unk_00);
                        ptr2->unk_28 = 0;
                        ref_func_80B13474(this, play, &sp70);
                    }
                }
            }
        }
    }
}
