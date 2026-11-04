// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

s32 CollisionCheck_LineOC(struct PlayState* play, CollisionCheckContext* colChkCtx, Vec3f* a, Vec3f* b,
                          Actor** exclusions, s32 numExclusions) {
    ColChkLineFunc lineCheck;
    Collider** colP;
    s32 i;
    s32 exclude;
    s32 result = false;

    for (colP = colChkCtx->colOC; colP < &colChkCtx->colOC[colChkCtx->colOCCount]; colP++) {
        if (CollisionCheck_SkipOC(*colP)) {
            continue;
        }

        exclude = false;
        for (i = 0; i < numExclusions; i++) {
            if ((*colP)->actor == exclusions[i]) {
                exclude = 1;
                break;
            }
        }
        if (exclude) {
            continue;
        }

        lineCheck = sOCLineCheckFuncs[(*colP)->shape];
        if (lineCheck == NULL) {
            continue;
        }

        result = lineCheck(play, colChkCtx, *colP, a, b);
        if (result) {
            break;
        }
    }
    return result;
}
