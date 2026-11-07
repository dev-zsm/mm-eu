// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_spinyroll.h"

s32 ref_func_80A1E074(ObjSpinyroll* this, PlayState* play, Vec3f* arg2, s32 arg3) {
    f32 temp_f0;
    ObjSpinyrollStruct* ptr = &this->unk_3A4;
    f32 temp_f20;
    s32 i;
    s32 j;
    Vec3f spC8;
    Vec3f spBC;
    Vec3f spB0;
    ObjSpinyrollSubStruct* temp_s1;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp;
    s32 pad;
    s32 sp98;

    spC8.y = this->dyna.actor.world.pos.y + 10.0f;
    spBC.y = spC8.y;
    sp98 = false;
    temp_f20 = FLT_MAX;
    ptr->unk_F0 = NULL;

    for (i = 0; i < ARRAY_COUNT(this->unk_3A4.unk_00); i++) {
        temp = ref_D_80A1F1F4[i];
        temp_f22 = temp * this->unk_4C4.x;
        temp_f24 = temp * this->unk_4C4.z;

        for (j = 0; j < ptr->unk_F4; j++) {
            temp_s1 = &ptr->unk_00[i][j];
            spC8.x = (temp_s1->unk_00 * Math_CosS(this->dyna.actor.world.rot.y)) + this->dyna.actor.world.pos.x;
            spC8.z = (temp_s1->unk_00 * -Math_SinS(this->dyna.actor.world.rot.y)) + this->dyna.actor.world.pos.z;

            spBC.x = temp_f22 + spC8.x;
            spBC.z = temp_f24 + spC8.z;

            if (BgCheck_EntityLineTest3(&play->colCtx, &spC8, &spBC, &spB0, &temp_s1->unk_04, true, false, false, true,
                                        &temp_s1->bgId, &this->dyna.actor, 0.0f)) {
                if (arg3 && (this->dyna.actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME)) {
                    ref_func_80A1DA50(play, this, &spC8, &spB0);
                }

                temp_f0 = Math3D_Vec3fDistSq(&spC8, &spB0);
                if (temp_f0 < temp_f20) {
                    temp_f20 = temp_f0;
                    sp98 = true;
                    Math_Vec3f_Diff(&spB0, &spBC, arg2);
                    ptr->unk_F0 = temp_s1;
                }
            }
        }
    }

    return sp98;
}
