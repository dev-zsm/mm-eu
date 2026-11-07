// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_water_effect.h"

void ref_func_80A5A6B8(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnWaterEffect* this = (EnWaterEffect*)thisx;
    EnWaterEffectStruct* ptr = &this->unk_144[0];
    u8 phi_s4 = false;
    s16 i;

    OPEN_DISPS(play->state.gfxCtx);

    Matrix_Translate(this->actor.world.pos.x, this->actor.world.pos.y, this->actor.world.pos.z, MTXMODE_NEW);
    Matrix_RotateYS(this->actor.shape.rot.y, MTXMODE_APPLY);
    Matrix_Scale(this->actor.scale.x, this->actor.scale.y, this->actor.scale.z, MTXMODE_APPLY);
    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    gDPSetEnvColor(POLY_XLU_DISP++, 165, 235, 255, 128);

    Matrix_Push();
    Matrix_Push();
    Matrix_Push();

    if ((this->actor.params == ENWATEREFFECT_TYPE_GYORG_RIPPLES) ||
        (this->actor.params == ENWATEREFFECT_TYPE_GYORG_PRIMARY_SPRAY)) {
        if (this->unk_E2C > 1.0f) {
            Gfx_SetupDL25_Xlu(play->state.gfxCtx);
            AnimatedMat_Draw(play, Lib_SegmentedToVirtual(object_water_effect_Matanimheader_000DE0));
            Matrix_Scale(this->unk_DC8[1].y, this->unk_DC8[1].z, this->unk_DC8[1].y, MTXMODE_APPLY);

            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (u8)this->unk_E2C);
            gSPDisplayList(POLY_XLU_DISP++, object_water_effect_DL_000420);
        }

        Matrix_Pop();

        if (this->unk_E30 > 1.0f) {
            Gfx_SetupDL25_Xlu(play->state.gfxCtx);
            AnimatedMat_Draw(play, Lib_SegmentedToVirtual(object_water_effect_Matanimheader_000E0C));
            Matrix_Scale(this->unk_DC8[2].y, this->unk_DC8[2].z, this->unk_DC8[2].y, MTXMODE_APPLY);

            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (u8)this->unk_E30);
            gSPDisplayList(POLY_XLU_DISP++, object_water_effect_DL_000730);
        }
        Matrix_Pop();
    } else {
        Matrix_Pop();
        Matrix_Pop();
    }

    if ((this->unk_E34 > 1.0f) && (this->actor.params != ENWATEREFFECT_TYPE_GYORG_SHOCKWAVE)) {
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        AnimatedMat_Draw(play, Lib_SegmentedToVirtual(object_water_effect_Matanimheader_000E40));
        Matrix_Scale(this->unk_DC8[3].y, this->unk_DC8[3].z, this->unk_DC8[3].y, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (u8)this->unk_E34);
        gSPDisplayList(POLY_XLU_DISP++, object_water_effect_DL_000A48);
    }

    Matrix_Pop();

    if ((this->actor.params == ENWATEREFFECT_TYPE_GYORG_RIPPLES) ||
        (this->actor.params == ENWATEREFFECT_TYPE_GYORG_SHOCKWAVE)) {
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        AnimatedMat_Draw(play, Lib_SegmentedToVirtual(object_water_effect_Matanimheader_000E58));
        Matrix_Scale(this->unk_DC8[4].y, this->unk_DC8[4].z, this->unk_DC8[4].y, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (u8)this->unk_E38);
        gSPDisplayList(POLY_XLU_DISP++, object_water_effect_DL_000CD8);
    }

    if (this->actor.params == ENWATEREFFECT_TYPE_GYORG_RIPPLES) {
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);

        for (i = 0; i < ARRAY_COUNT(this->unk_144) / 2; i++, ptr++) {
            if (ptr->unk_00 == 3) {
                if (!phi_s4) {
                    Gfx_SetupDL44_Xlu(play->state.gfxCtx);

                    gSPSegment(POLY_XLU_DISP++, 0x08, Lib_SegmentedToVirtual(gEffDust1Tex));
                    gDPSetEnvColor(POLY_XLU_DISP++, 250, 250, 255, 0);
                    gSPDisplayList(POLY_XLU_DISP++, object_water_effect_DL_004260);
                    phi_s4++;
                }

                gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, (u8)ptr->unk_38, (u8)(((void)0, ptr->unk_38) + 55.0f), 225,
                                ptr->unk_3C);

                Matrix_Translate(ptr->unk_04.x, ptr->unk_04.y, ptr->unk_04.z, MTXMODE_NEW);
                Matrix_Scale(ptr->unk_2C.x, 1.0f, ptr->unk_2C.x, MTXMODE_APPLY);
                Matrix_RotateYF(ptr->unk_2C.z, MTXMODE_APPLY);

                MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
                gSPDisplayList(POLY_XLU_DISP++, object_water_effect_DL_0042F8);
            }
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
