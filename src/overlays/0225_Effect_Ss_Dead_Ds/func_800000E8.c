// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_dead_ds.h"

void EffectSsDeadDs_Draw(PlayState* play, u32 index, EffectSs* this) {
    s32 pad;
    f32 scale;
    s32 pad2[2];
    MtxF mf;
    f32 yIntersect;
    Vec3f pos;
    CollisionPoly* floorPoly;

    OPEN_DISPS(play->state.gfxCtx);

    scale = this->rScale * 0.01f;
    Gfx_SetupDL60_XluNoCD(play->state.gfxCtx);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 0, 0, 0, this->rAlpha);
    gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, 0);
    pos = this->pos;

    if (this->rTimer == 0) {
        Vec3s rot;
        Vec3f prevPos;

        prevPos.x = pos.x - this->velocity.x;
        prevPos.y = pos.y - this->velocity.y;
        prevPos.z = pos.z - this->velocity.z;

        if (BgCheck_EntitySphVsWall1(&play->colCtx, &this->pos, &pos, &prevPos, 1.5f, &floorPoly, 1.0f)) {
            ref_func_800C0094(floorPoly, this->pos.x, this->pos.y, this->pos.z, &mf);
            Matrix_Put(&mf);
        } else {
            pos.y++;
            yIntersect = BgCheck_EntityRaycastFloor1(&play->colCtx, &floorPoly, &pos);

            if (floorPoly != NULL) {
                ref_func_800C0094(floorPoly, this->pos.x, yIntersect + 1.5f, this->pos.z, &mf);
                Matrix_Put(&mf);
            } else {
                Matrix_Translate(this->pos.x, this->pos.y, this->pos.z, MTXMODE_NEW);
                Matrix_Get(&mf);
            }
        }

        Matrix_MtxFToZYXRot(&mf, &rot, false);
        this->rRoll = rot.x;
        this->rPitch = rot.y;
        this->rYaw = rot.z;
        this->pos.y = mf.yw;
        this->rTimer++;
    }

    Matrix_Translate(this->pos.x, this->pos.y, this->pos.z, MTXMODE_NEW);
    Matrix_RotateZYX(this->rRoll, this->rPitch, this->rYaw, MTXMODE_APPLY);
    Matrix_RotateXFApply(1.57f); 
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    gDPSetCombineLERP(POLY_XLU_DISP++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0,
                      PRIMITIVE, 0);
    gSPDisplayList(POLY_XLU_DISP++, gLensFlareCircleDL);

    CLOSE_DISPS(play->state.gfxCtx);
}
