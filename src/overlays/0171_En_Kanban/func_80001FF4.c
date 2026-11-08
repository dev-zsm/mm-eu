// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kanban.h"

void EnKanban_Draw(Actor* thisx, PlayState* play) {
    EnKanban* this = (EnKanban*)thisx;
    f32 zShift;
    f32 zShift2;
    s32 i;
    Player* player = GET_PLAYER(play);
    u8* shadowTex = GRAPH_ALLOC(play->state.gfxCtx, ARRAY_COUNT(sShadowTexFlags));

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    gSPDisplayList(POLY_OPA_DISP++, gSignMaterialDL);

    if (this->actionState != ENKANBAN_SIGN) {
        Matrix_Translate(this->actor.world.pos.x, this->actor.world.pos.y, this->actor.world.pos.z, MTXMODE_NEW);
        Matrix_Scale(this->actor.scale.x, this->actor.scale.y, this->actor.scale.z, MTXMODE_APPLY);
        Matrix_RotateXFApply(this->floorRot.x);
        Matrix_RotateZF(this->floorRot.z, MTXMODE_APPLY);
        Matrix_Translate(0.0f, this->actor.shape.yOffset, 0.0f, MTXMODE_APPLY);
        Matrix_RotateYS(this->actor.shape.rot.y, MTXMODE_APPLY);
        Matrix_RotateXS(this->actor.shape.rot.x, MTXMODE_APPLY);

        zShift = fabsf(Math_SinS(this->spinRot.x) * this->pieceHeight);
        zShift2 = fabsf(Math_SinS(this->spinRot.z) * this->pieceWidth);
        zShift = CLAMP_MIN(zShift, zShift2);
        zShift *= -(f32)this->direction;

        Matrix_Translate(0.0f, 0.0f, zShift, MTXMODE_APPLY);
        Matrix_RotateXS(this->spinRot.x, MTXMODE_APPLY);
        Matrix_RotateYS(this->spinRot.z, MTXMODE_APPLY);
        Matrix_Translate(this->offset.x, this->offset.y, this->offset.z - 100.0f, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);

        for (i = 0; i < ARRAY_COUNT(sPartFlags); i++) {
            if (sPartFlags[i] & this->partFlags) {
                gSPDisplayList(POLY_OPA_DISP++, sDisplayLists[i]);
            }
        }
    } else {
        f32 phi_f0 = 0.0f;

        if ((player->transformation == PLAYER_FORM_HUMAN) || (player->transformation == PLAYER_FORM_DEKU)) {
            phi_f0 = -15.0f;
        }
        this->actor.world.pos.y = this->actor.home.pos.y + phi_f0;
        Matrix_Translate(0.0f, 0.0f, -100.0f, MTXMODE_APPLY);
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);

        if (this->partFlags == 0xFFFF) {
            gSPDisplayList(POLY_OPA_DISP++, gSignRectangularDL);
        } else {
            for (i = 0; i < ARRAY_COUNT(sPartFlags); i++) {
                if (sPartFlags[i] & this->partFlags) {
                    gSPDisplayList(POLY_OPA_DISP++, sDisplayLists[i]);
                }
            }
        }

        if (this->cutMarkAlpha != 0) {
            f32 cutOffset = (this->cutType == CUT_POST) ? -1200.0f : 0.0f;

            Matrix_Translate(0.0f, 4400.0f + cutOffset, 200.0f, MTXMODE_APPLY);
            Matrix_RotateZF(sCutAngles[this->cutType], MTXMODE_APPLY);
            Matrix_Scale(0.0f, 10.0f, 2.0f, MTXMODE_APPLY);

            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetPrimColor(POLY_XLU_DISP++, 0x00, 0x00, 255, 255, 255, this->cutMarkAlpha);
            gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 150, 0);
            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
            gSPDisplayList(POLY_XLU_DISP++, gSignParticleDL);
        }
    }

    if ((this->actor.projectedPos.z <= 400.0f) && (this->actor.projectedPos.z > 0.0f) &&
        (this->actor.floorHeight > -3000.0f) && ((this->bounceX != 0) || (this->bounceZ != 0))) {
        u16 dayTime = CURRENT_TIME;
        f32 shadowAlpha;

        if (dayTime >= CLOCK_TIME(12, 0)) {
            dayTime = (DAY_LENGTH - 1) - dayTime;
        }

        shadowAlpha = (dayTime * 0.00275f) + 10.0f;
        if (this->actor.projectedPos.z > 300.0f) {
            shadowAlpha *= (400.0f - this->actor.projectedPos.z) * 0.01f;
        }

        gDPSetPrimColor(POLY_XLU_DISP++, 0x00, 0x00, 0, 0, 0, (s8)shadowAlpha);

        if ((player->transformation == PLAYER_FORM_HUMAN) || (player->transformation == PLAYER_FORM_DEKU)) {
            zShift = 0.0f;
        } else {
            zShift = ((this->actor.world.pos.y - this->actor.floorHeight) * -50.0f) / 100.0f;
        }

        Matrix_Translate(this->actor.world.pos.x, this->actor.floorHeight, this->actor.world.pos.z + zShift,
                         MTXMODE_NEW);
        Matrix_RotateXFApply(this->floorRot.x);
        Matrix_RotateZF(this->floorRot.z, MTXMODE_APPLY);
        Matrix_Scale(this->actor.scale.x, 0.0f, this->actor.scale.z, MTXMODE_APPLY);

        if (this->actionState == ENKANBAN_SIGN) {
            Matrix_RotateXFApply(-M_PIf / 5);
        }

        Matrix_RotateYS(this->actor.shape.rot.y, MTXMODE_APPLY);
        Matrix_RotateXS(this->actor.shape.rot.x, MTXMODE_APPLY);
        Matrix_RotateXS(this->spinRot.x, MTXMODE_APPLY);
        Matrix_RotateYS(this->spinRot.z, MTXMODE_APPLY);
        Matrix_Translate(this->offset.x, this->offset.y, this->offset.z, MTXMODE_APPLY);
        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);

        for (i = 0; i < ARRAY_COUNT(sShadowTexFlags); i++) {
            if (sShadowTexFlags[i] & this->partFlags) {
                shadowTex[i] = 0xFF;
            } else {
                shadowTex[i] = 0;
            }
        }

        gSPSegment(POLY_XLU_DISP++, 0x08, Lib_SegmentedToVirtual(shadowTex));
        gSPDisplayList(POLY_XLU_DISP++, gEnKanban_D_80957DE0);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
