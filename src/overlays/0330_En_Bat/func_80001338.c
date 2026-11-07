// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bat.h"

void EnBat_Draw(Actor* thisx, PlayState* play) {
    EnBat* this = (EnBat*)thisx;
    Gfx* gfx;

    
    if (this->actor.projectedPos.z > 0.0f) {
        OPEN_DISPS(play->state.gfxCtx);

        gfx = POLY_OPA_DISP;

        gSPDisplayList(&gfx[0], gSetupDLs[SETUPDL_25]);
        MATRIX_FINALIZE_AND_LOAD(&gfx[1], play->state.gfxCtx);
        gSPDisplayList(&gfx[2], gBadBatSetupDL);
        gSPDisplayList(&gfx[3], gBadBatBodyDL);
        gSPDisplayList(&gfx[4], sWingsDLs[this->animationFrame]);

        POLY_OPA_DISP = &gfx[5];

        CLOSE_DISPS(play->state.gfxCtx);
    }

    
    if (this->drawDmgEffAlpha > 0.0f) {
        s16 rollAngle;

        if (this->animationFrame < BAD_BAT_FLAP_FRAME - 1) {
            rollAngle = this->animationFrame * (15 * (0x10000 / 360));
        } else {
            rollAngle = (this->animationFrame >= BAD_BAT_FLAP_FRAME)
                            ? (this->animationFrame * (15 * (0x10000 / 360))) - (120 * (0x10000 / 360))
                            : 0;
        }
        Matrix_MultZero(&this->bodyPartsPos[BAD_BAT_BODYPART_0]);
        Matrix_RotateZS(rollAngle, MTXMODE_APPLY);
        Matrix_MultVecX(1700.0f, &this->bodyPartsPos[BAD_BAT_BODYPART_1]);
        Matrix_RotateZS(-2 * rollAngle, MTXMODE_APPLY);
        Matrix_MultVecX(-1700.0f, &this->bodyPartsPos[BAD_BAT_BODYPART_2]);
        Actor_DrawDamageEffects(play, &this->actor, this->bodyPartsPos, BAD_BAT_BODYPART_MAX, this->drawDmgEffScale,
                                this->drawDmgEffFrozenSteamScale, this->drawDmgEffAlpha, this->drawDmgEffType);
    }
}
