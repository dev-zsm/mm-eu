// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_vspinyroll.h"

s32 ref_func_80A3C8D8(ObjVspinyroll* this, PlayState* play, Vec3f* arg2, s32 arg3) {
    s32 pad;
    ObjVspinyrollStruct3* unk_1A8 = &this->unk_1A8;
    ObjVspinyrollStruct2* ptr;
    s32 i;
    Vec3f spE4;
    Vec3f spD8;
    Vec3f spCC;
    Vec3f spC0;
    Vec3f spB4;
    Vec3f spA8;
    f32 temp_f20 = FLT_MAX;
    f32 temp_f0;
    s32 sp9C;

    spE4.z = 0.0f;
    sp9C = false;
    unk_1A8->unk_1E0 = NULL;

    for (i = 0; i < unk_1A8->unk_1E4; i++) {
        ptr = &unk_1A8->unk_000[i];

        spE4.x = ptr->unk_00.x;
        spE4.y = ptr->unk_00.y;
        ref_func_80A3C4E0(&spD8, &spE4, this->dyna.actor.world.rot.y);

        spD8.x += this->dyna.actor.world.pos.x;
        spD8.y += this->dyna.actor.world.pos.y;
        spD8.z += this->dyna.actor.world.pos.z;

        Math_Vec3f_Copy(&spCC, &spD8);

        spCC.x += 30.0f * this->unk_3B4.x;
        spCC.z += 30.0f * this->unk_3B4.z;

        if (BgCheck_EntityLineTest3(&play->colCtx, &spD8, &spCC, &spC0, &unk_1A8->unk_000[i].collisionPoly, true, false,
                                    false, true, &unk_1A8->unk_000[i].bgId, &this->dyna.actor, 0.0f)) {
            if ((arg3 != 0) && (this->dyna.actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME)) {
                spA8.x = ptr->unk_00.x * 0.2f;
                spA8.y = ptr->unk_00.y;
                spA8.z = 20.0f;

                ref_func_80A3C4E0(&spB4, &spA8, this->dyna.actor.world.rot.y);

                spB4.x += this->dyna.actor.world.pos.x;
                spB4.y += this->dyna.actor.world.pos.y;
                spB4.z += this->dyna.actor.world.pos.z;

                EffectSsHitmark_SpawnFixedScale(play, EFFECT_HITMARK_METAL, &spB4);
                Actor_PlaySfx(&this->dyna.actor, NA_SE_IT_SHIELD_REFLECT_SW);
            }

            temp_f0 = Math3D_Vec3fDistSq(&spD8, &spC0);
            if (temp_f0 < temp_f20) {
                temp_f20 = temp_f0;
                sp9C = true;
                Math_Vec3f_Diff(&spC0, &spCC, arg2);
                unk_1A8->unk_1E0 = ptr;
            }
        }
    }

    return sp9C;
}
