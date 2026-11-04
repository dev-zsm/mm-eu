// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_OC(struct PlayState* play, CollisionCheckContext* colChkCtx) {
    Collider** leftColP;
    Collider** rightColP;
    ColChkVsFunc vsFunc;

    for (leftColP = colChkCtx->colOC; leftColP < colChkCtx->colOC + colChkCtx->colOCCount; leftColP++) {
        if ((*leftColP == NULL) || CollisionCheck_SkipOC(*leftColP)) {
            continue;
        }
        for (rightColP = leftColP + 1; rightColP < colChkCtx->colOC + colChkCtx->colOCCount; rightColP++) {
            if ((*rightColP == NULL) || CollisionCheck_SkipOC(*rightColP) ||
                CollisionCheck_Incompatible(*leftColP, *rightColP)) {
                continue;
            }
            vsFunc = sOCVsFuncs[(*leftColP)->shape][(*rightColP)->shape];
            if (vsFunc == NULL) {
                continue;
            }
            vsFunc(play, colChkCtx, *leftColP, *rightColP);
        }
    }
}
