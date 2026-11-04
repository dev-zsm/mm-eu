// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/c_keyframe.h"

void Keyframe_DrawFlex(PlayState* play, KFSkelAnimeFlex* kfSkelAnime, Mtx* mtxStack,
                       OverrideKeyframeDrawScaled overrideKeyframeDraw, PostKeyframeDrawScaled postKeyframeDraw,
                       void* arg) {
    s32 limbIndex;

    if (mtxStack == NULL) {
        return;
    }

    OPEN_DISPS(play->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x0D, mtxStack);
    gSPSegment(POLY_XLU_DISP++, 0x0D, mtxStack);

    limbIndex = 0;
    Keyframe_DrawFlexLimb(play, kfSkelAnime, &limbIndex, overrideKeyframeDraw, postKeyframeDraw, arg, &mtxStack);

    CLOSE_DISPS(play->state.gfxCtx);
}
