// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_spinyroll.h"

s32 ref_func_80A1E3D8(ObjSpinyroll* this, PlayState* play, f32* arg2, s32 arg3) {
    f32 phi_f26;
    ObjSpinyrollStruct* spC8 = &this->unk_3A4;
    f32 phi_f22;
    ObjSpinyrollColFunc spC0;
    s32 i;
    s32 j;
    Vec3f spAC;
    Vec3f spA0;
    Vec3f sp94;
    ObjSpinyrollSubStruct* temp_s0;
    f32 temp_f20;
    s32 pad;
    s32 sp84;
    s32 pad2;
    f32* temp;

    if (this->unk_4C4.y > 0.0f) {
        spC0 = ref_func_80A1E394;
        phi_f26 = this->dyna.actor.world.pos.y + 48.0f;
    } else {
        spC0 = ref_func_80A1E334;
        phi_f26 = this->dyna.actor.world.pos.y;
    }

    sp84 = false;
    sp94.y = this->dyna.actor.world.pos.y + 24.0f;
    phi_f22 = FLT_MAX;
    spC8->unk_F0 = NULL;

    for (i = 0, temp = ref_D_80A1F1FC; i < ARRAY_COUNT(this->unk_3A4.unk_00); i++, temp++) {
        sp94.z = *temp;

        for (j = 0; j < spC8->unk_F4; j++) {
            temp_s0 = &spC8->unk_00[i][j];

            sp94.x = temp_s0->unk_00;
            ref_func_80A1DAAC(&spAC, &sp94, this->dyna.actor.world.rot.y);

            spAC.x += this->dyna.actor.world.pos.x;
            spAC.z += this->dyna.actor.world.pos.z;

            if (spC0(&play->colCtx, &spA0.y, &temp_s0->unk_04, &temp_s0->bgId, &spAC, this)) {
                temp_f20 = fabsf(spA0.y - spAC.y);
                if (temp_f20 <= 24.0f) {
                    if (arg3 && (this->dyna.actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME)) {
                        spA0.x = spAC.x;
                        spA0.z = spAC.z;
                        ref_func_80A1DA50(play, this, &spAC, &spA0);
                    }

                    if (temp_f20 < phi_f22) {
                        sp84 = true;
                        *arg2 = spA0.y - phi_f26;
                        phi_f22 = temp_f20;
                        spC8->unk_F0 = temp_s0;
                    }
                }
            }
        }
    }
    return sp84;
}
