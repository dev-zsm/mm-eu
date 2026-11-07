// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

s32 ref_func_80A24118(ObjIceblock* this, PlayState* play, f32 arg2, Vec3f* arg3) {
    static ObjIceBlockUnkStruct3 ref_D_80A26EE0[] = {
        { -300.0f, -300.0f }, { 300.0f, -300.0f }, { -300.0f, 600.0f }, { 300.0f, 600.0f }, { 0.0f, 0.0f },
    };
    static ObjIceBlockUnkStruct3 ref_D_80A26F08[] = {
        { 1.0f, 1.0f }, { -1.0f, 1.0f }, { 1.0f, -1.0f }, { -1.0f, -1.0f }, { 0.0f, 0.0f },
    };
    f32 temp_f20;
    f32 spF0;
    f32 spEC;
    f32 phi_f20;
    Vec3f spDC;
    Vec3f spD0;
    Vec3f spC4;
    Vec3f spB8;
    s32 pad[2];
    s32 bgId;
    CollisionPoly* spA8;
    s32 ret;
    s32 i;
    s16 sp9E;
    f32 temp_f24;
    f32 temp_f26;

    sp9E = this->dyna.yRotation;
    if (this->dyna.pushForce < 0.0f) {
        sp9E -= 0x8000;
    }

    spF0 = Math_SinS(sp9E);
    spEC = Math_CosS(sp9E);
    temp_f20 = Math3D_Vec3f_DistXYZ(&this->dyna.actor.world.pos, &this->dyna.actor.prevPos) +
               (300.0f * this->dyna.actor.scale.z) + arg2;
    temp_f24 = temp_f20 * spF0;
    temp_f26 = temp_f20 * spEC;
    ret = false;
    phi_f20 = FLT_MAX;

    for (i = 0; i < ARRAY_COUNT(ref_D_80A26EE0); i++) {
        spC4.x = (ref_D_80A26EE0[i].unk_00 * this->dyna.actor.scale.x) + ref_D_80A26F08[i].unk_00;
        spC4.y = (ref_D_80A26EE0[i].unk_04 * this->dyna.actor.scale.y) + ref_D_80A26F08[i].unk_04 +
                 (this->dyna.actor.shape.yOffset * this->dyna.actor.scale.y);
        spC4.z = 0.0f;

        ref_func_80A2311C(&spDC, &spC4, sp9E);

        spDC.x += this->dyna.actor.prevPos.x;
        spDC.y += this->dyna.actor.prevPos.y;
        spDC.z += this->dyna.actor.prevPos.z;

        spD0.x = temp_f24 + spDC.x;
        spD0.y = spDC.y;
        spD0.z = temp_f26 + spDC.z;

        if (BgCheck_EntityLineTest3(&play->colCtx, &spDC, &spD0, &spB8, &spA8, true, false, false, true, &bgId,
                                    &this->dyna.actor, 0.0f)) {
            temp_f20 = Math3D_Vec3fDistSq(&spDC, &spB8);
            if (temp_f20 < phi_f20) {
                phi_f20 = temp_f20;
                ret = true;
                Math_Vec3f_Diff(&spB8, &spD0, arg3);
            }
        }
    }
    return ret;
}
