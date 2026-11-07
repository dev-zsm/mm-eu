// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lightswitch.h"

void ObjLightSwitch_DrawOpa(ObjLightswitch* this, PlayState* play) {
    s32 pad;
    Vec3f tempPos;
    Vec3s tempRot;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    gDPSetEnvColor(POLY_OPA_DISP++, (u8)(this->colorR >> 6), (u8)(this->colorG >> 6),
                   ((void)0, (u8)(this->colorB >> 6)), (u8)(this->colorAlpha >> 6));
    gSPSegment(POLY_OPA_DISP++, 0x09, gActorSetupOpaDL);

    tempPos.x = this->actor.world.pos.x;
    tempPos.y = this->actor.world.pos.y + (this->actor.shape.yOffset * this->actor.scale.y);
    tempPos.z = this->actor.world.pos.z;
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, Lib_SegmentedToVirtual(sLightswitchFaceGfx[this->faceState]));
    gSPDisplayList(POLY_OPA_DISP++, object_lightswitch_DL_000260);

    tempRot.x = this->actor.shape.rot.x;
    tempRot.y = this->actor.shape.rot.y;
    tempRot.z = this->actor.shape.rot.z + this->edgeRot;
    Matrix_SetTranslateRotateYXZ(tempPos.x, tempPos.y, tempPos.z, &tempRot);
    Matrix_Scale(this->actor.scale.x, this->actor.scale.y, this->actor.scale.z, MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, object_lightswitch_DL_000398);

    tempRot.z = this->actor.shape.rot.z - this->edgeRot;
    Matrix_SetTranslateRotateYXZ(tempPos.x, tempPos.y, tempPos.z, &tempRot);
    Matrix_Scale(this->actor.scale.x, this->actor.scale.y, this->actor.scale.z, MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, object_lightswitch_DL_000408);

    CLOSE_DISPS(play->state.gfxCtx);
}
