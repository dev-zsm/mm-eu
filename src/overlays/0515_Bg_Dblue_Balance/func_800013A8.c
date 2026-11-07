// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_balance.h"

void ref_func_80B83758(Actor* thisx, PlayState* play) {
    s32 pad;
    BgDblueBalance* this = (BgDblueBalance*)thisx;
    f32 temp_f0;
    Gfx* gfx;
    s32 i;
    BgDblueBalanceStruct* ptr;
    BgDblueBalanceTypeInfo* ptr2;
    s32 temp;

    if (this->unk_178 != 0) {
        if (this->unk_178 == 0x1F4) {
            temp_f0 = 1.0f;
        } else {
            temp_f0 = this->unk_178 * 0.002f;
            temp_f0 = CLAMP(temp_f0, 0.0f, 1.0f);
        }
        Audio_PlaySfx_AtPosWithFreqAndChannelIO(&this->dyna.actor.projectedPos, NA_SE_EV_SMALL_WATER_WHEEL - SFX_FLAG,
                                                temp_f0, 0x20);
    }

    if (this->dyna.actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) {
        ptr2 = &sTypeInfo[BGDBLUEBALANCE_GET_300(&this->dyna.actor)];
        Gfx_DrawDListOpa(play, ptr2->opaDList);

        if (this->unk_183 != 0) {
            AnimatedMat_Draw(play, ref_D_80B83C70);

            OPEN_DISPS(play->state.gfxCtx);

            gfx = POLY_XLU_DISP;

            gSPDisplayList(gfx++, gSetupDLs[SETUPDL_25]);

            for (i = 0, ptr = &this->unk_188[0]; i < ARRAY_COUNT(this->unk_188); i++, ptr++) {
                if (ptr->unk_0E != 0) {
                    Matrix_Translate(ptr->unk_00.x, ptr->unk_00.y, ptr->unk_00.z, MTXMODE_NEW);
                    Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_APPLY);
                    Matrix_RotateXS(ptr->unk_0C, MTXMODE_APPLY);
                    Matrix_Scale(ptr->unk_10, ptr->unk_10, ptr->unk_10, MTXMODE_APPLY);

                    temp = ptr->unk_0E * (f32)this->unk_183 * 0.003921569f;
                    gDPSetEnvColor(gfx++, 0, 0, 0, temp);
                    MATRIX_FINALIZE_AND_LOAD(gfx++, play->state.gfxCtx);
                    gSPDisplayList(gfx++, gGreatBayTempleObjectWaterwheelSplashDL);
                }
            }

            POLY_XLU_DISP = gfx;

            CLOSE_DISPS(play->state.gfxCtx);
        }
    }
}
