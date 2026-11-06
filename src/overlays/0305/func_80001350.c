// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

s32 ref_func_80A243E0(ObjIceblock* this, PlayState* play, Vec3f* arg0) {
    static f32 ref_D_80A26F30[] = { -300.0f, 300.0f };
    static f32 ref_D_80A26F38[] = { 1.0f, -1.0f };
    s32 i;
    f32 sp100;
    f32 spFC;
    f32 phi_f22;
    Vec3f spEC;
    Vec3f spE0;
    Vec3f spD4;
    Vec3f spC8;
    s16 temp_s6;
    f32 temp_f28;
    s32 bgId;
    CollisionPoly* spB8;
    s32 ret;
    f32 temp_f30;
    f32 temp_f0;
    f32 temp_f12;

    temp_s6 = this->dyna.yRotation;
    if (this->dyna.pushForce < 0.0f) {
        temp_s6 -= 0x8000;
    }

    sp100 = Math_SinS(temp_s6);
    spFC = Math_CosS(temp_s6);

    temp_f0 = ((Math3D_Vec3f_DistXYZ(&this->dyna.actor.world.pos, &this->dyna.actor.prevPos) +
                (300.0f * this->dyna.actor.scale.z)) +
               2.0f);
    temp_f12 = -temp_f0;
    ret = false;
    temp_f28 = temp_f12 * sp100;
    temp_f30 = temp_f12 * spFC;
    phi_f22 = FLT_MAX;

    for (i = 0; i < ARRAY_COUNT(ref_D_80A26F30); i++) {
        spD4.x = (ref_D_80A26F30[i] * this->dyna.actor.scale.x) + ref_D_80A26F38[i];
        spD4.y = -10.0f;
        spD4.z = 0.0f;

        ref_func_80A2311C(&spEC, &spD4, temp_s6);

        spEC.x += this->dyna.actor.world.pos.x;
        spEC.y += this->dyna.actor.world.pos.y;
        spEC.z += this->dyna.actor.world.pos.z;

        spE0.x = temp_f28 + spEC.x;
        spE0.y = spEC.y;
        spE0.z = temp_f30 + spEC.z;

        if (BgCheck_EntityLineTest3(&play->colCtx, &spEC, &spE0, &spC8, &spB8, true, false, false, true, &bgId,
                                    &this->dyna.actor, 0.0f)) {
            temp_f12 = Math3D_Vec3fDistSq(&spEC, &spC8);
            if (temp_f12 < phi_f22) {
                phi_f22 = temp_f12;
                ret = true;
                arg0->x = (spC8.x - spEC.x) + (300.0f * this->dyna.actor.scale.z * sp100);
                arg0->y = 0.0f;
                arg0->z = (spC8.z - spEC.z) + (300.0f * this->dyna.actor.scale.z * spFC);
            }
        }
    }
    return ret;
}
