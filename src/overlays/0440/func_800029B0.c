// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

s32 EnTest7_OverrideLimbDraw(PlayState* play, KFSkelAnimeFlex* kfSkelAnime, s32 limbIndex, Gfx** dList, u8* flags,
                             void* thisx, Vec3f* scale, Vec3s* rot, Vec3f* pos) {
    EnTest7* this = (EnTest7*)thisx;
    Vec3f featherPos;

    if ((*dList != NULL) && (Rand_ZeroOne() < 0.03f)) {
        Matrix_MultVec3f(&gZeroVec3f, &featherPos);
        EnTest7_AddAndChooseFeather(this->feathers, &featherPos, false);
    }
    return true;
}
