// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

void ObjMine_Air_Draw(Actor* thisx, PlayState* play) {
    s32 pad; 
    ObjMine* this = (ObjMine*)thisx;
    s32 linkCount = OBJMINE_GET_LINK_COUNT(&this->actor);
    ObjMineAirChain* airChain = &this->chain.air;
    ObjMineAirLink* airLink;
    s32 i;
    Vec3f linkPos;
    Vec3f linkOffset;
    Gfx* gfx;

    ref_func_800B8050(&this->actor, play, true);

    OPEN_DISPS(play->state.gfxCtx);

    gfx = POLY_OPA_DISP;

    gSPDisplayList(gfx++, &gSetupDLs[SETUPDL_25]);
    MATRIX_FINALIZE_AND_LOAD(gfx++, play->state.gfxCtx);
    gSPDisplayList(gfx++, object_ny_DL_000030);

    ObjMine_SetMatrixRotation(&airChain->basis);
    Matrix_Scale(this->actor.scale.x, this->actor.scale.y, this->actor.scale.z, MTXMODE_APPLY);
    if (linkCount != 0) {
        
        Math_Vec3f_ScaleAndStore(&airChain->basis.y, -(LINK_SIZE / 2.0f), &linkOffset);
        linkPos.x = this->actor.home.pos.x - linkOffset.x;
        linkPos.y = this->actor.home.pos.y - (LINK_SIZE / 2.0f) - linkOffset.y;
        linkPos.z = this->actor.home.pos.z - linkOffset.z;
        Math_Vec3f_ScaleAndStore(&airChain->basis.y, -LINK_SIZE, &linkOffset);

        for (i = 0, airLink = airChain->links; i < linkCount; i++, airLink++) {
            Matrix_RotateYS(airLink->twist, MTXMODE_APPLY);
            linkPos.x += linkOffset.x;
            linkPos.y += linkOffset.y;
            linkPos.z += linkOffset.z;
            ObjMine_SetMatrixTranslation(&linkPos);

            MATRIX_FINALIZE_AND_LOAD(gfx++, play->state.gfxCtx);
            gSPDisplayList(gfx++, object_ny_DL_000030);
        }
    }

    Matrix_RotateXS(0x2000, MTXMODE_APPLY);
    ObjMine_SetMatrixTranslation(&this->actor.world.pos);

    MATRIX_FINALIZE_AND_LOAD(gfx++, play->state.gfxCtx);
    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPDisplayList(gfx++, object_ny_DL_002068);
    gSPDisplayList(gfx++, object_ny_DL_002188);

    POLY_OPA_DISP = gfx;

    CLOSE_DISPS(play->state.gfxCtx);
}
