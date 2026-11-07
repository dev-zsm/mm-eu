// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_movebg.h"

void BgDblueMovebg_Draw(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    BgDblueMovebg* this = (BgDblueMovebg*)thisx;
    s32 i;
    s32 j;
    Gfx* gfx;
    Gfx* gfx2;

    Matrix_Push();

    OPEN_DISPS(play->state.gfxCtx);

    if ((this->unk_160 == 9) || (this->unk_160 == 8) || (this->dyna.actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME)) {
        if (this->texAnim != NULL) {
            AnimatedMat_Draw(play, Lib_SegmentedToVirtual(this->texAnim));
        }

        if ((this->opaDList != NULL) || (this->unk_160 == 6)) {
            gfx2 = Gfx_SetupDL(POLY_OPA_DISP, SETUPDL_25);

            MATRIX_FINALIZE_AND_LOAD(&gfx2[0], play->state.gfxCtx);

            if (this->unk_160 == 6) {
                gSPDisplayList(&gfx2[1], gGreatBayTempleObjectGearShaftDL);
                if (this->opaDList != NULL) {
                    gSPDisplayList(&gfx2[2], this->opaDList);
                    POLY_OPA_DISP = &gfx2[3];
                } else {
                    POLY_OPA_DISP = &gfx2[2];
                }
            } else {
                gSPDisplayList(&gfx2[1], this->opaDList);
                POLY_OPA_DISP = &gfx2[2];
            }
        }

        if (this->xluDList != NULL) {
            gfx = Gfx_SetupDL71(POLY_XLU_DISP);

            MATRIX_FINALIZE_AND_LOAD(&gfx[0], play->state.gfxCtx);
            gSPDisplayList(&gfx[1], this->xluDList);

            POLY_XLU_DISP = &gfx[2];
        }
    }

    Matrix_Pop();

    CLOSE_DISPS(play->state.gfxCtx);

    if ((this->unk_160 == 8) && (this->unk_172 & 0x20)) {
        AnimatedMat_Draw(play, Lib_SegmentedToVirtual(gGreatBayTempleObjectWaterwheelSplashTexAnim));

        OPEN_DISPS(play->state.gfxCtx);

        Matrix_Translate(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y, this->dyna.actor.world.pos.z,
                         MTXMODE_NEW);
        Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_APPLY);
        Matrix_RotateXS(this->dyna.actor.shape.rot.x, MTXMODE_APPLY);
        Matrix_RotateZS(this->dyna.actor.shape.rot.z, MTXMODE_APPLY);
        gfx = Gfx_SetupDL71(POLY_XLU_DISP);

        for (i = 0; i < ARRAY_COUNT(this->unk_1D8[0]); i++) {
            for (j = 0; j < ARRAY_COUNT(this->unk_1D8); j++) {
                if (this->unk_1D8[j][i] > 0) {
                    if (this->unk_1F8[j][i] > 0.1f) {
                        gSPSegment(gfx++, 0x09,
                                   Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0,
                                                    (s32)(((play->gameplayFrames % 128) * -9.0f) / this->unk_1F8[j][i]),
                                                    0x20, 0x20, 1, 0, 0, 0x20, 0x20));
                    }
                    Matrix_Push();
                    Matrix_RotateXS(i * 0x2000, MTXMODE_APPLY);
                    Matrix_Translate(1785.0f, 0.0f, 270.0f, MTXMODE_APPLY);
                    if (j != 0) {
                        Matrix_RotateZS(-0x8000, MTXMODE_APPLY);
                    }
                    Matrix_Scale(this->unk_1F8[j][i] * this->dyna.actor.scale.x,
                                 this->unk_1F8[j][i] * this->dyna.actor.scale.y,
                                 this->unk_1F8[j][i] * this->dyna.actor.scale.z, MTXMODE_APPLY);

                    MATRIX_FINALIZE_AND_LOAD(gfx++, play->state.gfxCtx);
                    gDPSetEnvColor(gfx++, 255, 255, 255, this->unk_1D8[j][i]);
                    gSPDisplayList(gfx++, gGreatBayTempleObjectWaterwheelSplashDL);

                    Matrix_Pop();
                }
            }
        }
        POLY_XLU_DISP = gfx;

        CLOSE_DISPS(play->state.gfxCtx);
    }

    if ((this->unk_160 == 9) || (this->unk_160 == 8)) {
        if (this->unk_1CC >= 0) {
            Audio_PlaySfx_AtPosWithFreqAndChannelIO(&this->unk_1A8, NA_SE_EV_BIG_WATER_WHEEL_RR - SFX_FLAG,
                                                    this->unk_1D4, 32);
        } else {
            Audio_PlaySfx_AtPosWithFreqAndChannelIO(&this->unk_1A8, NA_SE_EV_BIG_WATER_WHEEL_LR - SFX_FLAG,
                                                    this->unk_1D4, 32);
        }
    }
}
