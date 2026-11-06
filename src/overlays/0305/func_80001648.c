// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

s32 ref_func_80A246D8(ObjIceblock* this, PlayState* play, Vec3f* arg2) {
    static ObjIceBlockUnkStruct3 ref_D_80A26F40[] = {
        { -300.0f, -300.0f }, { 300.0f, -300.0f }, { -300.0f, 600.0f }, { 300.0f, 600.0f }, { 0.0f, 0.0f },
    };
    static ObjIceBlockUnkStruct3 ref_D_80A26F68[] = {
        { 1.0f, 1.0f }, { -1.0f, 1.0f }, { 1.0f, -1.0f }, { -1.0f, -1.0f }, { 0.0f, 0.0f },
    };
    s32 pad;
    s32 i;
    s32 j;
    Vec3f spC0;
    Vec3f spB4;
    Vec3f spA8;
    Vec3f sp9C;
    s32 bgId;
    CollisionPoly* sp94;
    ObjIceblock* temp_v0;
    f32 temp_f20 = (this->dyna.actor.scale.z * 300.0f) + 2.0f;
    s16 phi_s3;
    s32 ret = false;

    for (i = 0, phi_s3 = 0; i < 4; i++, phi_s3 += 0x4000) {
        for (j = 0; j < ARRAY_COUNT(ref_D_80A26F40); j++) {
            spA8.x = (ref_D_80A26F40[j].unk_00 * this->dyna.actor.scale.x) + ref_D_80A26F68[j].unk_00;
            spA8.y = ((ref_D_80A26F40[j].unk_04 * this->dyna.actor.scale.y) + ref_D_80A26F68[j].unk_04) +
                     (this->dyna.actor.shape.yOffset * this->dyna.actor.scale.y);
            spA8.z = 0.0f;

            ref_func_80A2311C(&spC0, &spA8, phi_s3);

            spC0.x += arg2->x;
            spC0.y += arg2->y;
            spC0.z += arg2->z;

            spB4.x = (Math_SinS(phi_s3) * temp_f20) + spC0.x;
            spB4.y = spC0.y;
            spB4.z = (Math_CosS(phi_s3) * temp_f20) + spC0.z;

            if (BgCheck_EntityLineTest3(&play->colCtx, &spC0, &spB4, &sp9C, &sp94, true, false, false, true, &bgId,
                                        &this->dyna.actor, 0.0f)) {
                ret = true;
                temp_v0 = (ObjIceblock*)DynaPoly_GetActor(&play->colCtx, bgId);
                if ((temp_v0 != NULL) && (temp_v0->dyna.actor.id == ACTOR_OBJ_ICEBLOCK) && (temp_v0->unk_2B0 == 3)) {
                    temp_v0->unk_1B0 |= 0x80;
                }
            }
        }
    }

    return ret;
}
