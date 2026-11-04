// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

s32 CollisionCheck_SetAC_SAC(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* col, s32 index) {
    if (FrameAdvance_IsEnabled(play)) {
        return -1;
    }
    sACResetFuncs[col->shape](play, col);

    if ((col->actor != NULL) && (col->actor->update == NULL)) {
        return -1;
    }
    if (colChkCtx->sacFlags & SAC_ON) {
        if (index >= colChkCtx->colACCount) {
            return -1;
        }
        colChkCtx->colAC[index] = col;
    } else {
        if (colChkCtx->colACCount >= ARRAY_COUNT(colChkCtx->colAC)) {
            return -1;
        }
        index = colChkCtx->colACCount;
        colChkCtx->colAC[colChkCtx->colACCount++] = col;
    }
    return index;
}
