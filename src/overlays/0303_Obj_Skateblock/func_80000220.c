// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_skateblock.h"

s32 ref_func_80A21370(ObjSkateblock* this, PlayState* play) {
    ObjSkateblockFloor* floor;
    s32 i;
    s32 pad;
    s32 sp98;
    Vec3f sp8C;
    s32 sp88;
    f32 phi_f20 = BGCHECK_Y_MIN;

    sp88 = false;
    sp8C.y = this->dyna.actor.world.pos.y + 40.0f;
    sp98 = -1;

    for (i = 0; i < ARRAY_COUNT(this->unk_184); i++) {
        floor = &this->unk_184[i];

        floor->poly = NULL;
        floor->height = BGCHECK_Y_MIN;
        floor->bgId = BG_ACTOR_MAX;

        sp8C.x = this->dyna.actor.world.pos.x + ((ref_D_80A22A1C[i].x * this->dyna.actor.scale.x) + ref_D_80A22A44[i].x);
        sp8C.z = this->dyna.actor.world.pos.z + ((ref_D_80A22A1C[i].z * this->dyna.actor.scale.z) + ref_D_80A22A44[i].z);

        floor->height =
            BgCheck_EntityRaycastFloor6(&play->colCtx, &floor->poly, &floor->bgId, &this->dyna.actor, &sp8C, 0.0f);

        if (floor->height > BGCHECK_Y_MIN + 1.0f) {
            sp88 = true;
            if (phi_f20 < floor->height) {
                phi_f20 = floor->height;
                sp98 = i;
            }
        }
    }

    if (sp98 >= 0) {
        this->dyna.actor.floorPoly = this->unk_184[sp98].poly;
        this->dyna.actor.floorHeight = this->unk_184[sp98].height;
        this->dyna.actor.floorBgId = this->unk_184[sp98].bgId;
    }
    return sp88;
}
