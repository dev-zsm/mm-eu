// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test.h"

s32 EnTest_OverrideLimbDraw(PlayState* play, KFSkelAnimeFlex* kfSkelAnime, s32 limbIndex, Gfx** dList, u8* flags,
                            void* thisx, Vec3f* scale, Vec3s* rot, Vec3f* pos) {
    EnTest* this = (EnTest*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    if ((this->actor.params == -1) && ((limbIndex == 1) || (limbIndex == 2))) {
        *dList = NULL;
    }

    if ((this->actor.params == -2) && (limbIndex == 3)) {
        *dList = NULL;
    }

    if (limbIndex == 3) {
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 0, 0, 0, ((20 - this->unk_209) * 255.0f) / 20.0f);
        gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, ((20 - this->unk_209) * 255.0f) / 20.0f);
    }

    CLOSE_DISPS(play->state.gfxCtx);

    return true;
}
