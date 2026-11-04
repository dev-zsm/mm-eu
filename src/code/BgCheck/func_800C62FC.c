// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

void BgCheck_CalcWaterboxDimensions(Vec3f* minPos, Vec3f* maxXPos, Vec3f* maxZPos, Vec3s* minPosOut, s16* xLength,
                                    s16* zLength) {
    f32 temp;

    minPosOut->x = minPos->x;
    minPosOut->y = minPos->y;
    minPosOut->z = minPos->z;

    if (maxXPos->x < minPosOut->x) {
        minPosOut->x = maxXPos->x;
    }
    if (maxXPos->y < minPosOut->y) {
        minPosOut->y = maxXPos->y;
    }
    if (maxXPos->z < minPosOut->z) {
        minPosOut->z = maxXPos->z;
    }

    if (maxZPos->x < minPosOut->x) {
        minPosOut->x = maxZPos->x;
    }
    if (maxZPos->y < minPosOut->y) {
        minPosOut->y = maxZPos->y;
    }
    if (maxZPos->z < minPosOut->z) {
        minPosOut->z = maxZPos->z;
    }

    *xLength = minPos->x - minPosOut->x;
    temp = maxXPos->x - minPosOut->x;

    if (*xLength < temp) {
        *xLength = temp;
    }
    temp = maxZPos->x - minPosOut->x;
    if (*xLength < temp) {
        *xLength = temp;
    }
    *zLength = minPos->z - minPosOut->z;

    temp = maxXPos->z - minPosOut->z;
    if (*zLength < temp) {
        *zLength = temp;
    }
    temp = maxZPos->z - minPosOut->z;
    if (*zLength < temp) {
        *zLength = temp;
    }
}
