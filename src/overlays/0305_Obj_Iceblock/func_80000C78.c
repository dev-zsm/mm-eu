// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

s32 ref_func_80A23D08(ObjIceblock* this, PlayState* play) {
    static ObjIceBlockUnkStruct3 ref_D_80A26E90[] = {
        { -300.0f, 300.0f }, { 300.0f, 300.0f }, { -300.0f, -300.0f }, { 300.0f, -300.0f }, { 0.0f, 0.0f },
    };
    static ObjIceBlockUnkStruct3 ref_D_80A26EB8[] = {
        { 0.5f, -0.5f }, { -0.5f, -0.5f }, { 0.5f, 0.5f }, { -0.5f, 0.5f }, { 0.0f, 0.0f },
    };
    s32 pad3;
    ObjIceBlockUnkStruct2* ptr;
    WaterBox* waterBox;
    s32 i;
    s32 spBC;
    s32 spB8;
    s32 pad;
    f32 phi_f20;
    Vec3f spA4;
    Vec3f sp98;
    s32 sp94 = 0;
    f32 phi_f22;

    sp98.y = this->dyna.actor.world.pos.y + 40.0f;
    spBC = spB8 = -1;
    phi_f20 = BGCHECK_Y_MIN;
    phi_f22 = BGCHECK_Y_MIN;

    for (i = 0; i < ARRAY_COUNT(this->unk_1F4); i++) {
        ptr = &this->unk_1F4[i];

        ptr->unk_00 = NULL;
        ptr->unk_04 = BGCHECK_Y_MIN;
        ptr->unk_08 = 50;

        sp98.x = (ref_D_80A26E90[i].unk_00 * this->dyna.actor.scale.x) + ref_D_80A26EB8[i].unk_00;
        sp98.z = (ref_D_80A26E90[i].unk_04 * this->dyna.actor.scale.z) + ref_D_80A26EB8[i].unk_04;

        ref_func_80A2311C(&spA4, &sp98, this->dyna.actor.shape.rot.y);
        spA4.x += this->dyna.actor.world.pos.x;
        spA4.z += this->dyna.actor.world.pos.z;

        ptr->unk_04 =
            BgCheck_EntityRaycastFloor6(&play->colCtx, &ptr->unk_00, &ptr->unk_08, &this->dyna.actor, &spA4, 0.0f);
        if (ptr->unk_04 > BGCHECK_Y_MIN + 1) {
            sp94 = 1;
            if (phi_f22 < ptr->unk_04) {
                spBC = i;
                phi_f22 = ptr->unk_04;
            }
        }

        if (BgCheck_GetWaterSurfaceNoBgId(play, &play->colCtx, spA4.x, spA4.z, &ptr->unk_0C, &waterBox)) {
            if (phi_f20 < ptr->unk_0C) {
                spB8 = i;
                phi_f20 = ptr->unk_0C;
            }
        } else {
            ptr->unk_0C = BGCHECK_Y_MIN;
        }
    }

    if (spBC >= 0) {
        this->dyna.actor.floorPoly = this->unk_1F4[spBC].unk_00;
        this->dyna.actor.floorHeight = this->unk_1F4[spBC].unk_04;
        this->dyna.actor.floorBgId = this->unk_1F4[spBC].unk_08;
    } else {
        this->dyna.actor.floorPoly = NULL;
        this->dyna.actor.floorHeight = BGCHECK_Y_MIN;
        this->dyna.actor.floorBgId = BGCHECK_SCENE;
    }

    if (spB8 >= 0) {
        this->unk_244 = this->unk_1F4[spB8].unk_0C;
    } else {
        this->unk_244 = BGCHECK_Y_MIN;
    }

    return sp94;
}
