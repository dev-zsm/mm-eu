// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test.h"

void EnTest_Init(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnTest* this = (EnTest*)thisx;
    MtxF sp38;
    s32 bgId;

    this->unk_209 = 0;
    this->unk_174 = 0;

    if (thisx->params > 0) {
        Actor_SetScale(thisx, thisx->params / 100000.0f);
        this->surfaceMaterial = SURFACE_MATERIAL_DIRT;
    } else {
        thisx->floorPoly = NULL;
        thisx->world.pos.y += 10.0f;
        thisx->floorHeight = BgCheck_EntityRaycastFloor3(&play->colCtx, &thisx->floorPoly, &bgId, &thisx->world.pos);

        if ((thisx->floorPoly == NULL) || (thisx->floorHeight == BGCHECK_Y_MIN)) {
            Actor_Kill(thisx);
            return;
        }

        thisx->world.pos.y = thisx->floorHeight;
        ref_func_800C0094(thisx->floorPoly, thisx->world.pos.x, thisx->floorHeight, thisx->world.pos.z, &sp38);
        Matrix_MtxFToYXZRot(&sp38, &thisx->shape.rot, true);
        thisx->world.rot = thisx->shape.rot;
        this->surfaceMaterial = SurfaceType_GetMaterial(&play->colCtx, thisx->floorPoly, bgId);
    }

    Keyframe_InitFlex(&this->kfSkelAnime, &gameplay_keep_KFSkel_06EB70, &gameplay_keep_KFAnim_06BB0C, this->jointTable,
                      this->morphTable, NULL);
    Keyframe_FlexPlayOnce(&this->kfSkelAnime, &gameplay_keep_KFAnim_06BB0C);
    this->kfSkelAnime.frameCtrl.curTime = 9.0f;
    ref_func_80862B70(this->unk_20C);
}
