// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_skateblock.h"

s32 ref_func_80A216D4(ObjSkateblock* this, PlayState* play, f32 arg2, Vec3f* arg3) {
    s32 pad;
    f32 spE8;
    f32 spE4;
    s32 i;
    Vec3f spD4;
    Vec3f spC8;
    Vec3f spBC;
    Vec3f spB0;
    f32 temp_f20;
    f32 temp_f24;
    s32 bgId;
    CollisionPoly* spA0;
    s32 ret;
    f32 temp_f26;
    s16 sp96 = this->dyna.yRotation;
    f32 temp_f2;

    if (this->dyna.pushForce < 0.0f) {
        sp96 -= 0x8000;
    }
    spE8 = Math_SinS(sp96);
    spE4 = Math_CosS(sp96);

    temp_f2 = Math3D_Vec3f_DistXYZ(&this->dyna.actor.world.pos, &this->dyna.actor.prevPos) +
              (300.0f * this->dyna.actor.scale.z) + arg2;
    temp_f24 = temp_f2 * spE8;
    temp_f26 = temp_f2 * spE4;

    ret = false;
    temp_f20 = FLT_MAX;

    for (i = 0; i < ARRAY_COUNT(ref_D_80A22A6C); i++) {
        spBC.x = (ref_D_80A22A6C[i].x * this->dyna.actor.scale.x) + ref_D_80A22A94[i].x;
        spBC.y = (ref_D_80A22A6C[i].z * this->dyna.actor.scale.y) + ref_D_80A22A94[i].z;
        spBC.z = 0.0f;

        ref_func_80A212F0(&spD4, &spBC, sp96);

        spD4.x += this->dyna.actor.prevPos.x;
        spD4.y += this->dyna.actor.prevPos.y;
        spD4.z += this->dyna.actor.prevPos.z;

        spC8.x = temp_f24 + spD4.x;
        spC8.y = spD4.y;
        spC8.z = temp_f26 + spD4.z;

        if (BgCheck_EntityLineTest3(&play->colCtx, &spD4, &spC8, &spB0, &spA0, true, false, false, true, &bgId,
                                    &this->dyna.actor, 0.0f)) {
            temp_f2 = Math3D_Vec3fDistSq(&spD4, &spB0);
            if (temp_f2 < temp_f20) {
                temp_f20 = temp_f2;
                ret = true;
                Math_Vec3f_Diff(&spB0, &spC8, arg3);
            }
        }
    }
    return ret;
}
