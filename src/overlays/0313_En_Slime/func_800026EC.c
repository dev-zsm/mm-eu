// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_slime.h"

void EnSlime_Draw(Actor* thisx, PlayState* play) {
    s32 i;
    EnSlime* this = (EnSlime*)thisx;
    Vec3f wobbleScale;
    Color_RGBA8* primColor;
    Color_RGBA8* envColor;
    s32 pad;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    ref_func_800B8118(&this->actor, play, 0);
    if (this->iceBlockTimer != ICE_BLOCK_UNUSED) {
        gSPSegment(POLY_XLU_DISP++, 0x0A, gActorSetupOpaDL);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 170, 255, 255, 255, 255);
        gDPSetEnvColor(POLY_XLU_DISP++, 150, 255, 255, this->iceBlockTimer);
    } else {
        primColor = &sPrimColors[this->actor.params];
        envColor = &sEnvColors[this->actor.params];
        AnimatedMat_Draw(play, sSlimeTexAnim);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 100, primColor->r, primColor->g, primColor->b, primColor->a);
        gDPSetEnvColor(POLY_XLU_DISP++, envColor->r, envColor->g, envColor->b, 255);
    }

    if (this->actionFunc == EnSlime_Damaged) {
        wobbleScale.x = 1.0f - (Math_SinF((f32)this->timer * (M_PIf / 2)) * 0.3f);
        wobbleScale.y = (Math_SinF((f32)this->timer * (M_PIf / 2)) * 0.3f) + 1.0f;
        wobbleScale.z = 1.0f - (Math_CosF((f32)this->timer * (M_PIf / 2)) * 0.3f);

        Matrix_RotateXFApply(this->wobbleRot.x);
        Matrix_RotateZF(this->wobbleRot.z, MTXMODE_APPLY);
        Matrix_Scale(wobbleScale.x, wobbleScale.y, wobbleScale.z, MTXMODE_APPLY);
        Matrix_RotateZF(-this->wobbleRot.z, MTXMODE_APPLY);
        Matrix_RotateXFApply(-this->wobbleRot.x);
    }

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_XLU_DISP++, gChuchuBodyDL);

    if (this->iceBlockTimer == ICE_BLOCK_UNUSED) {
        
        Scene_SetRenderModeXlu(play, 0, 1);

        gSPSegment(POLY_OPA_DISP++, 0x09, sEyeTextures[this->eyeTexIndex]);
        gDPSetEnvColor(POLY_OPA_DISP++, 0, 30, 70, 255);
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, gChuchuEyesDL);

    } else {
        Scene_SetRenderModeXlu(play, 1, 2);
        gSPSegment(POLY_XLU_DISP++, 0x09, sEyeTextures[this->eyeTexIndex]);
        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, gChuchuEyesDL);
    }

    for (i = 0; i < EN_SLIME_BODYPART_MAX; i++) {
        Matrix_MultVec3f(&sBodyPartPosOffsets[i], &this->bodyPartsPos[i]);
    }

    if (this->actionFunc == EnSlime_Revive) {
        Matrix_Translate(this->actor.world.pos.x, this->actor.world.pos.y, this->actor.world.pos.z, MTXMODE_NEW);
        Matrix_RotateYS(this->reviveRotY, MTXMODE_APPLY);
        Matrix_Scale(this->reviveScale.x, this->reviveScale.y, this->reviveScale.z, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, gChuchuPuddleDL);
    }

    if ((this->actor.params != EN_SLIME_TYPE_BLUE) && (this->actor.scale.x > 0.0f)) {
        POLY_OPA_DISP = Play_SetFog(play, POLY_OPA_DISP);
        POLY_OPA_DISP = Gfx_SetupDL66(POLY_OPA_DISP);

        Matrix_Translate(this->actor.world.pos.x, this->actor.world.pos.y + (2000.0f * this->actor.scale.y),
                         this->actor.world.pos.z, MTXMODE_NEW);
        Matrix_Scale(0.03f, 0.03f, 0.03f, MTXMODE_APPLY);

        gSPSegment(POLY_OPA_DISP++, 0x08, this->itemDropTex);
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, gItemDropDL);
    }

    Actor_DrawDamageEffects(play, &this->actor, this->bodyPartsPos, EN_SLIME_BODYPART_MAX, this->drawDmgEffScale,
                            this->drawDmgEffFrozenSteamScale, this->drawDmgEffAlpha, this->drawDmgEffType);

    CLOSE_DISPS(play->state.gfxCtx);
}
