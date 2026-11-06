// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_waterfall.h"

void ref_func_80B84568(BgDblueWaterfall* this, PlayState* play) {
    s32 pad;
    CollisionPoly* sp40;
    WaterBox* waterBox;
    s32 bgId;
    f32 sp34 = BgCheck_EntityRaycastFloor5(&play->colCtx, &sp40, &bgId, &this->actor, &this->actor.world.pos);
    f32 waterSurface;

    if (BgCheck_GetWaterSurfaceNoBgId(play, &play->colCtx, this->actor.world.pos.x, this->actor.world.pos.z,
                                      &waterSurface, &waterBox)) {
        if (waterSurface < sp34) {
            this->unk_198 = sp34;
        } else {
            this->unk_198 = waterSurface;
        }
    } else {
        this->unk_198 = sp34;
    }
}
