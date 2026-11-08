// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bean.h"

s32 ref_func_80936D58(ObjBean* this, PlayState* play) {
    static Vec3f ref_D_80939018 = { 0.0f, 30.0f, 0.0f };
    s32 pad;
    s32 bgId;
    Vec3f spAC;
    Vec3f spA0;
    Vec3f sp94;
    Vec3f sp88;
    MtxF sp48;

    Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_NEW);
    Matrix_RotateXS(this->dyna.actor.shape.rot.x, MTXMODE_APPLY);
    Matrix_RotateZS(this->dyna.actor.shape.rot.z, MTXMODE_APPLY);
    Matrix_MultVec3f(&ref_D_80939018, &spAC);
    Math_Vec3f_Sum(&this->dyna.actor.world.pos, &spAC, &spA0);
    Math_Vec3f_Diff(&this->dyna.actor.world.pos, &spAC, &sp94);

    if (BgCheck_EntityLineTest2(&play->colCtx, &spA0, &sp94, &sp88, &this->dyna.actor.floorPoly, true, true, true, true,
                                &bgId, &this->dyna.actor)) {
        this->dyna.actor.world.pos.x = (COLPOLY_GET_NORMAL(this->dyna.actor.floorPoly->normal.x) * 1.9f) + sp88.x;
        this->dyna.actor.world.pos.y = (COLPOLY_GET_NORMAL(this->dyna.actor.floorPoly->normal.y) * 1.9f) + sp88.y;
        this->dyna.actor.world.pos.z = (COLPOLY_GET_NORMAL(this->dyna.actor.floorPoly->normal.z) * 1.9f) + sp88.z;
        ref_func_800C0094(this->dyna.actor.floorPoly, this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                      this->dyna.actor.world.pos.z, &sp48);
        Matrix_Put(&sp48);
        Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_APPLY);
        Matrix_Get(&sp48);
        Matrix_MtxFToYXZRot(&sp48, &this->dyna.actor.shape.rot, false);
        return true;
    }
    return false;
}
