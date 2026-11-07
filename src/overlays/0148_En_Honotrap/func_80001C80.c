// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_honotrap.h"

void EnHonotrap_DrawFlameGroup(Actor* thisx, PlayState* play) {
    s32 pad;
    EnHonotrap* this = (EnHonotrap*)thisx;
    EnHonotrapFlameElement* flameElem;
    EnHonotrapFlameGroup* flameGroup = &this->flameGroup;
    s32 i;
    s32 pad2;
    Vec3s camDir;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 200, 0, 255);
    gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 0, 0);
    camDir = Camera_GetCamDir(GET_ACTIVE_CAM(play));
    camDir.y += 0x8000;

    for (i = 0; i < ARRAY_COUNT(flameGroup->flameList); i++) {
        flameElem = &flameGroup->flameList[i];
        if (flameElem->isDrawn) {
            gSPSegment(POLY_XLU_DISP++, 0x08,
                       Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, 0, 32, 64, 1, 0, flameElem->flameScroll, 32, 128));
            Matrix_SetTranslateRotateYXZ(flameElem->pos.x, flameElem->pos.y - (4000.0f * flameElem->unkC),
                                         flameElem->pos.z, &camDir);
            Matrix_Scale(((fabsf(Math_SinS((s16)(camDir.y - thisx->shape.rot.y) >> 1)) * 0.2f) + 1.7f) *
                             flameElem->unkC,
                         flameElem->unkC, 1.0f, MTXMODE_APPLY);
            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
            gSPDisplayList(POLY_XLU_DISP++, gEffFire1DL);
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
